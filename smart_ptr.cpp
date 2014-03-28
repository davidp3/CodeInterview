#include <stdio.h>
#include <iostream>

using std::cout;

template <typename T>
class Smart	{
	T *obj;
	int *pCount;
	void decrement()	{
		--(*pCount);
		if(*pCount == 0)	{
			cout << "Deleting: " << *obj << "\n";
			delete obj;
			delete pCount;
			obj=NULL;
			pCount=NULL;
		}
	}
	
public:
	Smart(T *_obj) : obj(_obj), pCount(new int(1))	{}
	~Smart()	{
		decrement();
	}
	
	Smart<T> operator=(const Smart<T> &o)	{
		decrement();
		obj = o.obj;
		pCount = o.pCount;
		++(*pCount);
		return *this;
	}
	
	Smart(const Smart<T> &o)	{
		obj = o.obj;
		pCount = o.pCount;
		++(*pCount);
	}
	
	void print()	{
		cout << "Item: " << *obj << "\n";
	}
};

Smart<int> getPtr()	{
	return Smart<int>(new int(3));
}

int main()	{
	Smart<int> ptr = getPtr();
	ptr.print();
	ptr = Smart<int>(new int(0));
	ptr.print();
}


