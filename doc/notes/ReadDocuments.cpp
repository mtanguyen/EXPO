// read each line and parse through
// create a pointer for each word
// place each word into containers: subject, action/verb, preposition, result, etc

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main(){

    string word;
    ifstream myfile("Example"); // ifstream object
    vector<string> DataArray;   // store words in vector

    if (!myfile){ //test the file open
        cout << "Error opening outputfile"<<endl;
        system("pause");
        return -1;
    }
    while (getline(myfile, word)){
        DataArray.push_back(word);

    }
    cout << DataArray[0] << endl;
    myfile.close();  // close file
    return 0;

}

/*
ifstream file;
file.open("Example.txt");
string word;
char x;
word.clear();

while (!file.eof()){
    x = file.get();
    while(x != ' '){
        word = word + x;
        x = file.get();
    }

    cout << word << endl;
    word.clear();
}
*/
