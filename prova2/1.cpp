#include <iostream>
#include <cstddef>
using namespace std;
typedef struct node
{
    int chave;
    struct node *esq;
    struct node *dir;

} Node;

void insere(Node *R, int Ch)
{

    if (R != NULL)
    {                      // se a arvore não está vazia
        if (Ch < R->chave) // para eu percorrer o lado esquerdo
        {
            if (R->esq != NULL)
                insere(R->esq, Ch);
            // enquanto meu Ch for menor do que os elementos da esquerda , irei percorrer esse caminho
            else
            {
                // finalmente achei o lugar em que deve ser inserido
                R->esq = new node;
                R->esq->chave = Ch;
                R->esq->esq = NULL;
                R->esq->dir = NULL;

                // foi inserido com sucesso
            }
        }
        else if (Ch > R->chave)
        // aqui vamos percorrer a arvore a direita
        {
            if (R->dir != NULL)
                insere(R->dir, Ch);
            // enquanto meu Ch for maior que os elementos da arvore irei percorrer para direita
            else
            {
                // achei o lugar correto e irei inserir
                R->dir = new node;
                R->dir->chave = Ch;
                R->dir->esq = NULL;
                R->dir->dir = NULL;
            }
        }
    }
    else
    {
        // caso em que a arvore está vazia (R==NULL)
        R = new node;
        R->chave = Ch;
        R->esq = NULL;
        R->dir = NULL;
    }
}





