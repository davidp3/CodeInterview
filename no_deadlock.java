
class MyLock {
	private LockManager lockManager;
	private Lock lock = new Lock();
	
	public MyLock(LockManager lockManager) {
		this.lockManager = lockManager;
	}
	public void lock() throws Exception	{
		Thread thread = getThisThread();
		lockManager.lock(lock, thread);
	}
	public void unlock()	{
		Thread thread = getThisThread();
		lockManager.unlock(lock, thread);
	}
}

class LockManager {
	synchronized HashMap<Lock, Thread> lockToThread;
	synchronized HashMap<Thread, Lock> threadToWaitingLock;

	private synchronized boolean wouldDeadlock(Lock lock, Thread thread)	{
		// If lock unused then allow the lock.
		if(!lockToThread.hasKey(lock))
			return false;
			
		// Lock is used so check for deadlock.
		Thread initThread = thread;
		// This must end because it cannot contain cycles since that is what we are detecting and
		// forbidding here in the first place.
		while(true)	{
			thread = lockToThread.get(lock);
			if(thread.equals(initThread))
				return true;		// we looped lock-dependencies so deadlock
			if(!threadToWaitingLock.hasKey(thread))
				return false;		// this breaks the lock-list so no deadlock
			lock = threadToWaitingLock.get(thread);
		}
		assert false;	// impossible
		return true;
	}
	
	private void allowLock(Lock lock, Thread thread)	{
		lockToThread.put(lock, thread);
		threadToWaitingLock.put(thread, lock);
	}
	
	public void lock(Lock lock, Thread thread) throws Exception	{
		synchronized(this)	{
			if(wouldDeadlock(lock, thread))
				throw new Exception("Deadlock");
			allowLock(lock, thread);
		}
		lock.lock();
		threadToWaitingLock.remove(thread);	// synchronized(this) may be better than synchronized treadToWaitingLock...?
	}
	
	public void unlock(Lock lock, Thread thread)	{
		lock.unlock();
		lockToThread.remove(lock);
	}
}
