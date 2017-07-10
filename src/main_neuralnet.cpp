#include "funtions"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

extern Word	word;
extern Subject	subject;
extern Action	action;
extern Result	result;

using namespace std;

int main(int argc, char **argv){
	
	while(file_parse(file_read(argv[1])));
	
	return 0;
}
