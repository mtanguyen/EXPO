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

int main(int argc, char **argv){
	ifstream file (argv[1]);
	string line;

	if(file.is_open()){
		while(getline(file, line)){
			cout << line << endl;
		}
	}

	file.close();
	return 0;
}