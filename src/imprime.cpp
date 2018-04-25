#include "../include/imprime.h"
#include <iostream>
int shift(string *v, int n){
	if(n == 0) {
		return -1;
	}
	v[n] = v[n-1];
	return shift(v, n-1);
}
int quantidade_ciclos(Instrucao *instrucoes, int cont) {
	int ciclo = 0;
	analiseciclo(instrucoes, cont);
	ciclo = instrucoes[cont - 1].ciclo + 4;

	return ciclo;
}
void imprimepipe(int ciclo, string *imprime) {
	string stage[] = {"IF", "ID", "EX", "MEM", "WB"};
	cout << "------------------- Ciclo "<< ciclo + 1 <<"----------------" << endl;
	for(int j = 0; j < 5; j++){
		cout << stage[j] << ": 	"  << imprime[j] << endl;
	}
} 
void processapipe(Instrucao *instrucoes, int cont) {
	int ciclos = 0, i = 1 , j = 1, var = 0, next = 0;
	string  print[] = {"0", "0", "0", "0", "0"};
	ciclos = quantidade_ciclos(instrucoes, cont); /**< Contador de ciclos */
	Printpipe *imprime = new Printpipe[ciclos + 1];
	print[0] = instrucoes[0].instrucao ;

	for(int k = 0; k < 5; k++)
		imprime[0].press[k] = print[k];

	cout << "Quantidade Total de Ciclos: " << ciclos + 1 << endl;
	imprimepipe(0, print);
	while( i <= ciclos ) {
		if(instrucoes[j].opcode == "beq" || instrucoes[j].opcode == "bne") {
			int num = stoi(instrucoes[j].r3);
			next = num - 1;
			if(instrucoes[j].ciclo == i) {
				var = shift(print, 4);
				print[0] = instrucoes[j].instrucao;
				imprimepipe(i, print);
				if(j < cont)
			 		j = next;
			} else if(instrucoes[j].ciclo != i) {
				var = shift(print, 4);
				if(var == -1)
					print[0] = "0";
				imprimepipe(i, print);
			}
			for(int k = 0; k < 5; k++)
				imprime[i].press[k] = print[k];
			i++;
		} else if (instrucoes[j].opcode == "j"){
			int num = stoi(instrucoes[j].r1);
			next = num - 1;
			if(instrucoes[j].ciclo == i) {
				var = shift(print, 4);
				print[0] = instrucoes[j].instrucao;
				imprimepipe(i, print);
				if(j < cont)
			 		j = next;

			} else if(instrucoes[j].ciclo != i) {
				var = shift(print, 4);
				if(var == -1)
					print[0] = "0";
				imprimepipe(i, print);
			}
			for(int k = 0; k < 5; k++)
				imprime[i].press[k] = print[k];
			i++;
		} else {
			
			if(instrucoes[j].ciclo == i) {
				var = shift(print, 4);
				print[0] = instrucoes[j].instrucao;
				imprimepipe(i, print);
				if(j < cont)
			 		j++;
			} else if(instrucoes[j].ciclo != i) {
				var = shift(print, 4);
				if(var == -1)
					print[0] = "0";
				imprimepipe(i, print);
			}
			for(int k = 0; k < 5; k++)
				imprime[i].press[k] = print[k];

			i++;

		}
	}
}