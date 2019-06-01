// Assignment 1
// Matthew Lynn
// IDE: CLion by Jet Brains
    // 1. Traverse list
    // 2. Selection sort the list, changing node links but not node data
    // 3. Traverse again
    // 4. Profit
// Disclaimer: Much of the skeleton of this code was from:
    // https://www.geeksforgeeks.org/recursive-selection-sort-singly-linked-list-swapping-node-links/
    // Changes were made to fit the format of the homework and utilize both recursion and while looping
#include <iostream>
using namespace std;

// make the link list node
struct Node {
    int data;
    struct Node* next;
};

// function to swap nodes 'x' and 'y' in a
// linked list without swapping data
// head_ref is a pointer to a pointer to a Node
void swapNodes(struct Node** head_ref, struct Node* x,
               struct Node* y, struct Node* oldY)
{
    // make 'y' as new head
    // effectively we store the current min value to the address of our current head value
    *head_ref = y;

    // adjust links
    // set oldMin.next the value of current head
    oldY->next = x;

    // Swap next pointers
    struct Node* temp = y->next; // temp is a temporary placeholder for the "value" of min.next
    y->next = x->next; // replace the "value" of min.next with head.next
    x->next = temp; // head.next takes the "value" from min.next from temp
}

// function to sort the linked list using 
// recursive selection sort technique 
struct Node* recurSelectionSort(struct Node* head)
{
    // base case for one node
    // note that the base case for head == NULL is covered in sort and print/trav functions
    if (head->next == NULL) {return head;}

    // 'min' - pointer to store the node having minimum data value
    // kinda like setting a variable to 0 in a sense
    struct Node* min = head;

    // 'oldMin' - pointer to store node previous to 'min' node
    struct Node* oldMin = NULL;
    // ptr is just a temp variable for this function
    struct Node* ptr;

    // traverse the list till the last node
    for (ptr = head; ptr->next != NULL; ptr = ptr->next) {

        // if true, then update 'min' and 'oldMin'
        // if node.next, in the traversal, is less than our current min value
        // we replace the current min value and store the oldMin value
        // into the current node in the traversal
        if (ptr->next->data < min->data) {
            min = ptr->next;
            oldMin = ptr;
        }
    }

    // if 'min' and 'head' are not same,
    // swap the head node with the 'min' node
    if (min != head)
        swapNodes(&head, head, min, oldMin);

    // recursively sort the remaining list
    head->next = recurSelectionSort(head->next);

    // the recursion should stack like this
    // head, head.next, head.next.next, etc
    // or can be seen like this
    // min, next min, etc, max
    return head;
}

// sorts, begins the sorting process using &head, the address of head
void sort(struct Node** head_ref)
{
    // base case if head is NULL
    if (*head_ref == NULL) { return;}

    // sort via recursive selection sort
    *head_ref = recurSelectionSort(*head_ref);
}

// inserts a node at the front of the SLL, LIFO
void push(struct Node** head_ref, int new_data)
{
    // allocate node
    struct Node* new_node =
            (struct Node*)malloc(sizeof(struct Node));

    // put in the data
    new_node->data = new_data;

    // link the old list to the new node
    new_node->next = *head_ref;

    // move the head to point to the new node
    *head_ref = new_node;
}

// function to print the linked list 
void printList(struct Node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

// recursive version of printList
void trav(struct Node* head)
{
    if (head == NULL) { return;}
    cout << head->data << " ";
    trav(head->next);
}

// Driver program to test above 
int main()
{
    struct Node* head = NULL;

    // create linked list
    // Grader, please input values to be tested here
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 12);
    push(&head, 11);
    push(&head, 10);
    push(&head, 15);
    push(&head, 14);
    push(&head, 13);
    push(&head, 40);
    push(&head, 50);
    push(&head, 0);
    push(&head, 100);
    push(&head, 99);

    cout << "Linked list before sorting\n";
    printList(head);
    cout << "\nVia recursive traversal\n";
    trav(head);

    // sort the linked list
    sort(&head);

    cout << "\n\nLinked list after sorting\n";
    printList(head);
    cout << "\nVia recursive traversal (sorted)\n";
    trav(head);

    return 0;
} 
