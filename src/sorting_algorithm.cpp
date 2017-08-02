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
        for (j = 0; j < 3500; j++){
            if (char_word.c_str() == parts_speech[i][j]){
                logs << date_time() << " [SORT_ALGORITHM]: Word: " << char_word << endl;
                logs << date_time() << " [SORT_ALGORITHM]: Line Number: " << line << endl;
                logs << date_time() << " [SORT_ALGORITHM]: Word Number: " << wordnum << endl;
                logs << date_time() << " [SORT_ALGORITHM]: Type: " << parts.at(i) << endl;

                word = new Word(char_word, line, wordnum, parts.at(i));
                words.push_back(*word);

                // if(firsttime){
                //     word = new Word(char_word, line, wordnum, parts.at(i));
                //     words.push_back(*word);
                    
                //     already_created << word->get_word() << endl;

                //     firsttime--;
                // }
                // else{
                //     if(already_created.is_open()){
                //         int match = 0;
                //         while(getline(already_created, created_already)){
                //             if(created_already == char_word.c_str()){
                //                 for (vector<Word>::iterator it = words.begin(); it != words.end(); ++it){
                //                     if(it->get_word() == created_already){
                //                         it->add_line(line);
                //                         it->add_wordnum(wordnum);
                //                         it->add_type(parts.at(i));

                //                         match = 1;
                //                     }
                //                 }
                //             }
                //         }
                //         if(!match){
                //             word = new Word(char_word, line, wordnum, parts.at(i));
                //             words.push_back(*word);
                //         }


                //     }
                //     else{
                //         logs << date_time() << " [ERROR][SORT_ALGORITHM]: File not opened." << endl;
                //         cout << date_time() << " [ERROR][SORT_ALGORITHM]: File not opened." << endl;
                //     }  
                // }
                 
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

    // already_created.close();
    // already_created.open("../doc/already_created.txt", ios::out | ios::trunc);
    // already_created.close();

    logs.close();
}
