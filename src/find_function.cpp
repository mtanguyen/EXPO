#include "declarations.h"

using namespace std;

void find_function(string phrase_find, string file_location){
    int a = 1;
    ofstream logs(find_function_log, ios::out | ios::app);
    ifstream file(file_location);

    logs << date_time() << " [FIND_FUNCTION]: Entered function." << endl;

    string word = "", line;
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

    list<int> location_word;
    list<int> location_line;
    if(phrase_words.size() > 1){
        int line_num = 0;
        while(getline(file, line)){
            line_num++;
            size_t found = line.find(phrase_find);
            if(found != string::npos){
                location_word.push_back(static_cast<int>(found));
                location_line.push_back(line_num);
            }
            else{
                similar_find(file_location, phrase_find, phrase_words);
            }
        }
    
        if(location_word.size() > 0){
            logs << date_time() << " [FIND_FUNCTION]: Found the phrase " << phrase_find << endl;
            logs << date_time() << " [FIND_FUNCTION]: Line number: ";
            cout << date_time() << " [FIND_FUNCTION]: Found the phrase " << phrase_find << endl;
            cout << date_time() << " [FIND_FUNCTION]: Line number: ";
            for(list<int>::iterator it = location_line.begin(); it != location_line.end(); it++){
                logs << *it << '\t';
                cout << *it << '\t';
            }
            logs << endl;
            cout << endl;
            logs << date_time() << " [FIND_FUNCTION]: Phrase starts at character(s): ";
            cout << date_time() << " [FIND_FUNCTION]: Phrase starts at character(s): ";
            for(list<int>::iterator it = location_word.begin(); it != location_word.end(); it++){
                logs << *it << '\t';
                cout << *it << '\t';
            }
            logs << endl;
            cout << endl;
        }
        else{
            cout << date_time() << " [FIND_FUNCTION]: Phrase \"" << phrase_find << "\" not found." << endl; 
        }
    }
    else{
        for(vector<string>::iterator iter = phrase_words.begin(); iter != phrase_words.end(); iter++){
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
                        synonym_types += ", ";
                    }
                    logs << date_time() << " [FIND_FUNCTION]: Synonyms within the file: " << synonym_types << endl;
                    logs << date_time() << " [FIND_FUNCTION]: Synonyms:" << it->get_htmlsynonyms() << endl;

                    cout << date_time() << " [FIND_FUNCTION]: Found the word " << *iter << endl;
                    cout << date_time() << " [FIND_FUNCTION]: Line number: " << it->get_line() << endl;
                    cout << date_time() << " [FIND_FUNCTION]: Word number: " << it->get_wordnum() << endl;
                    cout << date_time() << " [FIND_FUNCTION]: Type: " << it->get_type() << endl;
                    cout << date_time() << " [FIND_FUNCTION]: Synonyms within the file: " << synonym_types << endl;
                    cout << date_time() << " [FIND_FUNCTION]: Synonyms:" << it->get_htmlsynonyms() << endl;

                    a = 0;
                }
                else if(a && (it == words.end())){
                    logs << date_time() << " [FIND_FUNCTION]: Word \'" << *iter << "\' not found." << endl;
                    cout << date_time() << " [FIND_FUNCTION]: Word \'" << *iter << "\' not found." << endl;
                }
            }
        }
    }
    logs << date_time() << " [FIND_FUNCTION]: Exiting function." << endl;

    logs.close();
    file.close();
}