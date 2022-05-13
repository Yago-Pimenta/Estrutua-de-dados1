#include <iostream>
using namespace std;

class Pessoa
{
public:
    Pessoa();
    Pessoa(int cp, string n);
    string GetName();
    int GetCPF();


    int cpf;
    string name;
};