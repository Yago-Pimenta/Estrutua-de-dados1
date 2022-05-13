#include <iostream>
#include "fila1.h"
#include <cstddef>
#include <new>
using namespace std;

fila::fila()
{
primeiro = new Node ;
ultimo = new Node ;
primeiro->dir= primeiro ;
primeiro->esq = primeiro ;
ultimo = primeiro ;
   
}

fila::~fila()
{
    Node* Paux;
    Paux = primeiro ;
    while(Paux!=ultimo){
        Paux = Paux->dir;
        delete Paux->esq ; 
    }
}

bool fila::estacheia()
{
    // para facilitar nao irei colocar exceções por enquanto
    return false;
}

bool fila::estavazia()
{

    return (primeiro == NULL);
}

void fila::imprimir(fila &lista1)
{
    bool TemElemento, Ok;
    TipoItem X;

    cout << "LISTA = [";
    PegaOprimeiro(lista1, X, TemElemento); // pega o primeiro, se existir
    while (TemElemento)
    {
        cout << " " << X;
        PegaOproximo(lista1, X, TemElemento);
    }

    cout << " ";
    cout << "]" << endl;
}

void fila::PegaOprimeiro(fila &lista1, TipoItem &X, bool &DeuCerto)
{

    if (estavazia() == true)
    {
        DeuCerto = false;
    }
    else
    {
        X = primeiro->info;
    }
}
void fila::PegaOproximo(fila &lista1, TipoItem &X, bool &DeuCerto)
{
    Node *Paux;

    Paux = primeiro->dir;
    if (lista1.primeiro == Paux)
    {
        DeuCerto = false;
    }

    else
    {
        DeuCerto = true;
        X = Paux->info;
    }
}
bool fila::estaNalista(fila &lista1, TipoItem &X)
{

    Node *P;
    bool AchouX;
    P = primeiro;
    while (P != ultimo)
    {
        if (P->info == X)
        {
            AchouX = true;
            break;
        }
        P = P->dir;
    }
    if (AchouX != true)
    {
        AchouX = false;
    }
    return AchouX;
}
void fila::InsereADireitadeP(fila &lista1, bool &DeuCerto, TipoItem X)
{
    // aqui vamos fazer para que seja inserido na ultima posição sem misterio
    Node *P = ultimo;
    if (estacheia() == true)
    {
        DeuCerto = false;
    }
    else
    {

        P->esq = ultimo;
        P->dir = NULL;
        ultimo->dir = P;
        ultimo = P;
    }
}

void fila::Retira(fila &lista1, TipoItem &X, bool &OK)
{
    // vamos retirar o primeiro
    Node *P;
    bool achouX;
    // convem ressaltar que poderia usar a subrotina "estanalista" , mas para fins didaticos achei por bem repetir
    //  esse procedimento
    if (lista1.primeiro == NULL) // ou seja a lista está vazia
    {
        achouX = false;
    }
    else
    {
        X = primeiro->info;
        P = primeiro;
        primeiro = primeiro->dir;
        primeiro->esq = NULL;
        delete P;
    }
}
void fila::Insere(fila &lista1, TipoItem &X, bool &DeuCerto)
{
    // vamos querer inserir de forma sem repetição
  //  if (estaNalista(lista1, X) == true)
  //  {
  //      cout << "O elemento  já está na  lista , logo nao foi possivel inseri-lo " << endl;
  //      DeuCerto = false;
  //  }

 //   else
  // {
        cout << "O elemento '"<<X<< "' ainda nao está na lista ,logo irei adiciona-lo"<<endl;
        Node *PAux;
        PAux->info = X;
        
         
        
            
       
            //passo 3 : vamos adicionar no começo mas primeiro basta ver se nao é repetido
            PAux->dir = primeiro ;
            PAux->esq = NULL ;
            primeiro->esq = PAux;
            primeiro = PAux;
        
   // }
}
void fila::uniao(fila &lista1, fila &lista2, fila &lista3)
{
    TipoItem ElementodaFila;
    fila listaAUX;
    bool DeuCerto;
    while (lista1.estavazia() == false)
    {
        // para simplificar o programa nao estou fazendo tratamento de exceçoes
        lista1.Retira(lista1, ElementodaFila, DeuCerto);
        lista3.InsereADireitadeP(lista3, DeuCerto, ElementodaFila);
        listaAUX.InsereADireitadeP(listaAUX, DeuCerto, ElementodaFila);
    }
    while (listaAUX.estavazia() == false)
    {
        listaAUX.Retira(listaAUX, ElementodaFila, DeuCerto);
        lista1.InsereADireitadeP(lista1, DeuCerto, ElementodaFila);
    }
    while (lista2.estavazia() == false)
    {
        lista2.Retira(lista2, ElementodaFila, DeuCerto);
        lista3.InsereADireitadeP(lista3, DeuCerto, ElementodaFila);
        listaAUX.InsereADireitadeP(listaAUX, DeuCerto, ElementodaFila);
    }
    while (listaAUX.estavazia() == false)
    {
        listaAUX.Retira(listaAUX, ElementodaFila, DeuCerto);

        lista2.InsereADireitadeP(lista2, DeuCerto, ElementodaFila);
    }
    // terminamos o procedimento
}