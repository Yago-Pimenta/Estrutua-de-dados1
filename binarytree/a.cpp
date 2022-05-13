#include <iostream>
#include <cstddef>
#include "a.h"
#include <new>
#include <string>
using namespace std;
Node::Node(){
    cpf = 0;
    esq = NULL ;
    dir = NULL ;
}
Node::Node(int cpf){
    this->cpf = cpf ;
    this->dir = NULL ;
    this->esq = NULL ;
}
Node::~Node(){

}
BinaryTree::BinaryTree()
{
    raiz = NULL;
    
}
BinaryTree::~BinaryTree()
{
    deletar(*raiz);
}
void BinaryTree::deletar( Node& Atual)
{
 
        // função recursiva
        deletar(*Atual.esq);
        deletar(*Atual.dir);
        
    
}
Node *BinaryTree::obterRaiz()
{
    return raiz;
}
bool BinaryTree::estavazio()
{
    return (raiz == NULL);
}
bool BinaryTree::estacheio()
{
    // nao vou fazer tratamento de exceções
    return false;
}

void BinaryTree::inserir(Node *temp,int cpf, bool &ok)
{
    // na main na hora de declarar o node temp vc tem que setar ele para apontar na raiz
    // se a arvore tiver vazia
        Node Aux;
   
        Aux.cpf = cpf ;
        
        Aux.dir = NULL ;
        Aux.esq = NULL ;

    if(raiz==NULL){
        *raiz =  Aux ;
    }
    else if (temp == NULL)
    {
       
        


        *temp = Aux;

        ok = true;
    }

    else
    {

        // decalrei esse node para percorrer a arvore e achar o lugar correto de isnerir

        if (cpf == temp->cpf)
        {
            ok = false; // ja está na lista e nao pode repetir
        }
        else if (temp->cpf > cpf)
        {
            inserir(temp->esq, cpf, ok);
        }
        else
        {
            inserir(temp->dir, cpf, ok);
        }
    }
}

void BinaryTree::remove(Node *R, int& cpf, bool &ok)
{

    if (R == NULL)
    {
        ok = false; // caso se a arvore tiver vazia
    }
    else
    {
        if (R->cpf > cpf)
        {
            remove(R->esq, cpf, ok);
        }
        else if (R->cpf < cpf)
        { // eses dois if serve para eu achar o elemento
            remove(R->dir, cpf, ok);
        }
        else
        {
            // caso em que encontrou :
            Node *Aux = R;
            ok = true;
            if (R->dir == NULL && R->esq == NULL)
            {
                // caso em que NAO tem filhos
                delete Aux;
                R = NULL;
            }
            else if (R->dir != NULL && R->esq != NULL)
            {
                // caso em qeu tem dois filhos

                // resumindo vai um para esquerda e o resto o maximo possivel a direita
                Aux = R->esq;
                while (Aux->dir != NULL)
                {
                    Aux = Aux->dir;
                }
                // agora que achamos , vamos substituir o R->info(o que queremos eliminar) pelo do aux
                R->cpf = Aux->cpf;

                // agora precisamos remover o elemento remetido , que ficou la em baixo
                remove(R->esq, R->cpf, ok);
                // unica recursao usada para remover
            }
            else
            {
                // caso em que vai ter um unico filho
                if (R->esq == NULL)
                {
                    R = R->dir;
                }
                else
                {
                    R = R->esq;
                }
                delete Aux;
            }
        }
    }
}
bool BinaryTree::EstaNaArvore(Node *R,int& cpf)
{

    if (estavazio())
    {
        return false;
    }
    else if (cpf == R->cpf)
    {
        return true;
    }
    else if (R->cpf > cpf)
    {
        return (EstaNaArvore(R->esq, cpf));
    }
    else
    {
        return (EstaNaArvore(R->dir, cpf));
    }
}

void BinaryTree::imprimirPreOrdem(Node *Atual)
{
    // recursivo tambem
    // nesse vamos imprimir todos elementos partindo da raiz e indo para esqeurda
    if (Atual != NULL)
    {
        
        cout << Atual->cpf << endl;

        imprimirPreOrdem(Atual->esq);
        imprimirPreOrdem(Atual->dir);
    }
}
void BinaryTree::imprimirEMOrdem(Node *Atual)
{
    // imprime em ordem crescente
    if (Atual != NULL)
    {
        imprimirEMOrdem(Atual->esq);
        
        cout << Atual->cpf << endl;
        imprimirEMOrdem(Atual->dir);
    }
}
void BinaryTree::imprimirPOSOrdem(Node *Atual)
{
    if (Atual != NULL)
    {
        // nesse vamos imprimir as folhas primeiro
        imprimirPOSOrdem(Atual->esq);
        imprimirPOSOrdem(Atual->dir);
       
        cout << Atual->cpf << endl;
    }
}

// exercícios extras
int BinaryTree::soma(Node *R)
{
    if (R == NULL)
    {
        // a arvore tiver vazia
        return 0;
    }
    else
    {
        return (R->cpf + soma(R->esq) + soma(R->dir));
    }
}

int BinaryTree::altura(Node *R)
{
    int AlturaEsq, AlturaDir;
    if (R == NULL)
    {
        return 0;
    }
    else
    {
        AlturaEsq = altura(R->esq);
        AlturaDir = altura(R->dir);
        if (AlturaEsq > AlturaDir)
        {
            return 1 + AlturaEsq;
        }
        else
        {
            return 1 + AlturaDir;
        }
    }
}
bool BinaryTree::temAlguemMaior(Node *R, int cpf)
{
    if (R == NULL)
    {
        return false;
    }
    else if (R->cpf > cpf)
    {
        return true;
    }
    else
    {
        return (temAlguemMaior(R->esq, cpf) || temAlguemMaior(R->dir, cpf));
    }
}
bool BinaryTree::temAlguemMenor(Node *R,int cpf)
{
    if (R == NULL)
    {
        return false;
    }
    else if (R->cpf < cpf)
    {
        return true;
    }
    else
    {
        return (temAlguemMenor(R->esq, cpf) || temAlguemMenor(R->dir, cpf));
    }
}