#include <stdio.h>
#include <limits.h>
#include <stack>

class Queue	{
	std::stack<int> stackOld, stackNew;
	int popTop(std::stack<int> &tstack)	{
		int ret = tstack.top();
		tstack.pop();
		return ret;
	}
	
public:
	static const int ERROR = INT_MIN;
	
	void push(int val)	{
		stackNew.push(val);
	}
	int pop()	{
		if(!stackOld.empty())
			return popTop(stackOld);
		while(!stackNew.empty())
			stackOld.push(popTop(stackNew));
		if(!stackOld.empty())
			return popTop(stackOld);
		return ERROR;
	}
	bool empty()	{	return stackOld.empty() && stackNew.empty();	}
};


int main()	{
	Queue myQueue;
	myQueue.push(1);
	myQueue.push(2);
	int val = myQueue.pop();
	printf("1 = %d\n", val);
	myQueue.push(3);
	val = myQueue.pop();
	printf("2 = %d\n", val);
	val = myQueue.pop();
	printf("3 = %d\n", val);
	val = myQueue.pop();
	printf("INT_MIN = %d\n", val);
}
