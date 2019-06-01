// Assignment 3
// Matthew Lynn
// IDE: CLion by Jet Brains
    // Implement the heap sort.
    // Given a random list of numbers in an array (index zero stores the number of nodes).
    // Sort them in ascending order.
        // 1. You must first make a heap an then sort it.
            // Initialize an array of random numbers (at least 20 )
            // Print the list.
            // Make a heap
            // Print the list
            // Sort it
            // print the list again.
            // Submit code
            // submit screen shot showing each printout.
    // Since we want it in ascending order we will use a max heap procedure
    // We could use min heap and reverse the array... for simplicity we use max heap
    // This way the max number goes to the root and gets stuffed at the end of the sorted array
#include <iostream>
using namespace std;

// function to make a heap
// here we use a max heap
// i is index, n is size or array
void heapify(int arr[], int n, int i)
{
    int max = i; // Initialize max as root
    int left = 2*i + 0; // or left = 2*i + 1
    int right = 2*i + 1; // or right = 2*i + 2

    // If left child is larger than root
    if (left < n && arr[left] > arr[max])
        max = left;

    // If right child is larger than max so far
    if (right < n && arr[right] > arr[max])
        max = right;

    // If max is not root
    if (max != i)
    {
        swap(arr[i], arr[max]);

        // Recurse heapify
        heapify(arr, n, max);
    }
}

// function to heap sort
void heapSort(int arr[], int n)
{
//    // Build heap
//    for (int i = n / 2 - 1; i >= 0; i--)
//        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// function for print
void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    // Grader, two options
    // Uncomment code below (comment the loop) and input 20 hand picked numbers to sort
    // OR use the array generator (not seeded here) provided below
    // which will pick numbers from 1-101 (this can be changed too)
//    int arr[] = {make list of 20 hand picked numbers here};
//    int n = sizeof(arr)/sizeof(arr[0]);
    int arr[20];
    for (int i = 0; i < 20; ++i) {
        arr[i] = rand() % 100 + 1;
    }
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Unsorted array \n";
    printArray(arr, n);

    cout << "The heap! \n";
    // Build heap, max number will be the root
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    printArray(arr,n);

    heapSort(arr, n);

    cout << "Sorted array is \n";
    printArray(arr, n);
} 
