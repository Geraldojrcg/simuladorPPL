#include "../include/dependencia.h"
void getDependencia(Instrucao *instrucao, int cont){
	int numIntrucao = 5;
	clearinst(instrucao, cont);
	for(int i = 0 ;  i < cont - 1; i++){
		for(int j = i + 1 ; j < numIntrucao; j++){
			if(instrucao[i].opcode != "j") {
				if(instrucao[i].opcode == "beq" || instrucao[i].opcode == "bne") {
					if(instrucao[j].r1 == instrucao[i].r1 || instrucao[j].r2 == instrucao[i].r1)
						instrucao[j].dependencia = i;
				} else if(instrucao[i].opcode == "lw") {
					if(instrucao[j].r2 == instrucao[i].r1)
						instrucao[j].dependencia = i;
				} else if(instrucao[i].opcode == "sw") {
					if(instrucao[j].r1 == instrucao[i].r1)
						instrucao[j].dependencia = i;
				} else {
					if(instrucao[j].r2 == instrucao[i].r1 || instrucao[j].r3 == instrucao[i].r1)
						instrucao[j].dependencia = i;
				}
			}
			if(j >= cont)
				break;
		}
		numIntrucao++;
	}
}
void getCiclo(Instrucao *instrucao, int cont) {
	int numIntrucao = 5;
	int ciclo = 0;
	getDependencia(instrucao, cont);
	instrucao[0].ciclo = ciclo;

	for(int i = 0; i < cont - 1; i++){
		for(int j = i + 1; j < numIntrucao; j++) {
			ciclo = instrucao[i].ciclo;
	 		if(instrucao[j].dependencia == i) {
 				int n = j - 1;
 				while(n >= i){
 					if(instrucao[n].dependencia == i) {
 						ciclo += 1;
						instrucao[j].ciclo = ciclo;
 					} else {
 						ciclo += 4;
						instrucao[j].ciclo = ciclo;
 					}
 					n--;
 				}
			}else if(instrucao[j].dependencia == -1) {
				ciclo ++;
				instrucao[j].ciclo = ciclo;
			}
			if(j >= cont)
				break;
		}
		numIntrucao++;
	}
}