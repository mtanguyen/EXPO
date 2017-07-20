// sorting algorithm
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// string parts_speech [3][3500];

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
            if (word == parts_speech[j])
                cout << j << endl;
        }
            if (word == parts_speech[i])
                cout << i << endl;
    }

    line = i;
    wordnum = j;
    cout << line << endl;
    cout << wordnum << endl;


}
