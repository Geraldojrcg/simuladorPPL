#include "../include/imprime.h"
#include <iostream>
int shift(string *s, int n){
	if(n == 0) {
		return -1;
	}
	s[n] = s[n-1];
	return shift(s, n-1);
}
int qtd_ciclos(Instrucao *instrucao, int cont) {
	int ciclo = 0;
	getCiclo(instrucao, cont);
	ciclo = instrucao[cont - 1].ciclo + 4;
	return ciclo;
}
void print_ciclo(int ciclo, string *print) {
	string stage[] = {"IF", "ID", "EX", "MEM", "WB"};
	cout << "------------------- Ciclo "<< ciclo + 1 <<" ----------------" << endl;
	for(int j = 0; j < 5; j++){
		cout << stage[j] << ": 	"  << print[j] << endl;
	}
}
void simulador(Instrucao *instrucao, int cont) {
	int ciclos = 0, i = 1 , j = 1, var = 0, next = 0, shift_n=4;
	string  print[] = {"0", "0", "0", "0", "0"};
	ciclos = qtd_ciclos(instrucao, cont); /**< Contador de ciclos */
	
	Print_pipeline *print_ppl = new Print_pipeline[ciclos + 1];
	print[0] = instrucao[0].instrucao ;

	for(int k = 0; k < 5; k++)
		print_ppl[0].null_step[k] = print[k];

	cout << "Quantidade Total de Ciclos: " << ciclos + 1 << endl;
	
	print_ciclo(0, print);

	while( i <= ciclos ) {
		if(instrucao[j].opcode == "beq" || instrucao[j].opcode == "bne") {
			int num = stoi(instrucao[j].r3);
			next = num - 1;
			if(instrucao[j].ciclo == i) {
				var = shift(print, shift_n);
				print[0] = instrucao[j].instrucao;
				print_ciclo(i, print);
				if(j < cont)
			 		j = next;
			}else if(instrucao[j].ciclo != i) {
				var = shift(print, shift_n);
				if(var == -1)
					print[0] = "0";
				print_ciclo(i, print);
			}
			for(int k = 0; k < 5; k++)
				print_ppl[i].null_step[k] = print[k];
			i++;
		}else if (instrucao[j].opcode == "j"){
			int num = stoi(instrucao[j].r1);
			next = num - 1;
			if(instrucao[j].ciclo == i) {
				var = shift(print, shift_n);
				print[0] = instrucao[j].instrucao;
				print_ciclo(i, print);
				if(j < cont)
			 		j = next;

			}else if(instrucao[j].ciclo != i) {
				var = shift(print, shift_n);
				if(var == -1)
					print[0] = "0";
				print_ciclo(i, print);
			}
			for(int k = 0; k < 5; k++)
				print_ppl[i].null_step[k] = print[k];
			i++;
		}else {
			if(instrucao[j].ciclo == i) {
				var = shift(print, shift_n);
				print[0] = instrucao[j].instrucao;
				print_ciclo(i, print);
				if(j < cont)
			 		j++;
			} else if(instrucao[j].ciclo != i) {
				var = shift(print, shift_n);
				if(var == -1)
					print[0] = "0";
				print_ciclo(i, print);
			}
			for(int k = 0; k < 5; k++)
				print_ppl[i].null_step[k] = print[k];

			i++;
		}
	}
}