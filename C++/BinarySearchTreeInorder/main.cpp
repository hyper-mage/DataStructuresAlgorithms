// Assignment 2
// Matthew Lynn
// IDE: CLion by Jet Brains
    // 1. Create Binary Search Tree followed by inorder traversal
    // 2. Delete the following nodes
        // a. Leaf Node followed by inorder traversal
        // b. Subtree Node followed by inorder traversal
    // 3. Profit
    //UPDATED: No array notation or pointers to the parent node
        //Perhaps this is due to unneeded pointers in array
        //and a pointer to the parent is redundant on a stack
    //Algorithm inOrder(v)
        //if ( v == null ) {return}
        //inOrder(v.left)
            //visit(v)
        //inOrder(v.right)
#include <iostream>
using namespace std;

// make the bst nodes for left and right child
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

//Now we want to make the nodes in the tree and orgainze the tree as a BST
//First up is the make node function
struct Node* makeNode(int val) {
    struct Node* loc = (struct Node*)malloc(sizeof(struct Node));
    loc->data = val;
    loc->left = loc->right = NULL; // set both childrn to null
    return loc;
}
//Next up is slapping (inserting) the nodes into place in a BST structure
struct Node* slapNode(struct Node* Node, int val){
    if (Node == NULL) return makeNode(val); //base case for nothing there
    else if (val < Node->data) //if the node be smol, go left
        Node->left = slapNode(Node->left, val);
    else //(val >= Node.data ... if the node be hoog, go right
        Node->right = slapNode(Node->right, val);
    return Node;
}

//Now we want to put our order funcitons here
//Since we are only doing inorder, we have just one
void inorder(struct Node* node) {
    if (node != NULL) {
        inorder(node->left); //recurse all down the left side
        cout << node->data << " "; //print.  Note we started at root
        inorder(node->right); //recurse all down the right side
    }
}

//finally our last few programs to consider are to delete leaf and subtree nodes
//to accomplish this we need to identify what nodes are leaves!
//with identify leaf and root we can imply subtree nodes
//we use delete and specify using the above as conditions
void identifyLeaf(Node* node) {
    if (!node) return;// if node is null, return none
    if (!node->left && !node->right) // print the leaf
    {
        cout << node->data << " ";
        return;
    }
    if (node->left) // recursively check left child and its leaves
        identifyLeaf(node->left);
    if (node->right) // recursively check right child and its leaves
        identifyLeaf(node->right);
}
// this next function simply find the max value of the left side of current node
// alternatively a successor function can be used as well
struct Node* predecessor(struct Node* node)
{
    struct Node* current = node;
    // loop down to find the right most leaf
    while (current->right != NULL)
        current = current->right;
    return current;
}
// since we have a bst, we can delete as follows
struct Node* removeNode(struct Node* node, int data)
{
    if (!node) return node; //basecase
    else if (data < node->data) // go down left side of tree, no need for right side
        node->left = removeNode(node->left, data);
    else if (data > node->data) // go down right side or tree, no need for left
        node->right = removeNode(node->right, data);
    else // case when node is the one we want to remove
    {
        // only one or no child
        if (node->left == NULL)
        {
            struct Node *tmp = node->right;
            free(node); //The free() function in C++ deallocates a block of memory, does not clear the pointer
            return tmp;
        }
        else if (node->right == NULL)
        {
            struct Node *tmp = node->left;
            free(node);
            return tmp;
        }
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        // two children => use predecessor function (that is max of left side)
        struct Node* tmp = predecessor(node->right);

        node->data = tmp->data; // Copy the predecssor to this loc_var node

        node->right = removeNode(node->right, tmp->data); // remove the predessor (since it got moved)
    }
    return node;
}

int main() {
    //1. make BST and do inorder traversal
    struct Node* node = NULL;
    //Slap the nodes into place below
    //Grader please input here
    node = slapNode(node, 16); // this is the root
    slapNode(node, 1);
    slapNode(node, 15);
    slapNode(node, 2);
    slapNode(node, 14);
    slapNode(node, 13);
    slapNode(node, 3);
    slapNode(node, 12);
    slapNode(node, 4);
    slapNode(node, 11);
    slapNode(node, 5);
    slapNode(node, 10);
    slapNode(node, 6);
    slapNode(node, 99);
    slapNode(node, 100);
    slapNode(node, 7);
    // 7 and 100 are my leaves i did by hand, identifyLeaf will show any leaves without doing by hand

    cout << "\nInorder always sorts in ascending order, assuming bst structure\n";
    cout << "This is the bst inorder, first part\n";
    inorder(node);

    //2. Delete leaf node and do inorder traversal
    cout << "\n\nBelow are the leaves\n";
    identifyLeaf(node);
    // Grader use identifyLeaf to easily pick a leaf to delete
    removeNode(node, 7);
    cout << "\nThis is the bst inorder with a leaf removed\n";
    inorder(node);

    //3. Delete subtree node and do inorder traversal
    cout << "\n\nBelow are the new leaves\n";
    identifyLeaf(node);
    // Grader simply pick a node that is not the root or the leaves
    removeNode(node, 4);
    cout << "\nThis the bst inorder with a subtree removed\n";
    inorder(node);
    cout << "\nWe verify that our leaves are the same\n";
    identifyLeaf(node);

}