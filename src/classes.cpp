#include "declarations.h"

using namespace std;

Word::Word(string line_char, int line_num, int word_num, string plugin_type){
    word = line_char;
    line.push_back(line_num);
    wordnum.push_back(word_num);
    type.push_back(plugin_type);
}

Word::Word(string line_char, int line_num, int word_num, list<string> plugin_type){
    word = line_char;
    line.push_back(line_num);
    wordnum.push_back(word_num);
    for(list<string>::iterator it = plugin_type.begin(); it != plugin_type.end(); it++){
        type.push_back(*it);
    }
}

string Word::get_word(){
    return word;
}

string Word::get_line(){
    string return_string;
    for(list<int>::iterator it = line.begin(); it != line.end(); it++){
        return_string += to_string(*it);
        return_string += ", ";
    }
    return return_string;
}

string Word::get_wordnum(){
    string return_string;
    for(list<int>::iterator it = wordnum.begin(); it != wordnum.end(); it++){
        return_string += to_string(*it);
        return_string += ", ";
    }
    return return_string;
}

string Word::get_type(){
    string return_string;
    for(list<string>::iterator it = type.begin(); it != type.end(); it++){
        return_string += *it;
        return_string += '\t';
    }
    return return_string;
}

string Word::get_htmlsynonyms(){
    string return_string;
    for(list<string>::iterator it = html_synonyms.begin(); it != html_synonyms.end(); it++){
        return_string += *it;
        return_string += ", ";
    }
    return return_string;
}

list<Word> Word::get_synonyms(){
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

void Word::add_synonym(Word synonym){
    synonyms.push_back(synonym);
}

void Word::add_htmlsynonym(string html_synonym){
    html_synonyms.push_back(html_synonym);
}