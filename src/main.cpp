//------------------------------------------------------------
// Author:			Alejandro Dominguez
// Origin Date:		July 11, 2017
// Last Modified:	July 11, 2017
// Description:		Main program, all spwans from here.
//------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <istream>
#include <ostream>
#include <fstream>

using namespace std;

extern void line_reader(string line, int line_num);
extern void setup_algorithm();
extern string date_time();

int main(int argc, char **argv){
	cout << date_time() << " [MAIN]: Entered program." << endl;

	string input_file = argv[1];

	ifstream file (input_file.c_str());
	string line;

	setup_algorithm();

	int line_num = 0;

	if(file.is_open()){
		cout << date_time() << " [MAIN]: File " << input_file << " succesfully opened." << endl;
		
		while(getline(file, line)){
			line_num++;
			line_reader(line,line_num);
		}
	}

	file.close();

	cout << date_time() << " [MAIN]: Exiting program." << endl;
	return 0;
}