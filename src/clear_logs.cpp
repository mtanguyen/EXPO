#include "declarations.h"

using namespace std;

void clear_logs(){
    system("exec rm -r ../doc/logs/*");
    system("exec rm -r ../doc/html/*");
}