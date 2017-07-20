// sorting algorithm
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// word --> new instance of class --> new variable --> class type = plugin(word);
class Word{
private:
    string word;
    int line;
    int wordnum;
    string type;
};

void sortingalgorithm(string word, int line, int wordnum){

    int i = 0, j = 0;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3500; j++){
            if (word == parts_speech[i][j]){
                cout << i << endl;
                cout << j << endl;
            }
        }
    }

    line = i;
    wordnum = j;
    cout << line << endl;
    cout << wordnum << endl;


}
