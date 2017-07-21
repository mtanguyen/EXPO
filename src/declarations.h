#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <vector>

class Word{
private:
    std::string word;
    int line;
    int wordnum;
    std::string type;
public:
    Word(std::string,int,int,std::string);
    std::string get_word();
    int get_line();
    int get_wordnum();
    std::string get_type();
};