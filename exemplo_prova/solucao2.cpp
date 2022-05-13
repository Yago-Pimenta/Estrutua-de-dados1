#include <iostream>
#include "solucao2.h"
#include <cstddef>
#include <new>
using namespace std;
//nao tem como testar pq nao tem construtor print etc ...
//fazendo construtor
FILA::FILA(){
    FV = new Node;
    FV->next = FV;
    FV->ant = FV;
    
}
FILA::~FILA(){

}
void FILA::imprimir(FILA& FilaDeVacinacao){
      int X = FV->info ; 
      int J ; 
      cout << "Fila = [ " ;
      while(J != X){
          Remover(FilaDeVacinacao,J);
        cout << J << " ";  
          Insere(FilaDeVacinacao,J);
      }cout << J << "]"<< endl ; 
}



void FILA::Insere(FILA &FilaDeVacinacao, int idade)
{
    Node *PAux;
    Node *P;
    Node *Ant;
    PAux = new Node;
    PAux->info = idade; //  Primeira parte , estou atribuindo o campo info do novo node com o valor idade , que foi passado

    if (FV == NULL)//no meu construtor devo setar esse ponteiro como NULL
    { // caso 1 - Lista vazia
        PAux->next = PAux;
        FV = PAux;
        // se a lista tiver vazia ele deve apontar para ele mesmo pois está vazia e depois o FV aponta para ele
    }

    else if (FV = FV->next) // para ter um unico elemento ele tem que apontar para ele memso
    { // caso 2 - Tem um unico elemento
        PAux->next = FV; // o que eu estou adicionando tem que apontar para o primeiro 
        FV->next = PAux; // nesse caso o primeiro tem que apontar para o segundo (to adicioandno agora)
        if (idade > FV->info)
        {
            FV = PAux; // caso 2A - FV passa a apontar para um novo nó
            //para ordenadar na ordem decrescente , como é cicular nao importa que o primeiro esteja na segudna posição
        }
    }
    else if (idade > FV->info) // vamos estar inserindo no final
    {             // caso 3 - varios elementos , e idade maior que todos(vamos ter um novo FV)
        Ant = FV; // vou inserir esse novo elemento a esquerda de FV
        while (Ant->next != FV)
        { // posiciona ant no ultimo nó
            Ant = Ant->next;
            //Maneira elegante de percorrer toda lista
        }
        PAux->next = FV;
        Ant->next = PAux;
        FV = PAux;
    }
    else
    { // inseir no meio da lista
        Ant = FV;
        P = FV->next;
        while(P != FV && P->info >= idade)
        {
            Ant = P;
            P = P->next;
        }
        Ant->next = PAux;
        PAux->next = P;
    }
}





//vou fazer o mesmo exercicio so que para duplamente encaddeada agora
void FILA::Insere(FILA &FilaDeVacinacao, int idade)
{
    Node *PAux;
    Node *P;
    Node *Ant;
    PAux = new Node;
    PAux->info = idade; //  Primeira parte , estou atribuindo o campo info do novo node com o valor idade , que foi passado

    if (FV == nullptr)//no meu construtor devo setar esse ponteiro como NULL
    { // caso 1 - Lista vazia
        PAux->next = PAux;
        PAux->ant = PAux;
        FV = PAux;
        // se a lista tiver vazia ele deve apontar para ele mesmo pois está vazia e depois o FV aponta para ele
    }

    else if (FV = FV->next) // para ter um unico elemento ele tem que apontar para ele memso
    { // caso 2 - Tem um unico elemento
        PAux->next = FV; // o que eu estou adicionando tem que apontar para o primeiro 
        PAux->ant = FV;
        FV->next = PAux; // nesse caso o primeiro tem que apontar para o segundo (to adicioandno agora)
        FV->ant = PAux;
        if (idade > FV->info)
        {
            FV = PAux; // caso 2A - FV passa a apontar para um novo nó
            //para ordenadar na ordem decrescente , como é cicular nao importa que o primeiro esteja na segudna posição
        }
    }
    else if (idade > FV->info) // vamos estar inserindo no final(novo começo)
    {             // caso 3 - varios elementos , e idade maior que todos(vamos ter um novo FV)
        Ant = FV; // vou inserir esse novo elemento a esquerda de FV
        while (Ant->next != FV)
        { // posiciona ant no ultimo nó
            Ant = Ant->next;
            //Maneira elegante de percorrer toda lista
        }
        PAux->next = FV;
        PAux->ant = Ant;
        Ant->next = PAux;
        FV->ant=PAux ; 
        FV = PAux;
    }
    else
    { // inseir no meio da lista
        Ant = FV;
        P = FV->next;
        while(P != FV && P->info >= idade)
        {
            Ant = P;
            P = P->next;
        }
        Ant->next = PAux;
        PAux->ant = Ant;
        PAux->next = P;
        P->ant = PAux ;
    }
}

//Quero remover o primeiro elemento dessa fila
void FILA::Remover(FILA& FilaDeVacinacao,int& idade){
    //no caso irei remover o elemento mais velho
    idade = FV->info ; 
    Node* Paux;
    
    Paux = new Node ;

    Paux = FV ;
    FV = FV->next ;
    FV->ant->next = FV ;
    FV->ant = Paux->ant ;
    delete Paux;

}