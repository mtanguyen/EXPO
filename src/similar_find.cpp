#include "declarations.h"

using namespace std;

void similar_find(string file_location, string phrase_find, vector<string> phrase_words){
    ifstream file(file_location);
    ofstream logs("../doc/logs/similiar_find.txt", ios::app | ios::out);

    string line, line2, line3;

    list<int> location_word;
    list<int> location_line;
    vector<string> temp;

    for(unsigned int i = 0; i < phrase_words.size(); i++){\
        temp = phrase_words;

        for(vector<string>::iterator it = phrase_words.begin(); it != phrase_words.end(); it++){
            ifstream synonym_html("../doc/html/html_" + *it + ".txt", ios::in);

            while(getline(synonym_html, line)){
                temp.at(i) = line; 

                for(unsigned int y = 0; y < temp.size(); y++){
                    line2 += temp.at(y);
                    line2 += " ";
                }

                int line_num = 0;
                while(getline(file, line3)){
                    line_num++;
                    size_t found = line3.find(line2);
                    if(found != string::npos){
                        location_word.push_back(static_cast<int>(found));
                        location_line.push_back(line_num);

                        cout << "Found a new match." << endl;
                    }
                }
            }
        }
    } 

    if(location_word.size() > 0){
        logs << date_time() << " [SIMILAR_FIND]: Found the phrase " << phrase_find << endl;
        logs << date_time() << " [SIMILAR_FIND]: Line number: ";
        cout << date_time() << " [SIMILAR_FIND]: Found the phrase " << phrase_find << endl;
        cout << date_time() << " [SIMILAR_FIND]: Line number: ";
        
        for(list<int>::iterator it = location_line.begin(); it != location_line.end(); it++){
            logs << *it << '\t';
            cout << *it << '\t';
        }
        logs << endl;
        cout << endl;
        logs << date_time() << " [SIMILAR_FIND]: Phrase starts at character(s): ";
        cout << date_time() << " [SIMILAR_FIND]: Phrase starts at character(s): ";
        for(list<int>::iterator it = location_word.begin(); it != location_word.end(); it++){
            logs << *it << '\t';
            cout << *it << '\t';
        }
        logs << endl;
        cout << endl;
    }   
}