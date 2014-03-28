#include <stdio.h>

class Node {
	int data;
	Node *next;
public:
	int getData()	{	return data;	}
	Node(int mydata, Node *nextNode) : data(mydata), next(nextNode)	{}
	~Node()	{
		if(next)	
			delete next;
	}
	
	Node *fromLastElt(unsigned int K)	{
		Node *kNode1 = this;
		for(unsigned int i=0; i<K; ++i)	{
			kNode1 = kNode1->next;
			if(!kNode1)
				return NULL;
		}
		Node *kNode2 = this;
		while(kNode1->next)	{
			kNode1 = kNode1->next;
			kNode2 = kNode2->next;
		}
		return kNode2;
	}
	
	void print()	{
		printf("%d  ", data);
		if(next)
			next->print();
	}
};


int main()	{
//	static const unsigned int K=3;
	static const unsigned int K=1;
	
	Node *head = new Node(1, new Node(2, new Node(3, new Node(4, NULL))));
//	Node *head = new Node(1, new Node(2, NULL));
	head->print();
	printf("\n");
	Node *kTL = head->fromLastElt(K);
	if(kTL)
		printf("%d\n", kTL->getData());
	else
		printf("Not found\n");
	delete head;
}

