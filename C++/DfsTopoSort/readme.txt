The purpose of this assingment is to topologically sort a graph via DFS. We make use of DFS to determine if our graph is acyclic or
includes a cycle. We further can determine where this cycle forms.
	    //Write program to do Topological sort (DFS).
    //your graph must have at lease 10 nodes and 15 edges.
    // It must have multiple edges going in and also coming out from some of the edges.
        //1. Run the program on a graph with no cycles.
            // Your print out would show all the edges of the graph.
            // Then it will show the list of vertices in the topological order.
        //2. Run the program on a graph that has a cycle.
            // Your program catches the cycle and print the list of edges that form the cycle.

Should be able to load the .cpp file into any standard compiler, or ran in any ide (Visual Studio doesn't output anything for me though).
I used CLion to write the code, therefore it should compile if the configurations are set.

***Easiest method***
	1. copy the .cpp text using a text editor (atom, sublime, notepad, etc)
	2. goto https://www.onlinegdb.com/online_c++_compiler
		+ may need to pick language (I used C++17)
	3. paste over the code
	4. hit Run (in green at the top)
	5. the output terminal should appear at the bottom

	179 >>> Each line represents an edge for my program. Simply input into addEdge(fromNode, toNode)
	The first graph is acyclic and the second one is cyclic (minor changes from first graph)
	My print for edges is rather crude, the '->' represents edges from my adjaceny list
	Going forward, I will implement a pair function that takes in two vertices and represent it as an edge,
	from there I should be able to print edges in the form of tuples.
	Something like this 'A' 'goes to' 'B'
	Last note: I was unable to implement the flagging system as the professor had mentioned, it seems like the flagging fails
		as inDegrees of a node surpass the amount of flaggers I use.
