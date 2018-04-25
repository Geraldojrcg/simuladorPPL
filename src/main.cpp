#include "../include/imprime.h"
#include <iostream>
#include <fstream>

using std::ifstream;

int main() {
	string linha_instrucao;
	int cont = 0;
	ifstream entrada;
	entrada.open("imput.txt");
	if(!entrada) {
		cout << "Arquivo de instruções inválido!" << endl;
		return 0;
	}
	while(getline(entrada, linha_instrucao)) {
		cont++;
	}
	Instrucao *instrucoes = new Instrucao[cont];

	entrada.clear();
	entrada.seekg(entrada.beg);
	for(int i = 0; i < cont; i++) {
		getline(entrada, instrucoes[i].instrucao);
	}
	entrada.clear();
	entrada.seekg(entrada.beg);
	for(int i = 0; i < cont; i++) {
		entrada >> instrucoes[i].opcode;
		if((instrucoes[i].opcode =="lw") || (instrucoes[i].opcode == "sw")) {
			entrada >> instrucoes[i].r1;
			entrada >> instrucoes[i].r2;
		} else if(instrucoes[i].opcode == "j") {
		         	entrada >> instrucoes[i].r1;
	     	} else {
			entrada >> instrucoes[i].r1;
			entrada >> instrucoes[i].r2;
			entrada >> instrucoes[i].r3;
		}
	}
	processapipe(instrucoes, cont);
	entrada.close();
	delete[] instrucoes;

	return 0;
}