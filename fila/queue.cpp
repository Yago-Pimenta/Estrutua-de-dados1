#include <iostream>
#include "queue.h"
using namespace std;

queue::queue()
{
    //setando como zero um valor correspondente ao primeiro e ultimo elemento 
    //lembrando que ao remover um elemento o primeiro recebe um incremento de uma unidade 
    //tal qual ao adicionar um elemento o ultimo recebe o mesmo incremento
    primeiro = 0;
    ultimo = 0;
    vetor = new tipo_da_variavel[max_itens];

}

queue::~queue()
{
    delete[] vetor;
}

bool queue::esta_cheia()
{
    return(ultimo - primeiro == max_itens);
}

bool queue::esta_vazia()
{
    return(primeiro == ultimo);
}

void queue::inserir(tipo_da_variavel item,bool& DeuCerto)
{
    
    if (esta_cheia()) {
        DeuCerto = false ;
    }
    else {
        //ARRAY CIRCULAR , ou seja para eu saber a posição real de tal elemento basta eu fazer essa operação
        //o resto da divisao do ultimo elemento(sempre incrementado de ++1) pelo tamanho do array
        vetor[ultimo % max_itens] = item;
        ultimo++;
        DeuCerto = true ; 
    }
}
void queue::remover(tipo_da_variavel& item,bool& DeuCerto)
{
    if (esta_vazia()) {
        cout << "A fila está vazia!\n";
        DeuCerto = false;
    }
    else {
        primeiro++;
        item =  vetor[(primeiro - 1) % max_itens];
        DeuCerto=true ;
    }
}
void queue::imprimir()
{
    cout << "Fila -> [";
    for (int i = primeiro;i < ultimo;i++) {
        //lembrando como o ultimo elemento pode estar a uma posição a esquerda do elemento primeiro
        //devemos usar sempre o resto da divisao para  encontrarmos a posição correta desse array
        cout << vetor[i % max_itens] << " ";

    }cout << "] " << endl;
}

void queue::qualtamanho(){
        if(esta_vazia()){
            printf("A fila esta vazia\n");
        }else{
             cout << "Essa fila tem : " << ultimo-primeiro << " elementos "<<endl;
        }
}