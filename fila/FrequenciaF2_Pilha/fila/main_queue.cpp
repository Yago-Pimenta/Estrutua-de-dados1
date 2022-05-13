#include <iostream>
#include "queue.h"
using namespace std;

int main(){
queue queue1;
int opcao;
tipo_da_variavel item ;
bool ta_ok;
cout << "Programa gerador de filas:\n";
    do {
        cout << "Digite 0 para parar o programa\n";
        cout << "Digite 1 para inserir um elemento\n";
        cout << "Digite 2 para remover um elemento\n";
        cout << "Digite 3 para imprimir a fila\n";
        cout << "Digite 4 para ver se a fila está cheia \n";
        cout << "Digite 5 para ver se a fila está vazia\n";
        cin >> opcao;
#include <iostream>
#include "stack.h"
using namespace std;

//VALE ENFATIZAR QUE IREI IMPLANTAR DUAS FUNÇÕES NAO PRIMITIVAS DIRETAMENTE AQUI
// o exercicio 2.2 e o exercicio 2.4
bool MaisElementos(pilha pilha1, pilha pilha2);
bool Iguais(pilha pilha1, pilha pilha2);

int main()
{
    //irá ter duas pilhas para dar certo o exercicio 2.2 e 2.4
    pilha pilha1;
    pilha pilha2;
    tipo_da_variavel objeto;
    int variavel_controle;

    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "Bem Vindo a Pilha 1 , por favor , digite alugma opcao do menu:\n";
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
            pilha1.inserir(objeto);
            if (pilha1.DeuCerto == true)
                cout << "Elemento inserido com sucesso " << endl;
        }
        else if (variavel_controle == 2)
        {
            objeto = pilha1.remover();
            if (pilha1.DeuCerto == true)
                cout << "Elemento removido com sucesso : " << objeto << endl;
        }

        else if (variavel_controle == 3)
        {
            if (pilha1.esta_cheia() == true)
            {
                cout << "A pilha está CHEIA" << endl;
            }
            else
            {
                cout << "A pilha NAO está cheia" << endl;
            }
        }
        else if (variavel_controle == 4)
        {
            if (pilha1.esta_vazia() == true)
            {
                cout << "A pilha está VAZIA" << endl;
            }
            else
            {
                cout << "A pilha NAO está vazia" << endl;
            }
        }
        else if (variavel_controle == 5)
        {
            cout << "O tamanho da pilha eh : ";
            cout << pilha1.qualtamanho() << endl;
        }
    } while (variavel_controle != 0);
    cout << "Essa  foi a pilha 1 :  ";
    pilha1.imprimir();
    cout << endl;

    // commo nao pensei em um metodo mais pratico para cadastrar os elementos da pilha 2 será idem a pilha 1
    int aleatorio;
    cout << "Precione algum numero para ir até o cadastro da pilha 2" << endl;
    cin >> aleatorio;

    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "Bem Vindo a Pilha 2 , por favor , digite alugma opcao do menu:\n";
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
            pilha2.inserir(objeto);
            if (pilha2.DeuCerto == true)
                cout << "Elemento inserido com sucesso " << endl;
        }
        else if (variavel_controle == 2)
        {
            objeto = pilha2.remover();
            if (pilha2.DeuCerto == true)
                cout << "Elemento removido com sucesso : " << objeto << endl;
        }

        else if (variavel_controle == 3)
        {
            if (pilha2.esta_cheia() == true)
            {
                cout << "A pilha está CHEIA" << endl;
            }
            else
            {
                cout << "A pilha NAO está cheia" << endl;
            }
        }
        else if (variavel_controle == 4)
        {
            if (pilha2.esta_vazia() == true)
            {
                cout << "A pilha está VAZIA" << endl;
            }
            else
            {
                cout << "A pilha NAO está vazia" << endl;
            }
        }
        else if (variavel_controle == 5)
        {
            cout << "O tamanho da pilha eh : ";
            cout << pilha2.qualtamanho() << endl;
        }
    } while (variavel_controle != 0);
    cout << "Essa  foi a pilha 2 :  ";
    pilha2.imprimir();
    cout << endl;

    cout << "Muito bem , após todos esses processor , finalmente , podemos abordar o exercicio 2.2 e 2.4 " << endl;
    cout << "Digite algum numero para resolver os exercicios: " << endl;
    cin >> aleatorio;
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "Vamos ver se as pilhas tem o mesmo tamanho  : " << endl;
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    if (MaisElementos(pilha1, pilha2) == true)
    {
        cout << "As pilhas tem  o mesmo tamanho , PARABENS " << endl;
    }
    else
    {
        cout << "Infelizmente as pilhas nao tem  o mesmo tamanho" << endl;
    }
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "Para finalizar  , vamos ver se as pilhas sao iguais  : " << endl;
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
  
    if (Iguais(pilha1, pilha2) == true)
    {
        cout << "As pilhas sao IGUAIS , PARABENS " << endl;
    }
    else
    {
        cout << "Infelizmente as pilhas NAO sao IGUAIS" << endl;
    }
    pilha1.~pilha();
    pilha2.~pilha();
    return 0;
}
bool MaisElementos(pilha pilha1, pilha pilha2)
{
    bool deu_certo;
    int elementos_pilha, elementos_pilha1, elementos_pilha2;
    pilha Paux1, Paxu2;
    // essas duas variaveis auxiliares vai contar quantos elementos tem em cada pilha
    int elementos_da_P1 = 0;
    int elementos_da_P2 = 0;

    // pagina 21 do material
    while (pilha1.esta_vazia() == false)
    {
        int elemento_da_pilha;
        elemento_da_pilha = pilha1.remover();
        Paux1.inserir(elemento_da_pilha);
        elementos_da_P1 += 1;
        // após desempilhar os elementos para fazer a contagem , precisamos voltar :
    }
    while (Paux1.esta_vazia() == false)
    {
        int elemento_da_pilha;
        elemento_da_pilha = Paux1.remover();
        pilha1.inserir(elemento_da_pilha);

        //voltamos os elementos para a pilha original
    }

    while (pilha2.esta_vazia() == false)
    {
        int elemento_da_pilha;
        elemento_da_pilha = pilha2.remover();
        Paxu2.inserir(elemento_da_pilha);
        elementos_da_P2 += 1;
        // estamos fazendo o mesmo procedimento igual ao da pilha1
    }
    while (Paxu2.esta_vazia() == false)
    {
        int elemento_da_pilha;
        elemento_da_pilha = Paxu2.remover();
        pilha2.inserir(elemento_da_pilha);

        //voltamos os elementos para a pilha original
    }
    if (elementos_da_P1 == elementos_da_P2)
    {
        return true;
    }
    else
        return false;
}

