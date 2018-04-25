#include "../include/dependencia.h"
void analisedependencia(Instrucao *instrucoes, int cont){
	int numIntrucao = 5;
	limpainstrucao(instrucoes, cont);
	for(int i = 0 ;  i < cont - 1; i++){ //Quantidade de instruções
		for(int j = i + 1 ; j < numIntrucao; j++){ //Verifica as próximas 5 instruções
			if(instrucoes[i].opcode != "j") { //verificando o tipo de instrução
				if(instrucoes[i].opcode == "beq" || instrucoes[i].opcode == "bne") {
					if(instrucoes[j].r1 == instrucoes[i].r1 || instrucoes[j].r2 == instrucoes[i].r1)
						instrucoes[j].dependencia = i;
				} else if(instrucoes[i].opcode == "lw") {
					if(instrucoes[j].r2 == instrucoes[i].r1)
						instrucoes[j].dependencia = i;
				} else if(instrucoes[i].opcode == "sw") {
					if(instrucoes[j].r1 == instrucoes[i].r1)
						instrucoes[j].dependencia = i;
				} else {
					if(instrucoes[j].r2 == instrucoes[i].r1 || instrucoes[j].r3 == instrucoes[i].r1)
						instrucoes[j].dependencia = i;
				}
			}
			if(j >= cont)
				break;
		}
		numIntrucao++;
	}
}
void analiseciclo(Instrucao *instrucoes, int cont) {
	int numIntrucao = 5;
	int ciclo = 0;
	analisedependencia(instrucoes, cont);
	instrucoes[0].ciclo = ciclo;

	for(int i = 0; i < cont - 1; i++){
		for(int j = i + 1; j < numIntrucao; j++) {

			ciclo = instrucoes[i].ciclo;

	 		if(instrucoes[j].dependencia == i) {
 				int n = j - 1;
 				while(n >= i){
 					if(instrucoes[n].dependencia == i) {
 						ciclo += 1;
						instrucoes[j].ciclo = ciclo;
 					} else {
 						ciclo += 4;
						instrucoes[j].ciclo = ciclo;
 					}
 					n--;
 				}
			} else if(instrucoes[j].dependencia == -1) {
				ciclo +=1;
				instrucoes[j].ciclo = ciclo;
			}
			if(j >= cont)
				break;
		}
		numIntrucao++;
	}
}