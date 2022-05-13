#include <iostream>
#include <cstddef>
using namespace std;
typedef struct node
{
    int chave;
    struct node *esq;
    struct node *dir;

} Node;
int getAltura(Node *R)
{
    int AlturaEsquerda, AlturaDireita;//é necessário essas variaveis pois a altura de uma parte pode ser maior que a outra


    if (R == NULL)
    {
        //como sugerido pelo enunciado , se ela tiver  vazia vai ser zero 
        return 0;
    }
    else//nao está vazia
    {
        AlturaEsquerda = getAltura(R->esq);
        AlturaDireita = getAltura(R->dir);
        //recursivamente vou calcular as alturas , depois vejo qual altura é maior e retornar esse valor pois a função é int
        if (AlturaEsquerda > AlturaDireita)
        {
            return 1 + AlturaEsquerda;
        }
        else
        {
            return 1 + AlturaDireita;
        }
    }
}