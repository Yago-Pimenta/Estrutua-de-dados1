#include "pessoa.h"
using namespace std;

Pessoa::Pessoa(){
    cpf = 0;
    name = "";
}

Pessoa::Pessoa(int cp, string n)
{
    cpf = cp;
    name = n;
}
string Pessoa::GetName()
{
    return name;
}
int Pessoa::GetCPF()
{
    return cpf;
}