#include "declarations.h"

using namespace std;

list<Word> words;

void sorting_algorithm(string char_word, int line, int wordnum){
    ofstream logs(sorting_algorithm_log, ios::out | ios::app);

    logs << date_time() << " [SORT_ALGORITHM]: Entered function." << endl;
    
    Word *word;
    vector<string> parts(3);

    parts.push_back("Noun");
    parts.push_back("Adjective");
    parts.push_back("Verb");


    int i = 0, j = 0, k = 0;
    for (i = 0; i < 3; i++){
        for(list<Word>::iterator it = words.begin(); it != words.end(); it++){
            if(char_word.c_str() == it->get_word()){
                it->add_line(line);
                it->add_wordnum(wordnum);
                it->add_type(parts.at(i));

                k = -1;
            }
        }
        if(k != -1){
            for (j = 0; j < 3500; j++){
                if (strcasecmp(char_word.c_str(),parts_speech[i][j].c_str()) == 0){
                    logs << date_time() << " [SORT_ALGORITHM]: Word: " << char_word << endl;
                    logs << date_time() << " [SORT_ALGORITHM]: Line Number: " << line << endl;
                    logs << date_time() << " [SORT_ALGORITHM]: Word Number: " << wordnum << endl;
                    logs << date_time() << " [SORT_ALGORITHM]: Type: " << parts.at(i) << endl;

                    word = new Word(char_word, line, wordnum, parts.at(i));
                    words.push_back(*word);
                    delete word;

                    logs << date_time() << " [SORT_ALGORITHM]: Word from Class: " << word->get_word() << endl;
                    logs << date_time() << " [SORT_ALGORITHM]: Line Number from Class: " << word->get_line() << endl;
                    logs << date_time() << " [SORT_ALGORITHM]: Word Number from Class: " << word->get_wordnum() << endl;
                    logs << date_time() << " [SORT_ALGORITHM]: Type from Class: " << word->get_type() << endl;
                
                    logs << date_time() << " [SORT_ALGORITHM]: New word created " << word->get_word() << endl;
                }
                else {
                    if(j == 3499){
                        logs << date_time() << " [SORT_ALGORITHM]: Looking for word " << char_word << " in the dictionary." << endl;
                        
                        string location = "../doc/" + parts.at(i+1) + ".txt";
                        ofstream type_file(location, ios::out | ios::app);
                        if(type_file.is_open())
                            type_file << char_word << endl;
                        else cout << date_time() << " [SORT_ALGORITHM]: " << "../doc/" + parts.at(i) + ".txt" << " did not open." << endl;
                        type_file.close();

                        list<string> dic_words = dic_algorithm(char_word.c_str());
                        
                        if(dic_words.size() < 1){
                            word = new Word(char_word.c_str(), line, wordnum, "unknown");
                            words.push_back(*word);
                            delete word;
                        }
                        else{
                            word = new Word(char_word.c_str(), line, wordnum, dic_words);
                            words.push_back(*word);
                            delete word;
                        }
                    }
                }
            }
        }
    }

    logs << date_time() << " [SORT_ALGORITHM]: Exiting function." << endl;

    logs.close();
}