#include "dependencia.h"
#include <fstream>
using std::ofstream;

void simulador(Instrucao *ins, int cont);
int shift(string *s, int n);
int quantidade_ciclos(Instrucao *ins, int cont);
void imprime_ciclo(int ciclo, string *print) ;