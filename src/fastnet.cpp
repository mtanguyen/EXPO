//------------------------------------------------------------
// Author:			Alejandro Dominguez
// Origin Date:		July 11, 2017
// Last Modified:	July 11, 2017
// Description:		Main program, all spwans from here.
//------------------------------------------------------------
#include "declarations.h"

using namespace std;

int main(int argc, char **argv){
	cout << date_time() << " [FASTNET]: Entered function." << endl;

	ifstream file(argv[1]);
	string line;

	setup_algorithm();

	int line_num = 0;

	if(file.is_open()){
		cout << date_time() << " [FASTNET]: File " << argv[1] << " succesfully opened." << endl;

		while(getline(file, line)){
			line_num++;
			line_reader(line,line_num);
		}
	}

	file.close();

	cout << date_time() << " [FASTNET]: Exiting function." << endl;

	return 0;
}