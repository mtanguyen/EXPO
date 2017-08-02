#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

extern string parts_speech[3][3500];
extern vector<string> parts;

extern void setup_algorithm();
extern void find_function(string);
extern void line_reader(string line, int line_num);
extern void sorting_algorithm(string word, int line, int wordnum);

extern string date_time();

extern vector<string> dic_algorithm(string wordToGet);

class Word{
private:
    string word;
    vector<int> line;
    vector<int> wordnum;
    vector<string> type;
    vector<Word> synonyms;
public:
    Word(string,int,int,string);
    Word(string,int,int,vector<string>);

    string get_word();
    string get_line();
    string get_wordnum();
    string get_type();

    vector<Word> get_synonyms();

    void add_line(int);
    void add_wordnum(int);
    void add_type(string);
    void add_synonym(Word);

};

extern vector<Word> words;