#include "declarations.h"

using namespace std;

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
    // static unsigned int firsttime = 1;
    // string created_already;
    // fstream already_created("../doc/already_created.txt", ios::out | ios::in | ios::app);
    for (i = 0; i < 3; i++){
        for(vector<Word>::iterator it = words.begin(); it != words.end(); it++){
            if(char_word.c_str() == it->get_word()){
                it->add_line(line);
                it->add_wordnum(wordnum);
                it->add_type(parts.at(i));

                i = -1;
            }
        }
        if(i != -1){
            for (j = 0; j < 3500; j++){
                if (char_word.c_str() == parts_speech[i][j]){
                    logs << date_time() << " [SORT_ALGORITHM]: Word: " << char_word << endl;
                    logs << date_time() << " [SORT_ALGORITHM]: Line Number: " << line << endl;
                    logs << date_time() << " [SORT_ALGORITHM]: Word Number: " << wordnum << endl;
                    logs << date_time() << " [SORT_ALGORITHM]: Type: " << parts.at(i) << endl;

                    word = new Word(char_word, line, wordnum, parts.at(i));
                    words.push_back(*word);

                    logs << date_time() << " [SORT_ALGORITHM]: Word from Class: " << word->get_word() << endl;
                    logs << date_time() << " [SORT_ALGORITHM]: Line Number from Class: " << word->get_line() << endl;
                    logs << date_time() << " [SORT_ALGORITHM]: Word Number from Class: " << word->get_wordnum() << endl;
                    logs << date_time() << " [SORT_ALGORITHM]: Type from Class: " << word->get_type() << endl;
                
                    logs << date_time() << " [SORT_ALGORITHM]: New word created " << word->get_word() << endl;
                }
                else {
                    if(i == 2 && j == 3499){
                        word = new Word(char_word.c_str(), line, wordnum, dic_algorithm(char_word.c_str(), 0));
                        words.push_back(*word);
                    }
                }
            }
        }
    }

    logs << date_time() << " [SORT_ALGORITHM]: Exiting function." << endl;

    // already_created.close();
    // already_created.open("../doc/already_created.txt", ios::out | ios::trunc);
    // already_created.close();

    logs.close();
}
