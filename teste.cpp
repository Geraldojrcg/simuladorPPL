#include "instrucao.h"
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <iomanip>
#include <sstream>
int main(){
    string inst;
    int op;
    cin >> op;
    getline(cin, inst);
    for(int i = 0; i<4; i++){
        cout << "inst" <<i<< ": ";
        getline(cin, inst);
        cout << inst << "\n";
    }
}