#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <vector>
#include <list>
#include <string>
#include <strings.h>
#include <cstring>

#define find_function_log       "../doc/logs/find_function.txt"
#define dic_algorithm_log       "../doc/logs/dic_algorithm.txt"
#define line_reader_log         "../doc/logs/line_reader.txt"
#define main_log                "../doc/logs/main.txt"
#define setup_algorithm_log     "../doc/logs/setup_algorithm.txt"   
#define sorting_algorithm_log   "../doc/logs/sorting_algorithm.txt"
#define synonyms_log            "../doc/logs/synonyms_log.txt"

using namespace std;

extern string parts_speech[3][3500];
extern list<string> parts;

extern void synonyms();
extern void clear_logs();
extern void html_synonyms();
extern void setup_algorithm();
extern void similar_find(string,string,vector<string>);
extern void find_function(string, string);
extern void line_reader(string line, int line_num);
extern void sorting_algorithm(string word, int line, int wordnum);

extern string date_time();

extern list<string> dic_algorithm(string wordToGet);

class Word{
private:
    string word;
    list<int> line;
    list<int> wordnum;
    list<string> type;
    list<Word> synonyms;
    list<string> html_synonyms;
public:
    Word(string,int,int,string);
    Word(string,int,int,list<string>);

    string get_word();
    string get_line();
    string get_wordnum();
    string get_type();
    string get_htmlsynonyms();

    list<Word> get_synonyms();

    void add_line(int);
    void add_wordnum(int);
    void add_type(string);
    void add_synonym(Word);
    void add_htmlsynonym(string);

};

extern list<Word> words;