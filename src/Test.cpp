// sorting algorithm
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string parts_speech [3][3500];
// word --> new instance of class --> new variable --> class type = plugin(word);
class Word{
private:
    string word;
    int line;
    int wordnum;
    string type;
};

int main(){
    Word word1;

    string files[3];
    files[0] = "Nouns.txt";
    files[1] = "Adjextives.txt";
    files[2] = "Verbs.txt";

    ifstream file ();
    string line;
    int i = 0, j = 0;
    while (i < 3){
        file.open(files[i]);
        while (getline(file, line)){
            if (files[i].is_open()){
                    line >> parts_speech[i][j];
                    cout << line << endl;
            }
        }

        i++;
        file.close();

    }


}
