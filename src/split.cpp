#include "../include/split.h"
#include <iostream>

string splitInstrucao(const string &inst){
	return inst.substr(0, inst.find_first_of(','));
}
string splitInstrucaoStore(const string &inst){
	return inst.substr((inst.find_first_of('(') + 1), 3);
}
void limpainstrucao(Instrucao *instrucoes, int cont){
	string aux;
	for(int i = 0; i < cont ; i++ ) {
		if(instrucoes[i].opcode != "j") {
			aux = splitInstrucao(instrucoes[i].r1);
			instrucoes[i].r1 = aux;
			if((instrucoes[i].opcode =="lw") || (instrucoes[i].opcode == "sw")) {
				aux = splitInstrucaoStore(instrucoes[i].r2);
				instrucoes[i].r2 = aux;
			} else {
				aux = splitInstrucao(instrucoes[i].r2);
				instrucoes[i].r2 = aux;

				aux = splitInstrucao(instrucoes[i].r3);
				instrucoes[i].r3 = aux;
			}
		}
	}
}