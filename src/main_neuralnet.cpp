//--------------------------------------------------------------
// Author:		Alejandro Dominguez								
// Date:		July 10th, 2017									
// Description:	Main file, all spawns from here.				
//--------------------------------------------------------------
//--------------------------------------------------------------
// Command line call:											
//		fastnet "file/location.txt" [modifiers]					
//--------------------------------------------------------------

#include "funtions"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

extern Word	word;
extern Subject	subject;
extern Action	action;
extern Result	result;

extern vector<string>	file_parse(string);
extern void				word_init(vector<string>);

using namespace std;

int main(int argc, char **argv){
	
	istream input;
	string input_line;
	vector<string> words;

	input.open(argv[1]);

	if(input.is_open){
		while(getline(input, input_line)){
			words = file_parse(input_line);
			word_init(words);
		}
	}
	else cout << "[ERROR]: The program could not find specified file.";

	return 0;
}
