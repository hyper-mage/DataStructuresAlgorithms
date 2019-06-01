// Assignment 5
// Matthew Lynn
// IDE: CLion by Jet Brains
    //Write program to do Topological sort (DFS).
    //your graph must have at lease 10 nodes and 15 edges.
    // It must have multiple edges going in and also coming out from some of the edges.
        //1. Run the program on a graph with no cycles.
            // Your print out would show all the edges of the graph.
            // Then it will show the list of vertices in the topological order.
        //2. Run the program on a graph that has a cycle.
            // Your program catches the cycle and print the list of edges that form the cycle.
    //Submit code and screen shots of the execution.
#include <vector>
#include <iostream>
#include <list>
#include <queue>
#include <limits.h>
#include <string>
#include <stack>
using namespace std;
// define a node for use in SLL
//struct node
//{
//    int data;
//    node *next;
//};
//class list
//{
//    private:
//            node *head, *tail, *flag, *cycle;
//    public:
//        list()
//        {
//            head=NULL;
//            tail=NULL;
//            flag=0;
//            cycle=0;
//        }
//};

class Graph
{
    // # of vertices
    int V;
    // pointer to adj list
    list<int> *adj;
    void tsDFSu(int v, bool visited[], bool marked[], stack<int> &Stack);
public:
    explicit Graph(int V);
    void addEdge(int v, int w);
    void tsDFS();
    void printGraph();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    // w goes to list v
    adj[v].push_back(w);
}

// A recursive utility function for tsDFS
void Graph::tsDFSu(int v, bool visited[], bool marked[], stack<int> &Stack) {
//    if (marked[v]) {
//        visited[v] = false;
//        marked[v] = false;
//    }
    // if already visited, mark for cycle
    if (visited[v])
        marked[v] = true;
    // flag as visited
    visited[v] = true;
    // Recurse through all neighbor nodes
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i){
        if (!visited[*i])
            tsDFSu(*i, visited, marked, Stack);
    }
    // push node on stack
    Stack.push(v);
}

// A utility function to print the adjacency list
// we'll use this to display edges
void Graph::printGraph()
{
        for (int v = 0; v<V; ++v)
    {
        cout << v;
        for (auto x : adj[v])
            cout << " -> " << x;
        printf("\n");
    }
}

// Topo Sort
void Graph::tsDFS()
{
    // Our vector needs to start with 0 inDegrees
    vector<int> inDegree(V, 0);
    // Traverse adjacency lists to fill inDegrees of nodes
    for (int i=0; i<V; i++)
    {
        list<int>::iterator itr;
        for (itr = adj[i].begin(); itr != adj[i].end(); itr++)
            inDegree[*itr]++;
    }
    // Queue up all inDegree 0's
    queue<int> que;
    for (int i = 0; i < V; i++)
        if (inDegree[i] == 0)
            que.push(i);
    int visits = 0;
    // this is another way to top sort, but here it is used for counting
    // this would be the vector that gives the sorted
    vector <int> pez;
    // pop, push, and decrement til 0
    while (!que.empty())
    {
        // pop the queue and push the sorted
        int u = que.front();
        que.pop();
        pez.push_back(u);
        // traverse nearby vertices and decrement inDegree
        list<int>::iterator j;
        for (j = adj[u].begin(); j != adj[u].end(); j++)
            // If in-degree becomes zero, add it to queue
            if (--inDegree[*j] == 0)
                que.push(*j);
        visits++;
    }

    // Check for cycle
    if (visits != V)
    {
        cout << "We got cycler! Check adj list for loops.\n";
    }
    else {
            stack<int> Stack;
            // set nodes as not visited
            bool *visited = new bool[V];
            auto marked = new bool[V];
            for (int i = 0; i < V + 1; i++){
                visited[i] = false;
                marked[i] = false;
            }
            // go to each node and start a sortin'
//    list<int>::iterator i;
//    for (i = adj[V].begin(); i != adj[V].end(); ++i)
            for (int i = 0; i < V; i++){

//        if (visited[*i] && !marked[*i])
//            tsDFSu(*i, visited, marked, Stack);
                if (!visited[i])
                    tsDFSu(i, visited, marked, Stack);
            }
//    for (i = adj[V].begin(); i != adj[V].end(); ++i)
//    for (int i = 0; i < V; i++){
//        if (marked[i])
//            cout << "\nCycle detected at " << i << " to " << i+1;
//    }
            // Print contents of stack
            while (!Stack.empty())
            {
                cout << Stack.top() << " ";
                Stack.pop(); // pop!
            }
        }

}

int main()
{
    // grader, input thingies here
    Graph acyclic(11);
    acyclic.addEdge(0, 4);
    acyclic.addEdge(0, 5);
    acyclic.addEdge(1, 5);
    acyclic.addEdge(1, 6);
    acyclic.addEdge(2, 1);
    acyclic.addEdge(2, 6);
    acyclic.addEdge(3, 2);
    acyclic.addEdge(3, 7);
    acyclic.addEdge(4, 5);
    acyclic.addEdge(4, 8);
    acyclic.addEdge(5, 6);
    acyclic.addEdge(5, 8);
    acyclic.addEdge(7, 9);
    acyclic.addEdge(9, 10);
    acyclic.addEdge(10, 8);
    cout << "For each vertex below, '->' denotes one edge from head vertex\n";
    cout << "to vertex in head's list\n";
    cout << "Edges of the acyclic graph shown using adj list:\n";
    acyclic.printGraph();
    cout << "DFS Topological Sort of vertices in acyclic graph:\n";
    acyclic.tsDFS();

    Graph cyclic(11);
    cyclic.addEdge(4, 0);
    cyclic.addEdge(0, 5);
    cyclic.addEdge(1, 5);
    cyclic.addEdge(1, 6);
    cyclic.addEdge(2, 1);
    cyclic.addEdge(2, 6);
    cyclic.addEdge(3, 2);
    cyclic.addEdge(3, 7);
    cyclic.addEdge(4, 5);
    cyclic.addEdge(8, 4);
    cyclic.addEdge(5, 6);
    cyclic.addEdge(5, 8);
    cyclic.addEdge(7, 9);
    cyclic.addEdge(9, 10);
    cyclic.addEdge(10, 8);
    cout << "\n\n\nEdges of the cyclic graph shown using adj list:\n";
    cyclic.printGraph();
    cout << "DFS Topological Sort of vertices in cyclic graph:\n";
    cyclic.tsDFS();

    return 0;
}