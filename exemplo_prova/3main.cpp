#include <iostream>
#include "3.h"
using namespace std;
int main(){
int x; 
linked_list lista_original;
linked_list Carrinho_de_compras;


bool DeuCerto;
cin >> x ;
lista_original.Insere_Lista_Original(lista_original,x,DeuCerto);
cin >> x ;
lista_original.Insere_Lista_Original(lista_original,x,DeuCerto);
cin >> x ;
lista_original.Insere_Lista_Original(lista_original,x,DeuCerto);
cout << "VAMOS imprimri a lsita original : "<<endl;
lista_original.imprimir(lista_original);


cout << "Vamos partir para o carrinho de compras"<<endl;;
int d;
cin >> d ;
Carrinho_de_compras.Insere_Carrinho_Compras(Carrinho_de_compras,d,DeuCerto);
cin >> d ;
Carrinho_de_compras.Insere_Carrinho_Compras(Carrinho_de_compras,d,DeuCerto);
cin >> d ;
Carrinho_de_compras.Insere_Carrinho_Compras(Carrinho_de_compras,d,DeuCerto);
cout << "VAMOS imprimri a lsita carrinho de compra : "<<endl;
lista_original.imprimir(lista_original);
int itens_errados = Carrinho_de_compras.ItensCompradosErroneamente(Carrinho_de_compras,lista_original);
cout << " O numero de itens comprados errados sao  : "<<itens_errados <<endl;

    return 0;
}