// SLLsort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

/* structure for a node */
struct Node
{
	int data;
	struct Node *next; //next is a pointer to a node
};

//pauses screen, even while debugging
void pause()
{
	cout << "Please press a key to continue\n";
	return;
}

/* print nodes in the SLL */
void printL(struct Node *start)
{
	struct Node *temp = start;
	printf("\n");
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}
void printList(struct Node *n)
{
	while (n != NULL)
	{
		printf(" %d ", n->data);
		n = n->next;
	}
}

int main()
{
	/* type data in here */
	int arr[] = { 12, 56, 2, 11, 1, 90 };
	int list_size, i;

	/* start with empty linked list */
	struct Node *start = NULL;


	return 0;

	pause();
}

