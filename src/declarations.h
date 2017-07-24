#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

extern string parts_speech[3][3500];

extern void line_reader(string line, int line_num);
extern void setup_algorithm();
extern string date_time();
extern void sorting_algorithm(string word, int line, int wordnum);

class Word{
private:
    string word;
    int line;
    int wordnum;
    string type;
public:
    Word(string,int,int,string);
    string get_word();
    int get_line();
    int get_wordnum();
    string get_type();
};