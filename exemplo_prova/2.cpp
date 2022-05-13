#include <iostream>
#include "2.h"
#include <cstddef>
#include <new>
using namespace std;

//OBSERVAO 1 : Eu implementei uma lista com dois ponteiros e nao com apenas com conforme o sugerido

fila_encadeada::fila_encadeada()
{
    FV = NULL;
    ultimo = NULL; // isso nao deveria existir
    //para construirmos vamos setar os dois Node do tipo ponteiro como NULL , ou seja apontando para nada
}

fila_encadeada::~fila_encadeada()
{
    Node *Paux;
    while (FV != NULL)
    {
        //OBSERVACAO :  esse perdaço está certo

        //enquanto o primeiro elemento da fila nao apontar para null eu vou  fazer meu ponteiro aux
        //apontar para tal "pedaço" e após pegar seu endereço e avançar para o proximo eu deleto esse antigo
        //tenho que apagar um por um
        Paux = FV;
        FV = FV->next;
        delete Paux;
    }
    ultimo = NULL;
}



bool fila_encadeada::estavazia()
{
    //OBSERVACAO :  esse perdaço está certo
    //por ser fila , o primeiro só aponta para o NULL se a fila tiver vazia , se nao tem um punhado de elemento
    //atrás dela
    return (FV == NULL);
}

void fila_encadeada::inserir(int item)
{
    //vamos inserir com ordenação  para isso vamos considerar 4 situações

    // 1 - A fila está vazia
    // 2 -  O item é menor que o ultimo elemento portanto vamos inserir no final da fila
    // 3 - O item é maior que o primeiro elemento e assim iremos inserir no começo da fila
    // 4 - Vamos ter que inserir ele no meio da fila , ordenando 
   
    
        //vamos criar um novo nó para poder adicionar o novo elemento
        Node *NodeNovo = new Node;
        Node *NodeAux = new Node;
        if(NodeNovo){
            //se a memoria nao estiver cheia é pq deu certo de acrescentar
            NodeNovo->idade = item;
            //1 situação ( fila vazia )
            if(FV == NULL){
                //ERRO
                NodeNovo->next = NULL ; // OBSERVACAO :  Ja está totalmente errado , por ser circular deveria apontar para ele proprio
                //deveria ter duas linhas de codigo , uma garantindo que apontasse para si proprio e outra designandno o Fv para essa posição
                ultimo = NodeNovo;
                ultimo->next = NULL ;
                FV = NodeNovo;
                //nesse caso FV(primeiro) e o ultimo estao apontando para o mesmo elemento
            }
            // 2 situação -> inserir um numero menor que o ultimo (final da fila)
            //OBSERVACAO DEVERIA SER QUANDO A LISTA TEM APENAS 1 ELEMENTO
            else if(NodeNovo->idade < ultimo->idade){ 
                //como nao tem dois ponteiros na solução correta o certo era declarar um novo ponteiro que apotna para FV
                //ele vai percorrer toda a lista com while(Ant->next!=FV)
                //OBSERVACAO :  depois disso bastaria que setasse novos Ant->next e Paux->next
                NodeNovo->next = NULL;
                ultimo->next = NodeNovo ;
                ultimo = NodeNovo ; 
            }
            // 3 situação -> inseir um numero maior que o primeiro elemento 
            //OBSERVACAO :  em uma lista circular  a diferença para o passo 2 e 3 sao irrisorias , bastaria setar o FV novamente
            else if(NodeNovo->idade > FV->idade){
            NodeNovo->next = FV;
            FV = NodeNovo;

            // 4 sitaução -> caso em que temos que ordenar no meio da fila 
            }else{
                NodeAux = FV ;
                //OBSERVACAO : Solucao usada foi ter dois ponterios um atras do outro 
                while(NodeAux->next && NodeNovo->idade < NodeAux->next->idade )
                NodeAux = NodeAux->next ; 
                NodeNovo->next = NodeAux->next;
                NodeAux->next = NodeNovo ;
            }
        }

    
    
}


void fila_encadeada::imprimir()
{
  
    Node* Paux = FV ;
    cout << "Fila= [";
    while (Paux != NULL)
    {
        cout << Paux->idade << " ";
        Paux = Paux->next;
    }
    cout << "]\n";
    
}


