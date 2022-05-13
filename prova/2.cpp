#include <iostream>
#include "2.h"
#include <cstddef>
#include <new>
using namespace std;

//Meu nome Comoeça com Y , logo foi inserido a,b,c nessa ordem com C no topo
bool Vazia(Pilha& P){
    if(P.Header==P.Header->dir){
        return true;
    }else  return false ;
}

void Empilha(Pilha& P , Elemento& X){
    //Header vai ficar sempre acima do topo , entao  o esq dele  aponta para o topo(CABEÇA) e o dir aponta para o começo(RABO): 

    Node* Paux = new Node ;
    Paux->info = X ;
    // Caso 1 - A fila está vazia : 
    if(Vazia(P)==true){
        P.Header->dir = Paux ;
        P.Header->esq = Paux ;
        Paux->dir = P.Header;
        Paux->esq = P.Header ;
    }else{
        //Caso 2 - A fila tem mais de um elemento e devemos coloca-la no Topo (Do lado do Header)
        //vamos fazer com que o antigo ultimo aponte para o novo ultimo e vice versa
        P.Header->esq->dir = Paux ; 
        Paux->esq = P.Header->esq ;
        Paux->dir = P.Header;
        P.Header->esq = Paux;
        

    }
}