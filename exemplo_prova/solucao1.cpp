// Era uma fial duplamente encadeada e circular com dois ponteiros o FPrimeiro
//  e FUltimo , tenho que aprender a abstrair nao preciso fazer o programa inteiro

#include <iostream>
#include "solucao1.h"
#include <cstddef>
#include <new>
using namespace std;
FILA::FILA()
{
    // lembrando que é uma lista circular entao tem que ser desse jeito a inicialização
    Primeiro = new Node;
    Primeiro->Dir = Primeiro;
    Primeiro->Esq = Primeiro;
    Ultimo = NULL;
    // eu inicializo a fila com os ponteiros apontando para o mesmo lugar
}

bool FILA::Vazia(FILA &F)
{
    if (F.Ultimo == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void FILA::Retira(FILA &F, Elemento &X, bool &Erro)
{
    if (Vazia(F))
    {
        Erro = true;
    }
    else
    {
        Erro = false;
        X = Primeiro->info;
        Node *Aux=new Node;
        Aux = F.Primeiro; // depois basta excluir esse Node para excluir o primeiro
        if (F.Ultimo = F.Ultimo->Dir)
        { // essa fila tem um unico elemento
            F.Ultimo = NULL;
            F.Primeiro = NULL;

        }
        else
        {                                 // se a fila tem mais de um elemento eu vou fazer
            F.Primeiro = F.Primeiro->Dir; // O primeiro agora vai ser o da direita
            F.Ultimo->Dir = F.Primeiro;   // A direita do ultimo agora tem que apontar para o novo primeiro
            F.Primeiro->Esq = F.Ultimo;   // O da esquerda do novo primeiro tem que ser o ultimo
        }
        delete Aux; // basta deletar esse aux para deletar o primeiro
    }
}

void FILA::Destroi(FILA &F)
{ // estamos destuindo sem precisar abrir a TV , como deve ser
    Elemento X;
    bool Erro;
    while (Vazia(F) == false)
    {
        Retira(F, X, Erro);
    }
}

//Arrumando o insere
void FILA::Insere(FILA &F, Elemento &X, bool &DeuCerto)
{

    

//Tenho que declarar o Paux desse jeito ( nao posso esquecer , muito importante)     
        Node *PAux=new Node;
        PAux->info = X;
       // if (PAux == NULL)     // se PAux retornar NULL, não há mais memória
        // DeuCerto = false; // a operação não deu certo - equivale a fila cheia
        if(Vazia(F)){//caso em que a fila está vazia
            
            F.Primeiro = PAux ;
            F.Ultimo = PAux ;
            DeuCerto = true;
            //os doisponteiros estao apotnando para o mesmo elemento
        }
        else{
            //estou adicionando no final
           
            
            PAux->Dir = Primeiro;
            PAux->Esq = Ultimo;
            Ultimo->Dir->Esq = PAux;
            Ultimo->Dir = PAux;
            Primeiro->Esq = PAux;
            Ultimo = PAux ;
            
            DeuCerto = true;
        } 
    
}

void FILA::print(FILA& F){
    Elemento X;
    bool DeuCerto;
    Node* Aux = Primeiro ;
    Node* Aux1;
    cout << "FILA: [ "<<Primeiro->info << " ";
    Aux1=Aux;
    while(Aux!=Primeiro){
        cout << Aux->info << " ";
        Aux1=Aux->Dir;
        Aux=Aux1;
    }
}
FILA::~FILA(){

}