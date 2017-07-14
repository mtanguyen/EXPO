// sorting algorithm
#include <iostream>
#include <string>
using namespace std;

// void sorting_algorithm(String word, in sentence_position, int line_number);

void sorting_algorithm(string word, int sentence_position, int line_number){
    string mockWord = word;
    int position = sentence_position;
    int number = line_number;
    bool flag = true;
    int array[0];

    for (int i = 0; i < position; i++){
        int index_of_min = i;
        for (int j = i; j < position; j++){
            if (array[index_of_min] > array[j]){
                index_of_min = j;
            }
        }
        int temp = array[i];
        array[i] = array[index_of_min];
        array[index_of_min] = temp;
    }

    // warning error
    if (!flag){
        // type, name of word, what it did, where
        cout << "[Error]: sorting algorithm failed in code block 53-72." << endl;

    }

    // error -- just one portion
    if (position = " "){


    }

}

// word --> new instance of class --> new variable --> class type = plugin(word);
