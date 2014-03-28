#include <stdio.h>

struct Node {
	Node *L, *R;
	int data;
	Node(int d) : data(d), L(NULL), R(NULL)	{}
};

Node *toLL(Node *node, Node *L, Node *R)	{
	Node *ret = node;
	printf("%d\n", node->data);
	if(node->L)	{
		ret = toLL(node->L, L, node);
	} else {
		node->L = L;
		if(L)
			L->R = node;
	}
	if(node->R)	{
		toLL(node->R, node, R);
	} else {
		node->R = R;
		if(R)
			R->L = node;
	}
	return ret;
}

Node *toLL(Node *root)	{
	if(root == NULL)
		return NULL;
	return toLL(root, NULL, NULL);
}

void printLL(Node *n)	{
	if(n)	{
		printf("n: %d\tleft: %d\tright: %d\n", n->data, n->L ? n->L->data : -1, n->R ? n->R->data : -1);
		printLL(n->R);
	}
}

int main()	{
	Node one(1), two(2), three(3), four(4), five(5), six(6), seven(7), eight(8), nine(9);
	seven.L = &three;
	seven.R = &nine;
	three.L = &one;
	three.R = &six;
	nine.L = &eight;
	one.R = &two;
	six.L = &four;
	four.R = &five;
	
	Node *ret = toLL(&seven);
	printf("hi\n");
	printLL(ret);
}

