// #include "declarations.h"
//
// #include <iostream>
// #include <string>
// #include <fstream>
// #include <istream>
// #include <ostream>
// #include <vector>
//
// using namespace std;
//
// std::string parts_speech[3][3500];
//
// extern string date_time();
//
// void findfunction(){
//     int countwords = 0;
//     string word;
//     string file;
//     string line;
//     cout << "Write the name of the file." << endl;
//     cin >> file;
//
//     ifstream File(file);
//
//     if(File.is_open()){
//
//         while(getline(File, line)){
//             cout << line << endl;
//         }
//
//     cout << "Type in word you want to find." << endl;
//     cin >> word;
//
//     while(!File.eof()){
//         if(word.compare(line) == 0){
//             countwords++;
//         }
//     }
//
//     cout << "The word has been found " << countwords << "times." << endl;
//     File.close();
//
//     }
//     else{
//         cout << "Error! File not found!";
//         exit(1);
//     }
//
// }
//
// int main() {
//     string word;
//     cout << "What word do you want to find" << endl;
//     cin >> word;
//
//     vector<string> word_files;
//     word_files.push_back("~/EXPO/doc/Nouns.txt");
//     word_files.push_back("~/EXPO/doc/Adjectives.txt");
//     word_files.push_back("~/EXPO/doc/Verbs.txt");
//
//
//     int i = 0,j = 0;
//     string line;
//
//     while (i<3){
//         ifstream file((word_files.at(i)).c_str());
//
//         if(file.is_open()){
//             cout << date_time() << " [SETUP_ALGORITHM]: File " << word_files.at(i) << " succesfully opened." << endl;
//
//             while(getline(file, line)){
//                     parts_speech[i][j] = line;
//                     j++;
//             }
//         }
//         else cout << date_time() <<" [ERROR][SETUP_ALGORITHM]: line 27 failure, file did not open." << endl;
//
//         i++;
//
//         file.close();
//     }
//
//     cout << date_time() << " [SETUP_ALGORITHM]: Exited function." << endl;
// }

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
char paragraph;

int main()
{
    string word;
    string file;
    string line;
    cout << "Please write the name of the file:" << endl;
    getline(cin, file);

    ifstream File(file);
    vector<string> words;

    if(!File){
        cout << "Error opening file." << endl;
        exit(1);
    }

    if(File.is_open()){
        while(getline(File, line)){
    //        cout << line << endl;
    //        cout << line.size() << endl;
            while (File >> word){
                cout << word << endl;
                words.push_back(word);
            }
        }
    }

    cout << "Please enter the word you are searching for:";
    getline (cin,word);
    size_t found = line.find(word);

    bool wordsearch = true;
    while(line.find(word) != string::npos){
        if(line.find(word) == string::npos){
            cout << "" << word << " does not exist in sentence." << endl;
            std::size_t found = line.find(word);
        }
        if (found != std::string::npos){
            cout << word << " found at: " << found << endl;
        }
    }



//
//
//
//
//
// bool wordsearch = true;
// while (paragraph.find(word) != string::npos)  {
//
//   if (paragraph.find(word) == string::npos)
//  cout << "" << word << " does not exist in the sentence" << endl;
// 		std::size_t found = paragraph.find(word);
//   if (found!=std::string::npos)
//     std::cout << "first 'word' found at: " << found << '\n';
//
//   found=paragraph.find((word),found+1);
//   if (found!=std::string::npos)
//     std::cout << "second 'word' found at: " << found << '\n';
//   found=paragraph.find((word),found+1);
//   if (found!=std::string::npos)
//     std::cout << "third 'word' found at: " << found << '\n';
//   found=paragraph.find("word");
//   if (found!=std::string::npos)
//     std::cout << "'word' also found at: " << found << '\n';
//
//   found=paragraph.find('.');
//   if (found!=std::string::npos)
//     std::cout << "Period found at: " << found << '\n';
//
// 	system ("pause");
//
//     }while (wordsearch == true);
}
