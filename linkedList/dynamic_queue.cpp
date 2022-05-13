#include <iostream>
#include "dynamic_queue.h"
#include <cstddef>
#include <new>
using namespace std;

fila_encadeada::fila_encadeada()
{
    primeiro = NULL;
    ultimo = NULL;
    //para construirmos vamos setar os dois Node do tipo ponteiro como NULL , ou seja apontando para nada
}

fila_encadeada::~fila_encadeada()
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

bool fila_encadeada::estacheia()
{
   
        return false;
    
}

bool fila_encadeada::estavazia()
{
    //por ser fila , o primeiro só aponta para o NULL se a fila tiver vazia , se nao tem um punhado de elemento
    //atrás dela
    return (primeiro == NULL);
}

void fila_encadeada::inserir(TipoItem item, bool &DeuCerto)
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
        else
        {
            ultimo->next = NodeNovo;
            //estou fazendo o penultimo apontar para o ultimo que to colocando agr
        }
        ultimo = NodeNovo; //setando que o nó que coloquei agora vai ser o ultimo
        DeuCerto = true;
    }
}

TipoItem fila_encadeada::remover(bool &DeuCerto)
{
    if (estavazia())
    {
       
        DeuCerto = false;
        return 0;
    }
    else
    {
        Node *Paux=primeiro;
        TipoItem item = primeiro->info;
        // o item(valor que irei retornar ) vai receber o valor do primeiro elemento
        //lembrando que fila quem sai é o primeiro
        primeiro = primeiro->next;
        //meu ponteiro que aponta para o primeiro irá apontar para o segundo elemento
        if (primeiro == NULL)
        {
            ultimo == NULL;
        }
        delete Paux;
        DeuCerto = true;
        return item;
       
    }
}
void fila_encadeada::imprimir()
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
int fila_encadeada::qualtamanho()
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

bool fila_encadeada::Mais_Elementos(fila_encadeada& fila1, fila_encadeada& fila2)
{
    bool deu_certo;
    int elementos_fila, elementos_fila1, elementos_fila2;
    fila_encadeada Paux1, Paxu2;
    // essas duas variaveis auxiliares vai contar quantos elementos tem em cada fila
    int elementos_da_F1 = 0;
    int elementos_da_F2 = 0;

    // pagina 21 do material
    while (fila1.estavazia() == false)
    {
        int elemento_da_fila;
        elemento_da_fila = fila1.remover(deu_certo);
        Paux1.inserir(elemento_da_fila, deu_certo);
        elementos_da_F1 += 1;
        // após desempilhar os elementos para fazer a contagem , precisamos voltar :
    }
    while (Paux1.estavazia() == false)
    {
        int elemento_da_fila;
        elemento_da_fila = Paux1.remover(deu_certo);
        fila1.inserir(elemento_da_fila, deu_certo);

        //voltamos os elementos para a fila original
    }

    while (fila2.estavazia() == false)
    {
        int elemento_da_fila;
        elemento_da_fila = fila2.remover(deu_certo);
        Paxu2.inserir(elemento_da_fila, deu_certo);
        elementos_da_F2 += 1;
        // estamos fazendo o mesmo procedimento igual ao da fila1
    }
    while (Paxu2.estavazia() == false)
    {
        int elemento_da_fila;
        elemento_da_fila = Paxu2.remover(deu_certo);
        fila2.inserir(elemento_da_fila, deu_certo);

        //voltamos os elementos para a fila original
    }
    if (elementos_da_F1 == elementos_da_F2)
    {
        return true;
    }
    else
        return false;
}

void fila_encadeada::Juncao_Elementos(fila_encadeada& fila1, fila_encadeada& fila2,fila_encadeada& fila3)
{
    
    TipoItem ElementodaFila;
    fila_encadeada filaAUX;
    bool DeuCerto;
    while (fila1.estavazia() == false)
    {
        //para simplificar o programa nao estou fazendo tratamento de exceçoes
        ElementodaFila = fila1.remover(DeuCerto);
        fila3.inserir(ElementodaFila, DeuCerto);
        filaAUX.inserir(ElementodaFila, DeuCerto);
    }
    while (filaAUX.estavazia() == false)
    {
        ElementodaFila = filaAUX.remover(DeuCerto);
        fila1.inserir(ElementodaFila, DeuCerto);
    }
    while (fila2.estavazia() == false)
    {
        ElementodaFila = fila2.remover(DeuCerto);
        fila3.inserir(ElementodaFila, DeuCerto);
        filaAUX.inserir(ElementodaFila, DeuCerto);
    }
    while (filaAUX.estavazia() == false)
    {
        ElementodaFila = filaAUX.remover(DeuCerto);

        fila2.inserir(ElementodaFila, DeuCerto);

    }
     //terminamos o procedimento
   
    }
    