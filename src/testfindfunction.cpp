#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main()
{
	int countwords=0;
	string file;
	string line;
	string word;
	cout<<"Write the name of the file."<<endl;
	cin>>file;
	ifstream File(file);
	if(File.is_open())
	{
		while(getline(File,line))
		{
			cout<<line<<endl;
		}

		cout<<"Write the word you're searching for."<<endl;
		cin>>word;
		while(!File.eof())
		{
			if(word.compare(line)==0)
				countwords++;
		}
		cout<<"The word has been found "<<countwords<<" times."<<endl;
		File.close();
	}
	else
	{
		cout<<"Error! File not found!";
		exit(1);
	}
}
