#include "declarations.h"

using namespace std;

void find_function(string phrase_find){
    int a = 1;
    ofstream logs(find_function_log, ios::out | ios::app);

    logs << date_time() << " [FIND_FUNCTION]: Entered function." << endl;

    string word = "";
    int word_num = 0;
    list<string> phrase_words;

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

    for(list<string>::iterator iter = phrase_words.begin(); iter != phrase_words.end(); iter++){
        for(list<Word>::iterator it = words.begin(); it != words.end(); it++){
            if(it->get_word() == *iter){
                logs << date_time() << " [FIND_FUNCTION]: Found the word " << *iter << endl;
                logs << date_time() << " [FIND_FUNCTION]: Line number: " << it->get_line() << endl;
                logs << date_time() << " [FIND_FUNCTION]: Word number: " << it->get_wordnum() << endl;
                logs << date_time() << " [FIND_FUNCTION]: Type: " << it->get_type() << endl;
                string synonym_types;
                list<Word> temp_Word = it->get_synonyms();
                for(list<Word>::iterator itr = temp_Word.begin(); itr != temp_Word.end(); itr++){
                    synonym_types += itr->get_word();
                    synonym_types += '\t';
                }
                logs << date_time() << " [FIND_FUNCTION]: Synonyms: " << synonym_types << endl;

                it->get_line();

                cout << date_time() << " [FIND_FUNCTION]: Found the word " << *iter << endl;
                cout << date_time() << " [FIND_FUNCTION]: Line number: " << it->get_line() << endl;
                cout << date_time() << " [FIND_FUNCTION]: Word number: " << it->get_wordnum() << endl;
                cout << date_time() << " [FIND_FUNCTION]: Type: " << it->get_type() << endl;
                 cout << date_time() << " [FIND_FUNCTION]: Synonyms: " << synonym_types << endl;



                a = 0;
            }
            else if(a && (it == words.end())){
                logs << date_time() << " [FIND_FUNCTION]: Word \'" << *iter << "\' not found." << endl;
                cout << date_time() << " [FIND_FUNCTION]: Word \'" << *iter << "\' not found." << endl;
            }
        }
    }

    logs << date_time() << " [FIND_FUNCTION]: Exiting function." << endl;

    logs.close();
}