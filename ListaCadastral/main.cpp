#include <iostream>
#include "listacadastral.h"
using namespace std;
// As duas operações não primitivas que usei foi qualtamanho e o print
linked_list lista3;

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
        cout << "Digite 6 para saber se tal elemento está na lista\n";
        cin >> opcao;

        if (opcao == 1) {
            cout << "Digite o elemento a ser inserido\n";
            cin >> item;
            lista1.Insere(lista1,item,DeuCerto);
             if(DeuCerto==true){cout << "Elemento inserido com sucesso : " << item << endl;}
        else{ cout << " NAo foi possível  inserir tal elemento"<<endl;}
        }
        else if (opcao == 2) {
            cin >> item ;
           lista1.Retira(lista1,item,DeuCerto);
            if(DeuCerto==true){cout << "Elemento removido com sucesso : " << item << endl;}
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
           tamanho = lista1.qualtamanho(lista1);
           cout << " O tamanhao da lista 1 eh : "<<tamanho<<endl;
        }
        else if(opcao == 6){
            cout << "Digite o valor para verificar se está na lista\n";
            int var;
            cin >> var;
            
            DeuCerto= lista1.estaNalista(lista1,var);
            if(DeuCerto == true){
                cout << "Sim , tal elemento está na lista\n";
            }else cout << "Tal elemento não está na lista\n";
        }
    } while (opcao != 0);
   cout << "Essa foi a lista 1:";
   lista1.imprimir(lista1);
   cout << endl;

    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "Bem Vindo a lista 2 , por favor , digite alugma opcao do menu:\n";
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

     do {
        cout << "Digite 0 para parar o programa\n";
        cout << "Digite 1 para inserir um elemento\n";
        cout << "Digite 2 para remover um elemento\n";
        cout << "Digite 3 para ver se a lista está cheia \n";
        cout << "Digite 4 para ver se a lista está vazia\n";
        cout << "Digite 5 para saber o tamanho da lista\n";
        cout << "Digite 6 para saber se tal elemento está na lista\n";
        cin >> variavel_controle;

        if (variavel_controle == 1) {
            cout << "Digite o elemento a ser inserido\n";
            cin >> item;
            lista2.Insere(lista2,item,DeuCerto);
             if(DeuCerto==true){cout << "Elemento inserido com sucesso : " << item << endl;}
        else{ cout << " NAo foi possível  inserir tal elemento"<<endl;}
        }
        else if (variavel_controle == 2) {
            cin >> item ;
           lista2.Retira(lista2,item,DeuCerto);
            if(DeuCerto==true){cout << "Elemento removido com sucesso : " << item << endl;}
        else {cout << " NAo foi possível  remover tal elemento"<<endl;}
        }
        else if (variavel_controle == 3) {
            if (lista2.estacheia() == true) {
                cout << "A lista está cheia" << endl;
            }
            else {
                cout << "A lista nao está cheia" << endl;
            }
        }        
        else if (variavel_controle == 4) {
            if (lista2.estavazia() == true) {
                cout << "A lista está vazia" << endl;
            }
            else {
                cout << "A lista nao está vazia" << endl;
            }
        }
        else if (variavel_controle == 5) {
           tamanho = lista2.qualtamanho(lista1);
           cout << " O tamanhao da lista 2 eh : "<<tamanho<<endl;
        }
        else if(variavel_controle == 6){
            cout << "Digite o valor para verificar se está na lista\n";
            int var;
            cin >> var;
            
            DeuCerto= lista2.estaNalista(lista2,var);
            if(DeuCerto == true){
                cout << "Sim , tal elemento está na lista\n";
            }else cout << "Tal elemento não está na lista\n";
        }
    } while (variavel_controle != 0);
    cout << "Essa  foi a lista 2 :  ";
    lista2.imprimir(lista2);
    cout << endl;
cout << " Agora irei implementar a operação UNIAO : "<<endl;
lista1.uniao(lista1,lista2,lista3);
lista3.imprimir(lista3);
lista1.~linked_list();
lista2.~linked_list();

    return  0;
}