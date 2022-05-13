#include <iostream>
#include "F5.h"
#include <cstddef>
#include <new>
using namespace std;
//antes de começar vamos esclarecer as coisas : 
//Remover: eu irei  remover tal elemento, o programa vai primeiro ele vai percorrer a lista toda quando achar vai remvoer
//adicionar : eu irei inserir o elemento em ordem numérica crescente
linked_list::linked_list()
{
    primeiro = NULL;
    ultimo = NULL;
    //para construirmos vamos setar os dois Node do tipo ponteiro como NULL , ou seja apontando para nada
}

linked_list::~linked_list()
{
    Node *Paux;
    while (primeiro != NULL)
    {
        //enquanto o primeiro elemento da fila nao apontar para null eu vou  fazer meu ponteiro aux
        //apontar para tal "pedaço" e após pegar seu endereço e avançar para o proximo eu deleto esse antigo
        //tenho que apagar um por um
        Paux = primeiro;
        primeiro = primeiro->next;
        delete Paux;
    }
    ultimo = NULL;
}

bool linked_list::estacheia()
{
   // para facilitar nao irei colocar exceções por enquanto
        return false;
    
}

bool linked_list::estavazia()
{
    
    return (primeiro == NULL);
}

void linked_list::inserir(TipoItem item, bool &DeuCerto)
{
    if (estacheia())
    {
        DeuCerto = false;
    }
    else
    {
        //vamos criar um novo nó para poder adicionar o novo elemento
        Node *NodeNovo = new Node;

        NodeNovo->info = item;
        NodeNovo->next = NULL;
        //ele vai entrar por ultimo , logo tem que apontar para o nada (null)
        if (primeiro == NULL)
        {
            primeiro = NodeNovo;
        }
        else if(ultimo->info < item )
        {
            ultimo->next = NodeNovo;
            //estou fazendo o penultimo apontar para o ultimo que to colocando agr
        }else if(ultimo->info > item){
            // ao inves de ir no antipenultimo e mandar ele apontar no novo elemento achei mais facil
            //troca o valor dos dois elementos mechendo apenas no info
            TipoItem aux;
            aux = ultimo->info ;
            ultimo->info = item ;
            NodeNovo->info = aux ;
            ultimo->next = NodeNovo;
            
        }else{
            ultimo->next = NodeNovo;
        }
        ultimo = NodeNovo; //setando que o nó que coloquei agora vai ser o ultimo
        DeuCerto = true;
    }
}

TipoItem linked_list::remover(bool &DeuCerto,TipoItem item)
{
    // vamos partir do princípio de que eu irei fornecer o elemento a ser removido
    if (estavazia())
    {
       
        DeuCerto = false;
        return 0;
    }
    else
    {
        Node *Paux=primeiro;
        Node *Pachei;
        if(item == Paux->info){
            delete Paux;
        }
       // a estrategia aqui foi ter 3 ponteiros um que aponta para o que eu vou remover outro para o antecessor
       //e o outro para o sucessor de tal forma que na hora de excluir o do meio eu irei conectar o antecessor ao
       //sucessor evitando qualquer tipo de problemas  
        Node *Panterior=primeiro;
        while(Panterior != NULL ){
        Paux = Paux -> next ;
            if(item == Paux->info){
                cout << "UAU a lista tem esse elemento , irei remove-lo para vc \n";
                Pachei = Paux->next ;
                Panterior->next = Pachei;
                delete Paux;
                Paux = NULL ;
                DeuCerto = true;
                break;
            }
            Panterior = Panterior->next;
        }
        if(DeuCerto!=true){cout << "Lamento informar , mas esse elemento nao tem na lista"<<endl;
        DeuCerto = false;}
     
       
        return item;
       
    }
}
void linked_list::imprimir()
{
    Node *Paux=primeiro;
    cout << "Fila= [";
    while (Paux != NULL)
    {
        cout << Paux->info << " ";
        Paux = Paux->next;
    }
    cout << "]\n";
}
int linked_list::qualtamanho()
{
    Node *Paux=primeiro;
    int tamanho = 0;
    while (Paux != NULL)
    {
        tamanho++;
        Paux = Paux->next;
    }
   // cout << " tamanaho -> "<<tamanho<<endl;
    return tamanho;
}

