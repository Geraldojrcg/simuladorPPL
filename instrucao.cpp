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
    std::vector<std::string> result;
    std::string token;
    while(getline(iss, token, ' ')) {
       result.push_back(token);
       while(getline(iss, token, ',')) {
        result.push_back(token);
       }
    }
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
        cout << "instrucao "<<i+1<<" :\n";
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
void print_ciclo(vector <Instrucao*> instrucoes,int qtdciclo){
    vector<string> etapas = {"IF", "ID", "EX", "MEM", "WB"};
    int aux = 0;
    for(int i =0; i<qtdciclo; i++){
        cout << "--------- ciclo "<<i+1<<" -----------\n";
        for(int j = 0; j<5; j++)
            cout << etapas[j]<< " -- "<< instrucoes[0]->inst << endl;
    }
}
/*
add $t0,$zero,$v0
add $t1,$t0,$t2
sub $s0,$t3,$t1
lw $t4,4($s0)
beq $s0,$t4,9
add $t1,$t2,$t3
lw $t0,128($t1)
lw $t5,128($t1)
lw $t5,128($t1)
*/
void simulator(vector <Instrucao*> instrucoes, int qtd){
    bool dependencia = false;
    int qtdciclo = 5;
    cout << "instruções\n";
    //printa todas as instrucoes
    for(auto ins : instrucoes){
        cout << ins->inst << "\n";
    }

    for(int i =0; i< qtd-1; i++){
        if((instrucoes[i]->opcode == "add" or instrucoes[i]->opcode == "sub") or instrucoes[i]->opcode == "addi"){
            if((instrucoes[i]->op1 == instrucoes[i+1]->op2) or (instrucoes[i]->op1 == instrucoes[i+1]->op3)){
                dependencia = true;
                qtdciclo +=4;
            }else{
                qtdciclo ++;
            }
        }else if(instrucoes[i]->opcode == "lw" or instrucoes[i]->opcode == "sw"){
            if((instrucoes[i]->op1 == instrucoes[i+1]->op2) or (instrucoes[i]->op1 == instrucoes[i+1]->op3)){
                dependencia = true;
                qtdciclo +=4;
            }else{
                qtdciclo ++;
            }
        }else if(instrucoes[i]->opcode == "j"){
            i = stoi(instrucoes[i]->op1)-1;
            qtdciclo++;
        }else{
            qtdciclo +=1;
        }
    }
    print_ciclo(instrucoes, qtdciclo);
}
int main(){
    int qtd;
    cout << "qtd de instrucao:\n";
    cin >> qtd;
    simulator(creatinst(qtd), qtd);

}