#include "declarations.h"

using namespace std;

void html_synonyms(){
    for(list<Word>::iterator it = words.begin(); it != words.end(); it++){
        ifstream html_syn("../doc/html/html_" + it->get_word() + ".txt", ios::in);

        string line;
        while(getline(html_syn, line)){
            it->add_htmlsynonym(line);
        }

        html_syn.close();
    }
}