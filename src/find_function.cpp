#include "declarations.h"

#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <ostream>
#include <vector>

using namespace std;

void find_function(string phrase_find){
    int a = 1;
    ofstream logs("../doc/logs/find_function.txt", ios::out | ios::app);

    logs << date_time() << " [FIND_FUNCTION]: Entered function." << endl;

    string word = "";
    int word_num = 0;
    vector<string> phrase_words;

    for (unsigned int i = 0; i <= phrase_find.size(); ++i){
        if(phrase_find[i] == 0x20 || phrase_find[i] == '\0' || phrase_find[i] == '\r'){
            word_num++;

            logs << date_time() << " [FIND_FUNCTION]: Word Size: " << word.size() << endl;
            logs << date_time() << " [FIND_FUNCTION]: Word: " << word << endl;

            if(word.size() > 0){
                phrase_words.push_back(word);
                word = "";
            }
        }
        else word += phrase_find[i];
    }

    for(unsigned int i = 0; i < phrase_words.size(); i++){
        for(vector<Word>::iterator it = words.begin(); it != words.end(); it++){
            if(it->get_word() == phrase_words.at(i).c_str()){
                logs << date_time() << " [FIND_FUNCTION]: Found the word " << phrase_words.at(i) << endl;
                logs << date_time() << " [FIND_FUNCTION]: Line number: " << it->get_line() << endl;
                logs << date_time() << " [FIND_FUNCTION]: Word number: " << it->get_wordnum() << endl;
                logs << date_time() << " [FIND_FUNCTION]: Type: " << it->get_type() << endl;

                it->get_line();

                cout << date_time() << " [FIND_FUNCTION]: Found the word " << phrase_words.at(i) << endl;
                cout << date_time() << " [FIND_FUNCTION]: Line number: " << it->get_line() << endl;
                cout << date_time() << " [FIND_FUNCTION]: Word number: " << it->get_wordnum() << endl;
                cout << date_time() << " [FIND_FUNCTION]: Type: " << it->get_type() << endl;



                a = 0;
            }
            else if(a && (it == words.end()-1)){
                logs << date_time() << " [FIND_FUNCTION]: Word \'" << phrase_words.at(i) << "\' not found." << endl;
                cout << date_time() << " [FIND_FUNCTION]: Word \'" << phrase_words.at(i) << "\' not found." << endl;
            }
        }
    }

    logs << date_time() << " [FIND_FUNCTION]: Exiting function." << endl;

    logs.close();
}