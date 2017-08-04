#include "declarations.h"

using namespace std;

void synonyms(){
    ofstream logs(synonyms_log, ios::out | ios::app);
    

    logs << date_time() << " [SYNONYMS]: Entered function." << endl;

	for(list<Word>::iterator it = words.begin(); it != words.end(); it++){
        cout << date_time() << " [SYNONYMS]: Word to find the synonyms of: " << it->get_word() << endl;

        string html_filename = "../doc/html/html_" + it->get_word() + ".txt";
        ifstream html_synonym(html_filename, ios::in);
        string synonym;
        
        while(getline(html_synonym, synonym)){
           for(list<Word>::iterator itr = words.begin(); itr != words.end(); itr++){
                if(itr->get_word() == synonym){
                    it->add_synonym(*itr);
                }
            }
        }
    }

    logs << date_time() << " [SYNONYMS]: Exited function." << endl;

    logs.close();
}