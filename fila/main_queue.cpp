#include <iostream>
#include "queue.h"
using namespace std;



void TrocaElementos_JuncaoDosElementos(queue fila1, queue fila2,queue fila3);
int main()
{
    //irá ter duas pilhas para fazer o exercicio 3.1(junção elementos duas filas ) 3.2(troca de elementos)
    // IREI FAZER POR INPUT , para  ficar algo mais realista
    queue fila1;
    queue fila2;
    tipo_da_variavel objeto;
    int variavel_controle;
    bool DeuCerto;
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "Bem Vindo a Fila 1 , por favor , digite alugma opcao do menu:\n";
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

    do
    {
        cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
        cout << "Digite 0 para parar o programa\n";
        cout << "Digite 1 para inserir um elemento\n";
        cout << "Digite 2 para remover um elemento\n";
        cout << "Digite 3 para ver se a pilha está cheia \n";
        cout << "Digite 4 para ver se a pilha está vazia\n";
        cout << "Digite 5 para saber o tamanho dessa pilha\n";
        cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
        cin >> variavel_controle;

        if (variavel_controle == 1)
        {
            cout << "Digite o elemento a ser inserido\n";
            cin >> objeto;
            fila1.inserir(objeto, DeuCerto);
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
            fila1.remover(objeto, DeuCerto);
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
            if (fila1.esta_cheia() == true)
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
            if (fila1.esta_vazia() == true)
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
            fila1.qualtamanho();
        }
    } while (variavel_controle != 0);
    cout << "Essa  foi a fila 1 :  ";
    fila1.imprimir();
    cout << endl;

    // commo nao pensei em um metodo mais pratico para cadastrar os elementos da fila 2 será idem a fila 1
    //ou seja por inputs , para simular um programa real
    int aleatorio;
    cout << "Precione algum numero para ir até o cadastro da pilha 2" << endl;
    cin >> aleatorio;

    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "Bem Vindo a Fila 2 , por favor , digite alugma opcao do menu:\n";
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

    do
    {
        cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
        cout << "Digite 0 para parar o programa\n";
        cout << "Digite 1 para inserir um elemento\n";
        cout << "Digite 2 para remover um elemento\n";
        cout << "Digite 3 para ver se a pilha está cheia \n";
        cout << "Digite 4 para ver se a pilha está vazia\n";
        cout << "Digite 5 para saber o tamanho dessa pilha\n";
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
            fila2.remover(objeto, DeuCerto);
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
            if (fila2.esta_cheia() == true)
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
            if (fila2.esta_vazia() == true)
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
            fila2.qualtamanho();
        }
    } while (variavel_controle != 0);
    cout << "Essa  foi a fila 2 :  ";
    fila2.imprimir();
    cout << endl;




    cout << "Muito bem , após todos esses processo , finalmente , podemos abordar o exercicio 3.1 e 3.2 " << endl;
    cout << "Digite algum numero para resolver os exercicios: " << endl;
    cin >> aleatorio;
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "Estou com um problema minha fila está retornando lixo depois que sai do procedimento"<<endl;
    cout << " Invertemos a fila 1 com a fila 2 " << endl;
    cout << "Junção dos elementos de duas pilhas em uma terceira : " << endl;
     queue fila3;
    TrocaElementos_JuncaoDosElementos(fila1, fila2,fila3);
      



    fila1.~queue();
    fila2.~queue();
    return 0;
}

//exercicio 3.1 vamos juntar as duas filas em uma terceira

//agora vamos fazer o exercicio 3.2 que vai trocar os elementos da fila 1 com os elemetos da fila 2
//juntei os dois exercicios no mesmo procedimentos
void TrocaElementos_JuncaoDosElementos(queue fila1, queue fila2,queue fila3)
{
    tipo_da_variavel ElementodaFila;
    queue filaAUX;
    bool DeuCerto;
    while (fila1.esta_vazia() == false)
    {
        fila1.remover(ElementodaFila, DeuCerto);
        fila3.inserir(ElementodaFila, DeuCerto);
        filaAUX.inserir(ElementodaFila, DeuCerto);
    }
    while (filaAUX.esta_vazia() == false)
    {
        filaAUX.remover(ElementodaFila, DeuCerto);
        fila1.inserir(ElementodaFila, DeuCerto);
    }
    while (fila2.esta_vazia() == false)
    {
        fila2.remover(ElementodaFila, DeuCerto);
        fila3.inserir(ElementodaFila, DeuCerto);
        filaAUX.inserir(ElementodaFila, DeuCerto);
    }
    while (filaAUX.esta_vazia() == false)
    {
        filaAUX.remover(ElementodaFila, DeuCerto);

        fila2.inserir(ElementodaFila, DeuCerto);

    } //terminamos o procedimento

    cout << " Essa é a fila 3 : ";
    fila3.imprimir();
    cout << endl;

    queue filaAUX1, filaAUX2;
 
   
    while (fila1.esta_vazia() == false)
    {
        fila1.remover(ElementodaFila, DeuCerto);
        if (DeuCerto == false)
        {
            cout << "Algo deu Errado" << endl;
        }
      
        filaAUX1.inserir(ElementodaFila, DeuCerto);
    }
    while (fila2.esta_vazia() == false)
    {
        fila2.remover(ElementodaFila, DeuCerto);
        filaAUX2.inserir(ElementodaFila, DeuCerto);
    }
    while (filaAUX1.esta_vazia() == false)
    {
        filaAUX1.remover(ElementodaFila, DeuCerto);
        fila2.inserir(ElementodaFila, DeuCerto);
    }
    while (filaAUX2.esta_vazia() == false)
    {
        filaAUX2.remover(ElementodaFila, DeuCerto);
        fila1.inserir(ElementodaFila, DeuCerto);
    }
    cout << "FILA 1 : ";
    fila1.imprimir();
    cout << "FILA 2 : ";
    fila2.imprimir();
    cout << endl;
}