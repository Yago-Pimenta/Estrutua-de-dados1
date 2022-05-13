#include <iostream>
#include "fila1.h"
using namespace std;
int main(){
fila lista;
char X;
bool OK;
cin >> X ;
// arrumar o insere
lista.Insere(lista,X,OK);
lista.imprimir(lista);
cin >> X ;
lista.Insere(lista,X,OK);
cin >> X ;
lista.Insere(lista,X,OK);
cout << " para ver se está na lista : "<<endl;
cin >> X ;
lista.estaNalista(lista,X);
cout << "vamos remover :"<<endl;
lista.Retira(lista,X,OK);
lista.imprimir(lista);
lista.~fila();
    return 0;
}