#include "declarations.h"

using namespace std;

string parts_speech[3][3500];

extern string date_time();

void setup_algorithm(){
    ofstream logs("../doc/logs/setup_algorithm.txt", ios::out | ios::app);

    logs << date_time() << " [SETUP_ALGORITHM]: Entered function." << endl;

    vector<string> word_files;
    word_files.push_back("../doc/Nouns.txt");
    word_files.push_back("../doc/Adjectives.txt");
    word_files.push_back("../doc/Verbs.txt");

    
    int a = 0;
    string line;

    while (a<3){
        int j = 0;
        ifstream file((word_files.at(a)).c_str());

        if(file.is_open()){
            logs << date_time() << " [SETUP_ALGORITHM]: File " << word_files.at(a) << " succesfully opened." << endl;
                
            while(getline(file, line)){
                string word = "";
                int word_num = 0; 

                for (unsigned int i = 0; i < line.size(); ++i){
                    if(line[i] == 0x20 || line[i] == '\0' || line[i] == '\r'){
                        word_num++;
                        
                        logs << date_time() << " [SETUP_ALGORITHM]: word: " << word << endl;
                
                        parts_speech[a][j] = word;
                   
                        logs << date_time() << " [SETUP_ALGORITHM]: parts_speech[" << a << "][" << j << "]: " << parts_speech[a][j] << endl;

                        j++; 

                        word = "";
                    }
                    else word += line[i];
                }
            }
        }
        else{
            logs << date_time() <<" [ERROR][SETUP_ALGORITHM]: line 27 failure, file "<< word_files.at(a) << " did not open." << endl;
        }
        a++;

        file.close();
    }

    logs << date_time() << " [SETUP_ALGORITHM]: Exited function." << endl;

    logs.close();
}