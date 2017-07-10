//--------------------------------------------------------------
// Author:		Alejandro Dominguez								
// Date:		July 10th, 2017									
// Description:	Program to parse through the line and pick 
//				out the words.				
//--------------------------------------------------------------
#include <iostream>

vector<string> file_parse(string line){
	int a = 0, b = 0;
	vector<string> words;
	
	if(line != NULL){
		while(line[a] != '/0'){
			switch(line[a]){
				case 0x41 ... 0x5A:	// Upper Case Letters
					words[b][a] = line[a];
					break;
				case 0x61 .. 0x7A:	// Lower Case Letters
					words[b][a] = line[a];
					break;
				case 0x20:			// Space
					b++;
					break;
			}
		
			a++;
		}
	
		return words;
	}
	else return NULL;
}
