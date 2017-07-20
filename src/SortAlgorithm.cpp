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

int main(){
    ifstream file ("Nouns.txt");
    if(file.is_open())
    {
        char noun[3500][25];
        for (int i = 0; i < sizeof(noun); i++)
        {
            file >> noun[i];

        }

        for (int i = 0; i < sizeof(noun); i++) cout << noun[i] << endl;
    }

    Word word1;
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
