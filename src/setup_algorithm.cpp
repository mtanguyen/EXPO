#include "declarations.h"

using namespace std;

string parts_speech[3][3500];

extern string date_time();

void setup_algorithm(){
    cout << date_time() << " [SETUP_ALGORITHM]: Entered function." << endl;

    vector<string> word_files;
    word_files.push_back("../doc/Nouns.txt");
    word_files.push_back("../doc/Adjectives.txt");
    word_files.push_back("../doc/Verbs.txt");

    
    int i = 0;
    string line;

    while (i<3){
        int j = 0;
        ifstream file((word_files.at(i)).c_str());

        if(file.is_open()){
            cout << date_time() << " [SETUP_ALGORITHM]: File " << word_files.at(i) << " succesfully opened." << endl;
                
            while(getline(file, line)){
                cout << date_time() << " [SETUP_ALGORITHM]: line: " << line << endl;
                
                parts_speech[i][j] = line;
                   
                cout << date_time() << " [SETUP_ALGORITHM]: parts_speech[" << i << "][" << j << "]: " << parts_speech[i][j] << endl;

                j++; 
            }
        }
        else{
            cout << date_time() <<" [ERROR][SETUP_ALGORITHM]: line 27 failure, file "<< word_files.at(i) << " did not open." << endl;
        }
        i++;

        file.close();
    }

    cout << date_time() << " [SETUP_ALGORITHM]: Exited function." << endl;
}