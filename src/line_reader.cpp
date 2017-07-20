//------------------------------------------------------------
// Author:			Alejandro Dominguez
// Origin Date:		July 19, 2017
// Last Modified:	July 19, 2017
// Description:		Program for reading the lines, and taking
//					out the lines.
//------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <istream>
#include <ostream>
#include <fstream>

using namespace std;

void line_reader(string line, int line_num){
	string word = "";
	int word_num = 0; 

	for (unsigned int i = 0; i < line.size(); ++i){
		if(line[i] == 0x20 || line[i] == '\0'){
			word_num++;

			if(word.size() > 0){
				if (word.size() == 1)
					cout << "Word: " << word << "\t\t";
				else cout << "Word: " << word << '\t';
				cout << "Word Number: " << word_num << '\t';
				cout << "Line Number: " << line_num << endl;
			}
			
			word = "";
		}
		else word += line[i];
	}
}