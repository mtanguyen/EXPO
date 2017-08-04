#include "declarations.h"

using namespace std;

void synonyms(){
    ofstream logs(synonyms_log, ios::out | ios::app);

    logs << date_time() << " [SYNONYMS]: Entered function." << endl;

	for(list<Word>::iterator it = words.begin(); it != words.end(); it++){
        cout << date_time() << " [SYNONYMS]: Word to find the synonyms of: " << it->get_word() << endl;
        list<string> dic_synonyms = dic_algorithm(it->get_word(), 1);

        for(list<string>::iterator iter = dic_synonyms.begin(); iter != dic_synonyms.end(); iter++){
            for(list<Word>::iterator itr = words.begin(); itr != words.end(); itr++){
                if(itr->get_word() == *iter){
                    it->add_synonym(*itr);
                }
            }
        }
    }

    logs << date_time() << " [SYNONYMS]: Exited function." << endl;

    logs.close();
}