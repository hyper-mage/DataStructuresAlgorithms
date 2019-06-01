#include <stdio.h>
#include <stdlib.h>

/* Link list node */
struct Node {
	int data;
	struct Node* next;
};

/* Given a reference (pointer to pointer) to
the head of a list and an int, push a new
node on the front of the list. */
void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

/* function to swap data of two nodes a and b*/
void swap(struct Node *a, struct Node *b)
{
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}

/*Print the list*/
void print(struct Node *node)
{
	if (!node) return;

	printf("[%p] [%d]\n", node, node->data);
	print(node->next);
}

void findSmallestNode(struct Node *node, struct Node **SNode)
{
	if (!node) return;

	//update the smallest node by comparing each element
	if (((*SNode)->data) > (node->data))
		*SNode = node;

	//traverse till end 
	findSmallestNode(node->next, SNode);
}

void selectionSort(struct Node *node, struct Node **sNode)
{
	if (!node) return;

	//find smallest node
	findSmallestNode(node, sNode);
	//swap head with smallest node
	swap(node, *sNode);

	//pass the next node 
	selectionSort(node->next, sNode);
}

int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;

	/* Use push() to construct below list
	25->30->50->15->20->10 */
	push(&head, 10);
	push(&head, 20);
	push(&head, 15);
	push(&head, 50);
	push(&head, 30);
	push(&head, 25);

	struct Node **sNode = (struct Node **)malloc(sizeof(struct Node *));
	*sNode = head;

	printf("Before Sort: \n");
	print(head);
	printf("\n");

	//sort the data
	selectionSort(head, sNode);

	printf("After Sort: \n");
	print(head);
	printf("\n");

	return 0;