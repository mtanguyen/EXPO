//------------------------------------------------------------
// Author:			Alejandro Dominguez
// Origin Date:		July 11, 2017
// Last Modified:	July 11, 2017
// Description:		Main program, all spwans from here.
//------------------------------------------------------------
#include "declarations.h"

using namespace std;

int main(int argc, char **argv){

	ifstream file(argv[1]);
	string line;

	setup_algorithm();

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