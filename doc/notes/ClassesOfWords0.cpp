// sorting algorithm
#include <iostream>
#include <string>
using namespace std;

// void sorting_algorithm(String word, in sentence_position, int line_number);
class Sort{
    void merge(Comparable[] a, Comparable [] aux, int lo, int mid, int high){
        int i = lo, j = mid;
        for (int k = lo; k < hi; k++) {
            if      (i == mid)                 aux[k] = a[j++];
            else if (j == hi)                  aux[k] = a[i++];
            else if (a[j].compareTo(a[i]) < 0) aux[k] = a[j++];
            else                               aux[k] = a[i++];
        }

        // copy back
        for (int k = lo; k < hi; k++)
            a[k] = aux[k];
    }
};
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