//agora vamos trabalhar com o exercicio 2.4
bool Iguais(pilha pilha1, pilha pilha2)
{
    pilha Paux1,Paux2;
    bool PorEnquantoSaoIguais;
    
    PorEnquantoSaoIguais = true;

    while ((pilha1.esta_vazia() == false && pilha2.esta_vazia() == false) )
    {
        int ElementoPilha1, ElementoPilha2;
        ElementoPilha1 = pilha1.remover();
        ElementoPilha2 = pilha2.remover();
        if (ElementoPilha1 != ElementoPilha2)
        {
            PorEnquantoSaoIguais = false;
            break;
        }
        Paux1.inserir(ElementoPilha1);
        Paux2.inserir(ElementoPilha2);
        //no exemplo do professor ele utiliza a variavel DeuCerto , tomei a liberdade de adaptar
    }
while (Paux1.esta_vazia() == false)
    {
        int elemento_da_pilha;
        elemento_da_pilha = Paux1.remover();
        pilha1.inserir(elemento_da_pilha);

       
    }
while (Paux2.esta_vazia() == false)
    {
        int elemento_da_pilha;
        elemento_da_pilha = Paux2.remover();
        pilha2.inserir(elemento_da_pilha);

        
    }
    if (PorEnquantoSaoIguais == false)
    {
        return false;
    }
    else
    {
        return true;
    }
}
        if (opcao == 1) {
            cout << "Digite o elemento a ser inserido\n";
            cin >> item;
            queue1.inserir(item,ta_ok);
        }
        else if (opcao == 2) {
            item = queue1.remover(item,ta_ok);
            cout << "Elemento removido com sucesso : " << item << endl;
        }
        else if (opcao == 3) {
            queue1.imprimir();
        }        
        else if (opcao == 4) {
            if (queue1.esta_cheia() == true) {
                cout << "A filla está cheia" << endl;ko
            }
            else {
                cout << "A fila nao está cheia" << endl;
            }
        }
        else if (opcao == 5) {
            if (queue1.esta_vazia() == true) {
                cout << "A fila está vazia" << endl;
            }
            else {
                cout << "A fila nao está vazia" << endl;
            }
        }
    } while (opcao != 0);
    queue1.~queue() ;



    return  0;
}