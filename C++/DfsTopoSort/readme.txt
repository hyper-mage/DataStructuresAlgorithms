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
