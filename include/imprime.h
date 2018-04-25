#include "dependencia.h"
#include <fstream>
using std::ofstream;

void processapipe(Instrucao *instrucoes, int cont);
int shift(string *v, int n);
int quantidade_ciclos(Instrucao *instrucoes, int cont);
void imprimepipe(int ciclo, string *imprime) ;
void escrever(int ciclos, Printpipe *imprime);
