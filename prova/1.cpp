#include <iostream>
#include "1.h"
#include <cstddef>
#include <new>
using namespace std;

// trata-se uma lista cadastral nao ordenada , nao circular e com elementos repetidos
void Remove1(NodePtr &L, int &X, bool &Ok)
{
    Paux = new NodePtr;
    Pant = new NodePtr;//vai ser necessario só no caso em que nao for o primeiro 
    // a fim de manter o L apontando sempre para primeira posição
    Paux = L;

    // REMOVENDO O PRIMEIRO
    if (L->info == X)
    {
        Ok = true;

        L = L->next;
        // lembrando que o Paux está apontando para o primeiro
        Paux->next = NULL;
        delete Paux;
    }

    // Agora é interessante eu separar L e Paux , ou seja , o Paux vai ficar um Node a frente
    else
    {   Pant = Paux ;
        Paux = Paux->next;
        while (Paux->info != X && Paux->next != NULL)
        {
            Pant = Paux;
            Paux = Paux->next;
        }
        if (Paux->info == X)
        {
            Ok = true;
            // agora vamos remover ele :
            Pant->next = Paux->next;
            Pant = Paux->next;
            Paux->next = NULL;
            delete Paux;
        }
        else
        {
            Ok = false;
        }
    }
}

// vamos pegar a mesma estrutura da de cima , fazendo algumas modificações
void RemoveTodos(NodePtr &L, int &X, bool &Ok)
{

    int ElementosRemovidos = 0; // para ajudar a setar o valor correto para  Ok

    // esquema para remover o primeiro elemento até ele deixar de ser igual a X

    while (L->info == X)
    {
        Paux = new NodePtr;
        
        Paux = L;

        L = L->next;

        Paux->next = NULL;
        delete Paux;
        ItensRemovidos += 1;
    }
    // Agora é extremamente crucial separar os ponteiros , o Paux estará um Node a frente de Pant
    Paux = new NodePtr;
    Pant = new NodePtr;//necessario para nao tirar o L da primeira  casa
    Pant = L ;
    Paux = Pant->next;
    while (Paux != NULL)
    {
        // caso em que Paux achou X e deve ser removido
        if (Paux->info == X)
        {
            ItensRemovidos += 1;
            // agora vamos remover ele :
            Pant->next = Paux->next;
            Pant = Paux->next;
            Paux->next = NULL;
            delete Paux;
        }

        Pant = Paux;
        Paux = Paux->next;
        // fazemos isso para percorrer  a lista toda
    }

    if (ItensRemovidos == 0)
    {
        Ok = false;
    }
    else
    {
        Ok = true;
    }
}
