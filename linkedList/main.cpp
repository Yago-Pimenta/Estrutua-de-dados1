#include <iostream>
#include "dynamic_queue.h"
using namespace std;
fila_encadeada fila3;
//pegar operação nao primitiva das atividades passadas e colocar ela no arquivo dynamic
//e passar por referencia a fila 2
int main(){
fila_encadeada fila1,fila2;
int opcao,variavel_controle;
TipoItem item,objeto ;
bool DeuCerto;
int tamanho;
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "Bem Vindo a Fila 1  , por favor , digite alugma opcao do menu:\n";
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

    do {
        cout << "Digite 0 para parar o programa\n";
        cout << "Digite 1 para inserir um elemento\n";
        cout << "Digite 2 para remover um elemento\n";
        cout << "Digite 3 para ver se a fila está cheia \n";
        cout << "Digite 4 para ver se a fila está vazia\n";
        cout << "Digite 5 para saber o tamanho da fila\n";
        cin >> opcao;

        if (opcao == 1) {
            cout << "Digite o elemento a ser inserido\n";
            cin >> item;
            fila1.inserir(item,DeuCerto);
             if(DeuCerto==true){cout << "Elemento inserido com sucesso : " << item << endl;}
        else{ cout << " NAo foi possível  inserir tal elemento"<<endl;}
        }
        else if (opcao == 2) {
            item = fila1.remover(DeuCerto);
            if(DeuCerto==true){cout << "Elemento removido com sucesso : " << item << endl;}
        else {cout << " NAo foi possível  remover tal elemento"<<endl;}
        }
        else if (opcao == 3) {
            if (fila1.estacheia() == true) {
                cout << "A filla está cheia" << endl;
            }
            else {
                cout << "A fila nao está cheia" << endl;
            }
        }        
        else if (opcao == 4) {
            if (fila1.estavazia() == true) {
                cout << "A fila está vazia" << endl;
            }
            else {
                cout << "A fila nao está vazia" << endl;
            }
        }
        else if (opcao == 5) {
           tamanho = fila1.qualtamanho();
           cout << " O tamanhao da fila 1 eh : "<<tamanho<<endl;
        }
    } while (opcao != 0);
   cout << "Essa foi a fila 1:";
   fila1.imprimir();
   cout << endl;

    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "Bem Vindo a Fila 2 , por favor , digite alugma opcao do menu:\n";
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

    do
    {
        cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
        cout << "Digite 0 para parar o programa\n";
        cout << "Digite 1 para inserir um elemento\n";
        cout << "Digite 2 para remover um elemento\n";
        cout << "Digite 3 para ver se a fila está cheia \n";
        cout << "Digite 4 para ver se a fila está vazia\n";
        cout << "Digite 5 para saber o tamanho dessa fila\n";
        cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
        cin >> variavel_controle;

        if (variavel_controle == 1)
        {
            cout << "Digite o elemento a ser inserido\n";
            cin >> objeto;
            fila2.inserir(objeto, DeuCerto);
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
           objeto = fila2.remover( DeuCerto);
            if (DeuCerto == true)
            {
                cout << "Elemento removido com sucesso : " << objeto << endl;
            }
            else
            {
                cout << "Infelizmente o DeuCerto retornou falso , logo esse elemento nao foi removido" << endl;
            }
        }

        else if (variavel_controle == 3)
        {
            if (fila2.estacheia() == true)
            {
                cout << "A fila está CHEIA" << endl;
            }
            else
            {
                cout << "A fila NAO está cheia" << endl;
            }
        }
        else if (variavel_controle == 4)
        {
            if (fila2.estavazia() == true)
            {
                cout << "A fila está VAZIA" << endl;
            }
            else
            {
                cout << "A fila NAO está vazia" << endl;
            }
        }
        else if (variavel_controle == 5)
        {
            cout << "O tamanho da fila eh : ";
            tamanho=fila2.qualtamanho();
            cout << tamanho<<endl;
        }
    } while (variavel_controle != 0);
    cout << "Essa  foi a fila 2 :  ";
    fila2.imprimir();
    cout << endl;
// agora que já fizemos a introdução padrao irei chamar as duas operações nao primitivas
cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
cout << "Chamando operações não primtiivas : " << endl;
cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
cout << "Qual fila eh maior : ";
bool resultado = fila1.Mais_Elementos(fila1,fila2);
if(resultado == true ){
    cout << " As filas tem o mesmo tamanho "<<endl;
}else  {
    cout << " As filas nao tem o mesmo tamanho"<<endl;
}
fila1.imprimir();
fila2.imprimir();
fila1.Juncao_Elementos(fila1,fila2,fila3);
cout<< "Juntamos os elementos das duas filas em uma terceira : "<<endl;
fila3.imprimir();
    return  0;
}