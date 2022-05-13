#include <iostream>
#include "2.h"
using namespace std;
int main()
{
    fila_encadeada fila;

    fila.inserir(22);
    fila.inserir(2);
    fila.inserir(14);
    fila.inserir(32);
    fila.inserir(7);
    fila.inserir(14);
    fila.inserir(73);
    fila.inserir(7);
    fila.imprimir();

    fila.~fila_encadeada();
    return 0;
}