// Assignment 4
// Matthew Lynn
// IDE: CLion by Jet Brains
    // 1. make a graph. you can use any representation. The graph must have at least 10 nodes and 15 edges. undirected graph.
    // 2. run Dijkstra's algorithm.
    //  submit screen shot and the code.
// I tried to use the priority queue from c++ stl, but did not understand it enough
// Below is a version from geeksforgeeks, may resubmit if I can get the priority queue one to work
// constructing priority queues
#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <vector>         // std::vector
#include <functional>     // std::greater
#include <stdio.h>
#include <limits.h>

// 10 vertices
#define V 10

// function to find the least weighted vertices iteratively
int minDist(int dist[], bool sptSet[])
{
    // here we set the current values to int max (inf)
    // then as we go through the graph, we update the values
    int min = INT_MAX, min_index = 0;

    // simply if dist at ith vertex is less than the current min
    // we update the min value, and its index
    for (int i = 0; i < V; i++)
        if (!sptSet[i] && dist[i] <= min)
            min = dist[i], min_index = i;

    return min_index;
}

// print out each vertex and its distance from the origin
int printDistances(int dist[], int n)
{
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < n; i++)
        printf("%d \t\t %d\n", i, dist[i]);
    return 0;

}

void dijkstra(int graph[V][V], int source)
{
    // dist[v] will contain the shortest path from origin to v and vice versa
    int dist[V];

    // this will return true if v is included in the minimal path
    bool sptSet[V];

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[source] = 0;

    // Find shortest path for all vertices
    for (int i = 0; i < V-1; i++)
    {
                // set min dist values for vertices not visited.
        int u = minDist(dist, sptSet);

        // set sptSet to true once visited
        sptSet[u] = true;

        // Update dist values of neighbor vertices of the visited vertex.
        for (int v = 0; v < V; v++)

            // ifelse to update dist[v] if:
                // 1. it is not in our sptSet
                // 2. an edge from u <-> v remains
                // 3. weight of path from source point to v that contains u < current dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u]+graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printDistances(dist, V);
}

int main()
{
// A picture of the graph using the adjacency matrix below is provided
// I do not know an easy way to type this in for the grader :(
// But if you have an adjacency matrix to put it, you can just slap it here.
    int graph[V][V] = {{0, 120, 150, 0, 140, 0, 130, 0, 110, 0},
                       {120, 0, 0, 60, 0, 0, 0, 0, 1, 0},
                       {150, 0, 0, 20, 0, 100, 0, 0, 0, 0},
                       {0, 60, 20, 0, 80, 0, 0, 0, 0, 40},
                       {140, 0, 0, 80, 0, 5, 0, 70, 0, 0},
                       {0, 0, 100, 0, 5, 0, 90, 0, 0, 15},
                       {130, 0, 0, 0, 0, 90, 0, 10, 0, 0},
                       {0, 0, 0, 0, 70, 0, 10, 0, 50, 30},
                       {110, 1, 0, 0, 0, 0, 0, 50, 0, 0},
                       {0, 0, 0, 40, 0, 15, 0, 30, 0, 0}
    };

    // we pick the 0 point vertex as our source, but it can start anywhere
    dijkstra(graph, 0);

    return 0;
}
