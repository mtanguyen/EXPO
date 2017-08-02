#include "declarations.h"

using namespace std;

Word::Word(string line_char, int line_num, int word_num, string plugin_type){
    word = line_char;
    line.push_back(line_num);
    wordnum.push_back(word_num);
    type.push_back(plugin_type);
}

string Word::get_word(){
    return word;
}

string Word::get_line(){
    string return_string;
    for(unsigned int i = 0; i < line.size(); i++){
        return_string += to_string(line.at(i));
        return_string += '\t';
    }
    return return_string;
}

string Word::get_wordnum(){
    string return_string;
    for(unsigned int i = 0; i < wordnum.size(); i++){
        return_string += to_string(wordnum.at(i));
        return_string += '\t';
    }
    return return_string;
}

string Word::get_type(){
    string return_string;
    for(unsigned int i = 0; i < type.size(); i++){
        return_string += type.at(i);
    }
    return return_string;
}

vector<Word> Word::get_synonyms(){
    return synonyms;
}

void Word::add_line(int line_num){
    line.push_back(line_num);
}

void Word::add_wordnum(int word_num){
    wordnum.push_back(word_num);
}

void Word::add_type(string plugin_type){
    type.push_back(plugin_type);
}

void Word::add_synonyms(Word synonym){
    synonyms.push_back(synonym);
}