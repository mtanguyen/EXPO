// sorting algorithm
#include <iostream>
#include <string>
using namespace std;

// word --> new instance of class --> new variable --> class type = plugin(word);
class Word{
public:
    void setName(string n){
        string name = n;
    }
    void setPosition(int p){
        int position = p;
    }
    void setLineNumber(int num){
        int lineNumber = num;
    }
    void getClassType(string type){
        string classType = type;
    }
};

void sorting_algorithm(string word, int sentence_position, int line_number){
    Word newWord;
    newWord.setName(word);
    newWord.setPosition(sentence_position);
    newWord.setLineNumber(line_number);
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

}
