#include <stdio.h>

class Node {
	Node *next;
	int data;
	
public:
	Node(int mydata, Node *nextNode) : data(mydata), next(nextNode)	{}
	~Node()	{
		if(next)
			delete next;
	}
	void print()	{
		printf("%d\t", data);
		if(next)
			next->print();
	}
	Node *partition(int val)	{
		Node *part1 = NULL, *part2 = NULL;
		Node *it = this;
		while(it)	{
			Node *itNext = it->next;
			if(it->data < val)	{
				it->next = part1;
				part1 = it;
			} else {
				it->next = part2;
				part2 = it;
			}
			it = itNext;
		}
		if(!part1)
			return part2;
		it = part1;
		while(it->next)
			it = it->next;
		it->next = part2;
		return part1;
	}
};

int main()	{
	Node *head = new Node(1, new Node(2, new Node(3, new Node(1, new Node(4, NULL)))));
	head->print();
	printf("\n");
	head = head->partition(2);
	head->print();
	printf("\n");
	delete head;
}




