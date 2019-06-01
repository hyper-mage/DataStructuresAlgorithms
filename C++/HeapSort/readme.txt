The purpose of this assingment is to produce a heap and sort in ascending order.
    // Implement the heap sort.
    // Given a random list of numbers in an array (index zero stores the number of nodes).
    // Sort them in ascending order.
        // 1. You must first make a heap and then sort it.
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

Should be able to load the .cpp file into any standard compiler, or ran in any ide (Visual Studio doesn't output anything for me though).
I used CLion to write the code, therefore it should compile if the configurations are set.

***Easiest method***
	1. copy the .cpp text using a text editor (atom, sublime, notepad, etc)
	2. goto https://www.onlinegdb.com/online_c++_compiler
	3. paste over the code
	4. hit Run (in green at the top)
	5. the output terminal should appear at the bottom

	81 >>> Vales for array that you would personally like to input
	83 >>> "RNG" to make an array of 20 numbers if you trust it (outputs the same values each session since it is not seeded)
	Note: The "RNG" can be changed somewhat by changing the modulo function
