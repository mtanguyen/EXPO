#include "declarations.h"

using namespace std;

vector<string> parts;
vector<Word> words;

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

void sorting_algorithm(string char_word, int line, int wordnum){
    ofstream logs("../doc/logs/sorting_algorithm.txt", ios::out | ios::app);

    logs << date_time() << " [SORT_ALGORITHM]: Entered function." << endl;
    
    Word *word;

    parts.push_back("Noun");
    parts.push_back("Adjective");
    parts.push_back("Verb");


    int i = 0, j = 0;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3500; j++){
            if (char_word.c_str() == parts_speech[i][j]){
                word = new Word(char_word, line, wordnum, parts.at(i));
                words.push_back(*word);
                
                logs << date_time() << " [SORT_ALGORITHM]: New word created " << word->get_word() << endl;
            }
            else {
                // string type = plugin(word);
                // Word word(word, line, wordnum, type);
                // words.push_back(word);


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
