#include <string>
using namespace std;
class  Instrucao{
	public:
		string instrucao;
		string opcode;
		string r1;
		string r2;
		string r3;
		int ciclo;
		int dependencia = -1;
};

class Printpipe {
	public:
		string press[5] = {"0", "0", "0", "0", "0"};
};