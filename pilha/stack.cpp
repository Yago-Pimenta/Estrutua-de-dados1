#include <iostream>
#include "stack.h"
using namespace std;

pilha::pilha()
{
    //aqui estou setando a posição inicial no topo como 0 , pois ela começa vazia
    posicao_Topo = 0;
    // ja esse comando eu inicializei um novo array com a posição maxima de 20 elementos
    //alocados sequencialmetne tal qual o exercicio pede
    vetor = new tipo_da_variavel[max_itens];
}

pilha::~pilha()
{
    // essa função vai deletar o vetor , acabando com a pilha
    delete[] vetor;
}

bool pilha::esta_cheia()
{
    //a pilha está cheia se a posição no topo for igual a 20
    return (posicao_Topo == max_itens);
}

bool pilha::esta_vazia()
{
    // se o valor dessa variavel for 0 significa que a pilha está vazia
    return (posicao_Topo == 0);
}
void pilha::inserir(tipo_da_variavel objeto)
{
    //estou passando um valor por referencia e ele será colocado no topo da pilha
    if (esta_cheia())
    {
        cout << "Lamento, a pilha esta cheia \n Nao eh possivel colocar esse elemento!" << endl;
        DeuCerto = false;
    }
    else
    {
        // com esse comando eu coloco esse objeto no topo do array e avanço a posição_topo em uma unidade
        vetor[posicao_Topo] = objeto;
        posicao_Topo++;
        DeuCerto = true;
    }
}

tipo_da_variavel pilha::remover()
{
    if (esta_vazia())
    {
        cout << "Lamento, a pilha esta vazia \n Nao eh possivel remover esse elemento!" << endl;
        DeuCerto = false;
        return false;
    }
    else
    {
        // basta eu remover uma unidade dessa variavel e retornar a pilha até onde ela vai , ou seja o
        // elemento antigo dela ainda estará lá até eu mandar sobrescrever
        posicao_Topo--;
        return vetor[posicao_Topo];
        DeuCerto = true;
    }
}

void pilha::imprimir()
{ //basta percorrer com um looping o nosso vetor até a posição_topo, evitando que leia lixo
    cout << "Pilha: -> [";
    for (int i = 0; i < posicao_Topo; i++)
    {
        cout << vetor[i] << " ";
    }
    cout << "]" << endl;
}

int pilha::qualtamanho()
{

    return posicao_Topo;
}
