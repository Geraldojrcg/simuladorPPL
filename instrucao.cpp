#include "instrucao.h"
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <iomanip>
#include <sstream>
#include <list>

using namespace std;

Instrucao::Instrucao(string inst, string opcode, string op1, string op2, string op3){
    this->inst = inst;
    this->opcode = opcode;
    this->op1 = op1;
    this->op2 = op2;
    this->op3 = op3;
}
vector<string> split(string s){
    std::istringstream iss(s);
    std::vector<std::string> result{
        std::istream_iterator<std::string>(iss), {}
    };
    return result;
}
vector <Instrucao*> creatinst(int qtd){
    vector <Instrucao*> instrucoes;
    vector<string> res;
    Instrucao* ins;
    int i=0;
    string instrucao;
    getline(cin, instrucao);
    while(i < qtd){
        cout << "instrucao "<<i<<" :\n";
        getline(cin, instrucao);
        res = split(instrucao);
        if(res.size() < 3){
            ins = new Instrucao(instrucao, res[0],res[1], "", "");
            instrucoes.push_back(ins);
        }else{
            ins = new Instrucao(instrucao, res[0],res[1],res[2],res[3]);
            instrucoes.push_back(ins);
        }
        i++;
    }
    return instrucoes;
}
void print_ciclo(Instrucao* ins){
    
}
void simulator(vector <Instrucao*> instrucoes, int qtd){
    cout << "instruções\n";
    for(auto ins : instrucoes)
        cout << ins->inst << "\n";
    
}
int main(){
    int qtd;
    cout << "qtd de instrucao:\n";
    cin >> qtd;
    simulator(creatinst(qtd), qtd);

}