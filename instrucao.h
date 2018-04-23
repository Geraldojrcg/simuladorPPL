#include <string>
using namespace std;
class Instrucao{
    public:
    string inst;
    string opcode;
    string op1;
    string op2;
    string op3;
    Instrucao(string inst, string opcode, string op1, string op2, string op3);
};