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

void Word::add_line(int line_num){
    line.push_back(line_num);
}

void Word::add_wordnum(int word_num){
    wordnum.push_back(word_num);
}

void Word::add_type(string plugin_type){
    type.push_back(plugin_type);
}

vector<Word> words;

void sorting_algorithm(string char_word, int line, int wordnum){
    ofstream logs("../doc/logs/sorting_algorithm.txt", ios::out | ios::app);

    logs << date_time() << " [SORT_ALGORITHM]: Entered function." << endl;
    
    Word *word;
    vector<string> parts;

    parts.push_back("Noun");
    parts.push_back("Adjective");
    parts.push_back("Verb");


    int i = 0, j = 0;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3500; j++){
            if (char_word.c_str() == parts_speech[i][j]){
                logs << date_time() << " [SORT_ALGORITHM]: Word: " << char_word << endl;
                logs << date_time() << " [SORT_ALGORITHM]: Line Number: " << line << endl;
                logs << date_time() << " [SORT_ALGORITHM]: Word Number: " << wordnum << endl;
                logs << date_time() << " [SORT_ALGORITHM]: Type: " << parts.at(i) << endl;

                // static int firsttime = 1;
                // if(firsttime){
                //     word = new Word(char_word, line, wordnum, parts.at(i));
                //     words.push_back(*word);
                // }
                // else{
                //     for(vector<Word>::iterator it = words.begin(); it != words.end(); it++){
                //         if(it->get_word() == char_word.c_str()){
                //             it->add_line(line);
                //             it->add_wordnum(wordnum);
                //             it->add_type(parts.at(i));
                //         }
                //         else{
                //             word = new Word(char_word, line, wordnum, parts.at(i));
                //             words.push_back(*word);
                //         }
                //     }
                // }

                word = new Word(char_word, line, wordnum, parts.at(i).c_str());
                words.push_back(*word);
                 
                logs << date_time() << " [SORT_ALGORITHM]: Word from Class: " << word->get_word() << endl;
                logs << date_time() << " [SORT_ALGORITHM]: Line Number from Class: " << word->get_line() << endl;
                logs << date_time() << " [SORT_ALGORITHM]: Word Number from Class: " << word->get_wordnum() << endl;
                logs << date_time() << " [SORT_ALGORITHM]: Type from Class: " << word->get_type() << endl;
                
                logs << date_time() << " [SORT_ALGORITHM]: New word created " << word->get_word() << endl;
            }
            else {
                // string type = plugin(word);
                // Word word(word, line, wordnum, type);
                // words.push_back(word);

                // word = new Word(char_word, line, wordnum, dic_algorithm(char_word.c_str()));
                // words.push_back(*word);

                if(i == 2 && j == 3499)
                    logs << date_time() << " [SORT_ALGORITHM]: No new words created for " << i+1 << " filess and " << (j+1)*3 << " words." << endl;
                
            }
        }

        // if(i == 2)
        //     dic_algorithm(char_word);
    }

    logs << date_time() << " [SORT_ALGORITHM]: Exiting function." << endl;

    logs.close();
}
