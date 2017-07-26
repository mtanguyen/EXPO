//------------------------------------------------------------
// Author:			Alejandro Dominguez
// Origin Date:		July 19, 2017
// Last Modified:	July 21, 2017
// Description:		Program for reading the lines, and taking
//					out the lines.
//------------------------------------------------------------
#include "declarations.h"

using namespace std;

void line_reader(string line, int line_num){
    cout << date_time() << " [LINE_READER]: Entered function." << endl;

	string word = "";
	int word_num = 0; 

	for (unsigned int i = 0; i < line.size(); ++i){
		if(line[i] == 0x20 || line[i] == '\0' || line[i] == '\r'){
			word_num++;

			// cout << "Word Size: " << word.size() << endl;

			if(word.size() > 0){
				// if (word.size() == 1)
				// 	cout << "Word: " << word << "\t\t";
				// else cout << "Word: " << word << '\t';
				// cout << "Word Number: " << word_num << '\t';
				// cout << "Line Number: " << line_num << endl;

				//sorting_algorithm(word,line_num,word_num);
				word = "";
			}
		}
		else word += line[i];
	}

    cout << date_time() << " [LINE_READER]: Exiting function." << endl;
}