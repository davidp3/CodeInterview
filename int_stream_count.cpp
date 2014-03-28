#include <stdio.h>

class BinTree {
	BinTree *left, *right;
	int data, dataCount;
	
	int getRankOfNumber(int n, int ancestorVal)	{
		if(data > n)	{
			if(!left)
				return -1;
			return left->getRankOfNumber(n, ancestorVal);
		}
		if(data < n)	{
			if(!right)
				return -1;
			return right->getRankOfNumber(n, dataCount + ancestorVal);
		}
		// assert (data == n);
		return ancestorVal + dataCount;
	}
	
public:
	BinTree(int n) : left(NULL), right(NULL), data(n), dataCount(1)	{}
	~BinTree()	{
		if(left)
			delete left;
		if(right)
			delete right;
	}
	
	void track(int n)	{
		if(n == data)	{
			++dataCount;
			return;
		}
		if(n < data)	{
			++dataCount;
			if(left)
				left->track(n);
			else
				left = new BinTree(n);
		} else {
			if(right)
				right->track(n);
			else
				right = new BinTree(n);
		}
	}
	
	int getRankOfNumber(int n)	{
		return getRankOfNumber(n, 0);
	}
};


int main()	{
	BinTree tree(1);
	tree.track(6);
	tree.track(5);
	tree.track(2);
	tree.track(3);
	tree.track(3);
	tree.track(4);
	tree.track(8);
	tree.track(7);	
	printf("3(4)=%d\n", tree.getRankOfNumber(3));
	printf("2(2)=%d\n", tree.getRankOfNumber(2));
	printf("7(8)=%d\n", tree.getRankOfNumber(7));
	printf("9(-1)=%d\n", tree.getRankOfNumber(9));
}



