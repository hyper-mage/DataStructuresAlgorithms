Should be able to load the .cpp file into any standard compiler, or ran in any ide (Visual Studio doesn't output anything for me though).
I used CLion to write the code, therefore it should compile if the configurations are set.

***Easiest method***
	1. copy the .cpp text using a text editor (atom, sublime, notepad, etc)
	2. goto https://www.onlinegdb.com/online_c++_compiler
	3. paste over the code
	4. hit Run (in green at the top)
	5. the output terminal should appear at the bottom

***notes to the grader***
	Within the main function space I have comments that will inform the grader where to input values
	Lines for grader to look for inputting:
	81 >>> Vales for array that you would personally like to input
	83 >>> "RNG" to make an array of 20 numbers if you trust it (outputs the same values each session since it is not seeded)
	Note: The "RNG" can be changed somewhat by changing the modulo function
