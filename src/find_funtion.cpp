#include "declarations.h"

#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <ostream>
#include <vector>

using namespace std;

void find_function(string word_find){
    int a = 1;
    ofstream logs("../doc/logs/find_function.txt", ios::out | ios::app);

    for(vector<Word>::iterator it = words.begin(); it != words.end(); it++){
        if(it->get_word() == word_find){
            logs << date_time() << " [FIND_FUNCTION]: Found the word " << word_find << endl;
            logs << date_time() << " [FIND_FUNCTION]: Line number: " << it->get_line() << endl;
            logs << date_time() << " [FIND_FUNCTION]: Word number: " << it->get_wordnum() << endl;
            logs << date_time() << " [FIND_FUNCTION]: Type: " << it->get_type() << endl;
            cout << date_time() << " [FIND_FUNCTION]: Found the word " << word_find << endl;
            cout << date_time() << " [FIND_FUNCTION]: Line number: " << it->get_line() << endl;
            cout << date_time() << " [FIND_FUNCTION]: Word number: " << it->get_wordnum() << endl;
            cout << date_time() << " [FIND_FUNCTION]: Type: " << it->get_type() << endl;

            a = 0;
        }
        else if(a && (it == words.end()-1)){
            logs << date_time() << " [FIND_FUNCTION]: Word \'" << word_find << "\' not found." << endl;
            cout << date_time() << " [FIND_FUNCTION]: Word \'" << word_find << "\' not found." << endl;
        }
    }

    logs.close();
}