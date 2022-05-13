#include <iostream>
#include "3.h"
#include <cstddef>
#include <new>
using namespace std;
int tamanho = 0;
// basta arrumar o estavazia , printar situaçõoes fazer desenho e mandar para o pŕof
linked_list::linked_list()
{
    // lembrando que é uma lista circular entao tem que ser desse jeito a inicialização
    Header = new Node;
    Header->next = Header;
    Header->prev = Header;
    Atual = Header;
}

linked_list::~linked_list()
{

    // remove todos os nós da Fila
    bool TemElemento, Ok;
    Elemento X;
    Atual = Header;
    if (Atual != NULL)
    {
        TemElemento = true;
        X = Atual->info;
    }
    else
    {
        TemElemento = false;
    }
    Node *P = new Node;
    // pega o primeiro, se existir
    while (TemElemento)
    {
        if (P != Header)
        {
            P->next->prev = P->prev;
            P->prev->next = P->next;
            delete P;
            P = NULL;
        }
        else
        {
            if (Header->next == Header)
            {
                Header == NULL;

            } // se a lista tem um único nó
            else
            {
                Header = Header->next;
                P->next->prev = P->prev;
                P->prev->next = P->next;
                delete P;
                P = NULL;
            }
        }
        // ao retirar elemento, Atual passa para Atual->Esq
        if (Atual != NULL)
        {
            Atual = Atual->next;
        }
        if (Atual == NULL)
        {
            Ok = false;
        }
        else
        {
            Ok = true;
            X = Atual->info;
        }
    }
    delete (Header);
    Header = NULL;
    Atual = NULL;
    // fim Destroi */
}

bool linked_list::estacheia()
{
    // para facilitar nao irei colocar exceções por enquanto
    return false;
}

bool linked_list::estavazia()
{

    return (Header->next == Header);
}

