#include <iostream>
#include "F5.h"
using namespace std;
// As duas operações não primitivas que usei foi qualtamanho e o print


int main(){
linked_list lista1,lista2;
int opcao,variavel_controle;
TipoItem item,objeto ;
int item1;
bool DeuCerto;
int tamanho;
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "Bem Vindo a Lista 1  , por favor , digite alugma opcao do menu:\n";
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

    do {
        cout << "Digite 0 para parar o programa\n";
        cout << "Digite 1 para inserir um elemento\n";
        cout << "Digite 2 para remover um elemento\n";
        cout << "Digite 3 para ver se a lista está cheia \n";
        cout << "Digite 4 para ver se a lista está vazia\n";
        cout << "Digite 5 para saber o tamanho da lista\n";
        cin >> opcao;

        if (opcao == 1) {
            cout << "Digite o elemento a ser inserido\n";
            cin >> item;
            lista1.inserir(item,DeuCerto);
             if(DeuCerto==true){cout << "Elemento inserido com sucesso : " << item << endl;}
        else{ cout << " NAo foi possível  inserir tal elemento"<<endl;}
        }
        else if (opcao == 2) {
            cin >> item ;
            item1 = lista1.remover(DeuCerto,item);
            if(DeuCerto==true){cout << "Elemento removido com sucesso : " << item1 << endl;}
        else {cout << " NAo foi possível  remover tal elemento"<<endl;}
        }
        else if (opcao == 3) {
            if (lista1.estacheia() == true) {
                cout << "A lista está cheia" << endl;
            }
            else {
                cout << "A lista nao está cheia" << endl;
            }
        }        
        else if (opcao == 4) {
            if (lista1.estavazia() == true) {
                cout << "A lista está vazia" << endl;
            }
            else {
                cout << "A lista nao está vazia" << endl;
            }
        }
        else if (opcao == 5) {
           tamanho = lista1.qualtamanho();
           cout << " O tamanhao da lista 1 eh : "<<tamanho<<endl;
        }
    } while (opcao != 0);
   cout << "Essa foi a lista 1:";
   lista1.imprimir();
   cout << endl;

    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "Bem Vindo a lista 2 , por favor , digite alugma opcao do menu:\n";
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

    do
    {
        cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
        cout << "Digite 0 para parar o programa\n";
        cout << "Digite 1 para inserir um elemento\n";
        cout << "Digite 2 para remover um elemento\n";
        cout << "Digite 3 para ver se a lista está cheia \n";
        cout << "Digite 4 para ver se a lista está vazia\n";
        cout << "Digite 5 para saber o tamanho dessa lista\n";
        cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
        cin >> variavel_controle;

        if (variavel_controle == 1)
        {
            cout << "Digite o elemento a ser inserido\n";
            cin >> objeto;
            lista2.inserir(objeto, DeuCerto);
            if (DeuCerto == true)
            {
                cout << "Elemento inserido com sucesso " << endl;
            }
            else
            {
                cout << "Infelizmente o DeuCerto retornou falso , logo esse elemento nao foi inserido" << endl;
            }
        }

        else if (variavel_controle == 2)
        {
            cout << "Digite o elemento que vc quer remover"<<endl;
            cin >> objeto ;
           item1 = lista2.remover( DeuCerto,objeto);
            if (DeuCerto == true)
            {
                cout << "Elemento removido com sucesso : " << item1 << endl;
            }
            else
            {
                cout << "Infelizmente o DeuCerto retornou falso , logo esse elemento nao foi removido" << endl;
            }
        }

        else if (variavel_controle == 3)
        {
            if (lista2.estacheia() == true)
            {
                cout << "A lista está CHEIA" << endl;
            }
            else
            {
                cout << "A lista NAO está cheia" << endl;
            }
        }
        else if (variavel_controle == 4)
        {
            if (lista2.estavazia() == true)
            {
                cout << "A lista está VAZIA" << endl;
            }
            else
            {
                cout << "A lista NAO está vazia" << endl;
            }
        }
        else if (variavel_controle == 5)
        {
            cout << "O tamanho da lista eh : ";
            tamanho=lista2.qualtamanho();
            cout << tamanho<<endl;
        }
    } while (variavel_controle != 0);
    cout << "Essa  foi a lista 2 :  ";
    lista2.imprimir();
    cout << endl;


    return  0;
}