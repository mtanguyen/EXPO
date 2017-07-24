//------------------------------------------------------------
// Author:			Alejandro Dominguez
// Origin Date:		July 11, 2017
// Last Modified:	July 11, 2017
// Description:		Main program, all spwans from here.
//------------------------------------------------------------
#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <ostream>
#include <vector>

using namespace std;

extern void line_reader(string line, int line_num);
extern void setup_algorithm();

int main(int argc, char **argv){
	ifstream file(argv[1]);
	string line;

	setup_algorithm();
	cout << "setup_algorithm Succes" << endl;

	int line_num = 0;

	if(file.is_open()){
		while(getline(file, line)){
			line_num++;
			line_reader(line,line_num);
		}
	}

	file.close();
	return 0;
}