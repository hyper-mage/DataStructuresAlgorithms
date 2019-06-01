Should be able to load the .cpp file into any standard compiler, or ran in any ide (Visual Studio doesn't output anything for me though).
I used CLion to write the code, therefore it should compile if the configurations are set.

***Easiest method***
	1. copy the .cpp text using a text editor (atom, sublime, notepad, etc)
	2. goto https://www.onlinegdb.com/online_c++_compiler
		+ may need to pick language (I used C++17)
	3. paste over the code
	4. hit Run (in green at the top)
	5. the output terminal should appear at the bottom

	Ideally, I would use an infile function like this:
		string line;
		ifstream myfile("word_list.txt");
		if (myfile.is_open()) {
				while (getline(myfile, line)) {
						table->insert(line);
				}
				myfile.close();
		}

	However, that wouldn't work on an online compiler and I'm not sure where to
	have you put it so that it runs correctly.

	Between lines <191> and <210> are the input functions for words. Included is a list of words
	generated form an online words generator. Any words can be used and the program made more general
	if the above infile string were utilized.
