#include "declarations.h"

using namespace std;

void clear_logs(){
    ofstream logs(find_function_log, ios::trunc);
    logs.close();
   
    logs.open(dic_algorithm_log, ios::trunc);
    logs.close();
   
    logs.open(line_reader_log, ios::trunc);
    logs.close();
   
    logs.open(main_log, ios::trunc);
    logs.close();
   
    logs.open(setup_algorithm_log, ios::trunc);
    logs.close();
   
    logs.open(sorting_algorithm_log, ios::trunc);
    logs.close();

    logs.open(synonyms_log, ios::trunc);
    logs.close();
}