#include <iostream>
#include "1.h"
#include <cstddef>
#include <new>
using namespace std;

int NroPessoasVacinadasOuInfectadas(Lista L1, Lista L2)
{
    bool TemELemento;
    Elemento X;
    int contador = 0;
    // L1 -> Numero de pessoas vacinadas
    // L2 ->  numero de pessoas infectadas
    // considerando que nao ha repetição nessas listas eu pensei em pegar todos elementos de uma lista  e conferir depois com a segunda lista

    // COntando quantos elementos tem na primeira  lista :
    
    PegaOPrimeiro(L1, X, TemElemento);
 
    while (TemElemento)
    {
        contador += 1;
        PegaOProximo(L1, X, TemElemento);
       
    }
 //agora vamos usar esse algoritmo para ver os elementos de L2 que nao estao na lista de L1 e somar eles 


    PegaOPrimeiro(L2, X, TemElemento);
    while (TemElemento == true)
    {
        if (EstaNaLista(L1, X) == false)
        {
            contador += 1;
        }
        PegaOProximo(L2, X, TemElemento);
    }
return contador ;
  
}