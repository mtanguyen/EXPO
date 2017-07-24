#include "declarations.h"

#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <ostream>
#include <vector>

using namespace std;

vector<string> parts;

extern string parts_speech[3][3500];
extern string date_time();

Word::Word(string line, int line_num, int word_num, string plugin_type){
    word = line;
    line = line_num;
    wordnum = word_num;
    type = plugin_type;
}

string Word::get_word(){
    return word;
}
int Word::get_line(){
    return line;
}
int Word::get_wordnum(){
    return wordnum;
}
string Word::get_type(){
    return type;
}

void sortingalgorithm(string char_word, int line, int wordnum){
    cout << date_time() << " [SORTALGORITHM]: Entered function." << endl;
    vector<Word> words;
    Word *word;

    parts.push_back("Noun");
    parts.push_back("Adjective");
    parts.push_back("Verb");


    int i = 0, j = 0;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3500; j++){
            if (char_word == parts_speech[i][j]){
                word = new Word(char_word, line, wordnum, parts.at(i));
                words.push_back(*word);
            }
            else {
                // string type = plugin(word);
                // Word word(word, line, wordnum, type);
                // words.push_back(word);
            }
        }
    }

    cout << date_time() << " [SORTALGORITHM]: Exiting function." << endl;
}
