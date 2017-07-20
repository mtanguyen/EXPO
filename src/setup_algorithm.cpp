// sorting algorithm
#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <ostream>

using namespace std;

// word --> new instance of class --> new variable --> class type = plugin(word);
string parts_speech[3][3500];

void setup_algorithm(){
    string files[3];
    files[0] = "Nouns.txt";
    files[1] = "Adjectives.txt";
    files[2] = "Verbs.txt";

    
    int i = 0,j = 0;
    string line;

    while (i<3){
        ifstream file(files[i]);

        while(getline(file, line){
            if(file.is_open())
            {
                parts_speech[i][j] = line;
                cout << line << endl;
                // take away extra space
            }
            j++;
        }

        i++;

        file.close();
    }
}

    //newWord.getClassType = plugin(newWord);

    // // warning error
    // if (!flag){
    //     // type, name of word, what it did, where
    //     cout << "[Error]: sorting algorithm failed in code block 53-72." << endl;
    //
    // }
    //
    // // error -- just one portion
    // if (position = " "){
    //
    //
    // }
