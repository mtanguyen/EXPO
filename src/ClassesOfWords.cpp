/* puts block of code into lines of code
i.e.
this
Agreement
...
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct wordCount
{
    string word;
    int count;
};

int main()
{
    const size_t N = 500;
    wordCount docWordCount[N] = {};
    size_t n = 0;
    std::string::size_type i = 0;
    string text ="This AGREEMENT AND PLAN OF MERGER (this Agreement) is made and \
                  entered into as of August 15, 2011, by and among GOOGLE INC., \
                  a Delaware corporation (Parent), RB98 INC., a Delaware corporation \
                  and a wholly owned subsidiary of Parent (Merger Sub), and \
                  MOTOROLA MOBILITY HOLDINGS, INC., a Delaware corporation (the Company).";

    while (n < N && i < text.size())
    {
        while (i < text.size() && text[i] == ' ') {
            ++i;
        }

        std::string::size_type j = i;
        while (i < text.size() && text[i] != ' '){
            ++i;
        }

        if (j != i){
            docWordCount[n++].word.assign(text, j, i - j);
        }
    }

    ofstream file;
    file.open ("Example.txt");
    for (size_t i = 0; i < n; i++) {
        file << docWordCount[i].word << endl;
    }
    file.close();

    return 0;
}
