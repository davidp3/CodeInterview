#include <stdio.h>
#include <string>
#include <map>
#include <set>

using std::map;
using std::set;

class Node {
	int data;
	Node *next;
	
public:
	void print()	{
		printf("%d  ", data);
		if(next)
			next->print();
	}
	
	void removeDups()	{
		set<int> elts;
		Node *cur = this->next;
		Node *prev = this;
		elts.insert(data);
		while(cur)	{
			if(elts.find(cur->data) != elts.end())	{
				prev->next = cur->next;
				cur->next = NULL;
				delete cur;
			}
			else	{
				elts.insert(cur->data);
				prev = cur;
			}
			cur = prev->next;
		}
	}
	
	Node(int myData, Node *nextNode) : data(myData), next(nextNode)	{
	}
	
	~Node()	{
		if(next)	{
			delete next;
		}
	}
};

int main()	{
	Node *head = new Node(1, new Node(2, new Node(2, new Node(3, NULL))));
	head->print();
	printf("\n");
	head->removeDups();
	head->print();
	printf("\n");
	delete head;
}


