#include <cstdlib>
#include <algorithm>

class BinTree	{
	BinTree *left, *right;
	
	struct Helper	{
		bool isBalanced;
		int depth;
		Helper(bool _is, int _depth) : isBalanced(_is), depth(_depth)	{}
		Helper()	{}
	};
	
	Helper isBalancedH()	{
		Helper helperL = left ? left->isBalancedH() : Helper(true, 0),
			helperR = right ? right->isBalancedH() : Helper(true, 0);
		return Helper(helperL.isBalanced && helperR.isBalanced &&
						std::abs(helperL.depth-helperR.depth) <= 1,
					std::max(helperL.depth, helperR.depth) + 1);
	}

public:
	BinTree(BinTree *_left, BinTree *_right) : left(_left), right(_right)	{}
	~BinTree()	{
		if(left) delete left;
		if(right) delete right;
	}
	
	bool isBalanced()	{	return isBalancedH().isBalanced;	}
};


int main()	{
//	BinTree myTree(new BinTree(new BinTree(NULL, NULL), NULL), NULL);	// FALSE
	BinTree myTree(new BinTree(new BinTree(NULL, NULL), NULL), new BinTree(NULL, NULL));	// TRUE
	if(myTree.isBalanced())
		printf("TRUE\n");
	else
		printf("FALSE\n");
}