void linked_list::imprimir(linked_list &lista1)
{
    bool TemElemento, Ok;
    Elemento X;

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
int linked_list::qualtamanho(linked_list &lista1)
{

    Elemento X;
    bool DeuCerto;
    PegaOprimeiro(lista1, X, DeuCerto);
    Elemento valor;
    valor = X;
    int tamanho = 0;
    // basicamente peguei o mesmo programa do de cima e irei contar as vezes que vai percorrer

    PegaOproximo(lista1, X, DeuCerto);
    while (X != valor)
    {

        tamanho += 1;
        PegaOproximo(lista1, X, DeuCerto);
    }
    return tamanho;
}

void linked_list::PegaOprimeiro(linked_list &lista1, Elemento &X, bool &DeuCerto)
{

    lista1.Atual = lista1.Header->next;
    if (lista1.Atual != lista1.Header)
    {
        DeuCerto = true;
        X = lista1.Atual->info;
    }
    else
    {
        DeuCerto = false;
    }
}
void linked_list::PegaOproximo(linked_list &lista1, Elemento &X, bool &DeuCerto)
{
    lista1.Atual = lista1.Atual->next;
    if (lista1.Atual == lista1.Header)
    {
        DeuCerto = false;
    }

    else
    {
        DeuCerto = true;
        X = lista1.Atual->info;
    }
}
bool linked_list::estaNalista(linked_list &lista1, Elemento &X)
{

    Node *P;
    bool AchouX;
    P = Header->next; // P é um ponteiro auxiliar que percorre a Lista
    Header->info = X;
    // atribuição de X ao Nó Header, apenas para auxiliar na busca
    while (P->info != X)
        P = P->next;
    if (P != Header)
        AchouX = true;
    // achamos um X armazenado na Lista
    else
        AchouX = false;

    return AchouX;
}
void linked_list::InsereADireitadeP(linked_list &lista1, bool &DeuCerto, Elemento X)
{
    Node *P;
    if (estacheia() == true)
    {
        DeuCerto = false;
    }
    else
    {
        Node *PAux = new Node;

        PAux->info = X;
        PAux->next = P->next;
        PAux->prev = P;
        P->next->prev = PAux;
        P->next = PAux;
    }
}

void linked_list::Retira(linked_list &lista1, Elemento &X, bool &OK)
{
    Node *P = new Node;
    bool achouX;
    // convem ressaltar que poderia usar a subrotina "estanalista" , mas para fins didaticos achei por bem repetir
    //  esse procedimento
    if (lista1.Header == NULL)
    {
        achouX = false;
    }
    else
    {
        P = lista1.Header->next;
        while ((P->info != X) && (P != lista1.Header))
            P = P->next;
        if (P->info == X)
        {
            achouX = true;
        }
        else
        {
        }
    }
    // agora vamos remover de fato
    if (achouX == true)
    {
        if (P != lista1.Header)
        {
            P->next->prev = P->prev;
            P->prev->next = P->next;
        }
        else
        {
            if (lista1.Header->next == lista1.Header)
            {
                lista1.Header == NULL;

            } // se a lista tem um único nó
            else
            {
                lista1.Header = lista1.Header->next;
                P->next->prev = P->prev;
                P->prev->next = P->next;
            }
        }
    }
}
void linked_list::Insere_Lista_Original(linked_list &lista1, Elemento &X, bool &DeuCerto)
{

    if (estaNalista(lista1, X) == true)
        DeuCerto = false;
    else
    {
        Node *PAux = new Node;
        if (PAux == NULL)     // se PAux retornar NULL, não há mais memória
            DeuCerto = false; // a operação não deu certo - equivale a fila cheia
        else
        {
            DeuCerto = true;
            PAux->info = X;
            PAux->next = Header->next;
            PAux->prev = Header;
            Header->next->prev = PAux;
            Header->next = PAux;
           tamanho +=1;
        } 
    }
}
void linked_list::Insere_Carrinho_Compras(linked_list &lista1, Elemento &X, bool &DeuCerto)
{

    if (estaNalista(lista1, X) == true)
        DeuCerto = false;
    else
    {
        Node *PAux = new Node;
        if (PAux == NULL)     // se PAux retornar NULL, não há mais memória
            DeuCerto = false; // a operação não deu certo - equivale a fila cheia
        else
        {
            DeuCerto = true;
            PAux->info = X;
            PAux->next = Header->next;
            PAux->prev = Header;
            Header->next->prev = PAux;
            Header->next = PAux;
           
        } 
    }
}

int linked_list::ItensCompradosErroneamente(linked_list &Carrinho_de_Compras, linked_list &Lista_De_Compras_ori)
{
    // Minha ideia é a seguinte : irei usar dois whiles para percorrer as duas listas , irei verificar
    //  se tal elemento da lista de compras está no carrinho de compras se tiver irei incrementar 1
    // para retornar os itens errados irei fazer o size da lista menos os itens_iguais

    //ERRADO
    //Observação : É muita gambiarra essa solução que eu fiz e vai contra os principios da atividade
    //Sugestao : Basta implementar a função Hash -> EstáNaLista que retorna se um elemento está ou nao na lista
    //para isso eu pego todos elementos do carrinho de compras e vejo se está na lista original se nao tiver incremeneto no contador
    int itens_iguais = 0;
    bool TemElemento1, TemElemento2;
    Elemento X, Y;
    PegaOprimeiro(Lista_De_Compras_ori, Y, TemElemento2);
    while (TemElemento2)
    {
//ISSO gasta muita memoria e nao é nem um  pouco necessario
        PegaOprimeiro(Carrinho_de_Compras, X, TemElemento1); // pega o primeiro, se existir

        while (TemElemento1)
        {
            if (X == Y)
            {
                itens_iguais += 1;
            }
            PegaOproximo(Carrinho_de_Compras, X, TemElemento1);
        }
        PegaOproximo(Lista_De_Compras_ori,Y,TemElemento2);
    }
    return  tamanho- itens_iguais ;
}
