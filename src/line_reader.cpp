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
	ofstream logs("../doc/logs/line_reader.txt", ios::out | ios::app);

    logs << date_time() << " [LINE_READER]: Entered function." << endl;

	string word = "";
	int word_num = 0; 

	for (unsigned int i = 0; i <= line.size(); ++i){
		if((line[i] >= 0x20 && line[i] <= 0x2E) || line[i] == '\0' || line[i] == '\r'){
			word_num++;

			logs << date_time() << " [LINE_READER]: Word Size: " << word.size() << endl;
			logs << date_time() << " [LINE_READER]: Word: " << word << endl;

			if(word.size() > 0){
				sorting_algorithm(word,line_num,word_num);
				word = "";
			}
		}
		else word += line[i];
	}

	cout << date_time() << " [LINE_READER]: Input string " << line_num << " properly read and parsed." << endl;
    logs << date_time() << " [LINE_READER]: Exiting function." << endl;

    logs.close();
}
