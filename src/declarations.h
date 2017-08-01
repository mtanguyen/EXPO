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

extern void line_reader(string line, int line_num);
extern void setup_algorithm();
extern string date_time();
extern void sorting_algorithm(string word, int line, int wordnum);
extern vector<string> dic_algorithm(string wordToGet);
extern void find_function(string);

class Word{
private:
    string word;
    int line;
    vector<int> wordnum;
    vector<string> type;
public:
    Word(string,int,int,string);
    Word(string,int,int,vector<string>);
    string get_word();
    int get_line();
    string get_wordnum();
    string get_type();
    void add_wordnum(int);
    void add_type(string);
};

extern vector<Word> words;