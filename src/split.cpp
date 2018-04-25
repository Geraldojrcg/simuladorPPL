#include "../include/split.h"
#include <iostream>

string splitInst(const string &inst){
	return inst.substr(0, inst.find_first_of(','));
}
string splitInstLS(const string &inst){
	return inst.substr((inst.find_first_of('(') + 1), 3);
}
void clearinst(Instrucao *instrucoes, int cont){
	string aux;
	for(int i = 0; i < cont ; i++ ) {
		if(instrucoes[i].opcode != "j") {
			aux = splitInst(instrucoes[i].r1);
			instrucoes[i].r1 = aux;
			if((instrucoes[i].opcode =="lw") || (instrucoes[i].opcode == "sw")) {
				aux = splitInstLS(instrucoes[i].r2);
				instrucoes[i].r2 = aux;
			} else {
				aux = splitInst(instrucoes[i].r2);
				instrucoes[i].r2 = aux;

				aux = splitInst(instrucoes[i].r3);
				instrucoes[i].r3 = aux;
			}
		}
	}
}