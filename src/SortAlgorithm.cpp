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
    string files[3];
    files[0] = "Nouns.txt";
    files[1] = "Adjextives.txt";
    files[2] = "Verbs.txt";

    ifstream file ();
    int i = 0;
    while (){
        file.open(files[i]);

        if(files[0].is_open())
        {
            char noun[3500][10];
            for (int j = 0; j < sizeof(noun); j++)
            {
                file >> noun[j];
                // take away extra space
            }
        }

        i++;
        file.close();

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
