#include "../include/imprime.h"
#include <iostream>
#include <fstream>

using std::ifstream;

void load_inst(){
    string lines_imput;
	int cont = 0;
	ifstream imput;
	imput.open("imput.txt");
	if(!imput) {
		cout << "Erro ao abrir arquivo de instruções!!" << endl;
		exit(0);
	}
	while(getline(imput, lines_imput)){
		cont++;
	}
	
	Instrucao *instrucao = new Instrucao[cont];
	
	imput.clear();
	imput.seekg(imput.beg);
	for(int i = 0; i < cont; i++){
		getline(imput, instrucao[i].instrucao);
	}
	imput.clear();
	imput.seekg(imput.beg);
	for(int i = 0; i < cont; i++) {
		imput >> instrucao[i].opcode;
		if((instrucao[i].opcode =="lw") || (instrucao[i].opcode == "sw")) {
			imput >> instrucao[i].r1;
			imput >> instrucao[i].r2;
		}else if(instrucao[i].opcode == "j") {
		    imput >> instrucao[i].r1;
	    }else{
			imput >> instrucao[i].r1;
			imput >> instrucao[i].r2;
			imput >> instrucao[i].r3;
		}
	}
	//rodando o simulador
	simulador(instrucao, cont);
	imput.close();
	delete[] instrucao;
}
int main() {
	load_inst();
	return 0;
}