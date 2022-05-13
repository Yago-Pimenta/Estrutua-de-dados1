#include <iostream>
#include "1.h"
#include <cstddef>
#include <new>
using namespace std;
//basta arrumar o estavazia , printar situaçõoes fazer desenho e mandar para o pŕof
FILA::FILA()
{
    //lembrando que é uma lista circular entao tem que ser desse jeito a inicialização
    Primeiro = new Node;
    Primeiro->next = Primeiro;
    Primeiro->prev = Primeiro;
    Ultimo = Primeiro;
    
}

FILA::~FILA()
{

    // remove todos os nós da Fila
    bool TemElemento, Ok;
    Elemento X;
    Ultimo = Primeiro;
    if (Ultimo != NULL)
    {
        TemElemento = true;
        X = Ultimo->info;
    }
    else
    {
        TemElemento = false;
    }
    Node *P = new Node;
    // pega o primeiro, se existir
    while (TemElemento)
    {
        if (P != Primeiro)
        {
            P->next->prev = P->prev;
            P->prev->next = P->next;
            delete P;
            P = NULL;
        }
        else
        {
            if (Primeiro->next == Primeiro)
            {
                Primeiro == NULL;

            } // se a lista tem um único nó
            else
            {
                Primeiro = Primeiro->next;
                P->next->prev = P->prev;
                P->prev->next = P->next;
                delete P;
                P = NULL;
            }
        }
        // ao retirar elemento, Ultimo passa para Ultimo->Esq
        if (Ultimo != NULL)
        {
            Ultimo = Ultimo->next;
        }
        if (Ultimo == NULL)
        {
            Ok = false;
        }
        else
        {
            Ok = true;
            X = Ultimo->info;
        }
    }
    delete (Primeiro);
    delete (Ultimo);
    Primeiro = NULL;
    Ultimo = NULL;
    // fim Destroi */
}



bool FILA::vazia()
{
//ERRADO
    return ( Primeiro->next == Primeiro); //vai retornar true caso ela aponte para ela mesma
//OBSERVACAO: Está totalmetne errada , pode ter um elemento , ela vai estar vazia se F.Ultimo==NULL
}


//lembrando que em fila que quem sai primeiro é o primeiro elemento
void FILA::Retira(FILA &F, Elemento &X, bool &OK)
{
    Node *P = new Node; // OBSERVACAO : nao precisa ficar fazendo essa viadagem
    P = Primeiro ; 

    //OBSERVACAO: Eu nao trato o caso em que a fila está vazia
    
            if (F.Primeiro->next == F.Primeiro)
            {
                X = F.Primeiro->info ;
                F.Primeiro == NULL;
                //OBSEVACAO: e quanto ao F.Ultimo? tinha que dar NULL nele tambem

            } // se a lista tem um único nó
            else
            {   
                //caso em que tem mais de um nó
                //OBSERVACAO:  Esta totalmente  errado , vc nunca usou o ponteiro do Ultimo , parece que ele nao serve para nada
                X = F.Primeiro->info;
                F.Primeiro = F.Primeiro->next;
                P->next->prev = P->prev;
                P->prev->next = P->next;
                //Nao devo mecher no ponteiro aux que aponta para o primeiro , pois ele deveria ser deletado depois
            }
        
   
}
//para fins de simulação mantive o Insere , para facilitar tal propósito
//e tambem é crucial pois nesse procedimento irei setar onde o NodePtr Ultimo tem que apotnar
void FILA::Insere(FILA &F, Elemento &X, bool &DeuCerto)
{

   

    //OBSERVAÇÃO : errado pois nao leva em  conta o punhado de casos que tem 
        Node *PAux = new Node;
        if (PAux == NULL)     // se PAux retornar NULL, não há mais memória
            DeuCerto = false; // a operação não deu certo - equivale a fila cheia
        else
        {
            DeuCerto = true;
            PAux->info = X;
            PAux->next = Primeiro->next;
            PAux->prev = Primeiro;
            Primeiro->next->prev = PAux;
            Primeiro->next = PAux;
            Ultimo = PAux ;
            delete PAux ;
        } 
    
}


