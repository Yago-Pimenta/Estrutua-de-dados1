#include <iostream>

#include "arvore.h"

using namespace std;

int main()
{
    int opc;
    Node *R;
    BinaryTree arvore1;
    bool ok;
    cout << "-=-=---=--==-=---=--=-=-=-=-=-=-=---=-==-=--=-=-=-=-==--=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

    cout << "Digite 0 para parar o programa\n";
    cout << "Digite 1 para inserir um elemento\n";
    cout << "Digite 2 para remover um elemento\n";
    cout << "Digite 3 para imprimir a arvore em pre ordem , em ordem e pos ordem\n";
    cout << "Digite 4 para ver a soma da arvore \n";
    cout << "Digite 5 para ver a altura da arovre\n";
    cout << "-=-=---=--==-=---=--=-=-=-=-=-=-=---=-==-=--=-=-=-=-==--=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cin >> opc;
    while (opc != 0)
    {
        // sempre preciso que meu R esteja apontando para a raiz , infelizmente tive deixar esse atributo public
        R = arvore1.raiz;
      
        if (opc == 1)
        {
            cout << "-=-=---=--==-=---=--=-=-=-=-=-=-=---=-==-=--=-=-=-=-==--=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
           
            cout << "Digite um CPF" << endl;
            int cpf;
            cin >> cpf;
       
        
            cout << "-=-=---=--==-=---=--=-=-=-=-=-=-=---=-==-=--=-=-=-=-==--=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
            arvore1.inserir(R,cpf,ok);
            if (ok == false)
            {
                cout << "Ocorreu um erro na inserção " << endl;
            }
            else
            {
                cout << "O objeto foi inserido com sucesso" << endl;
            }
        }
        else if (opc == 2)
        {
            cout << "Digite o cpf a ser removido " << endl;
            cout << "-=-=---=--==-=---=--=-=-=-=-=-=-=---=-==-=--=-=-=-=-==--=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
             
           
            cout << "Digite um CPF" << endl;
            int cpf;
            cin >> cpf;
           
            arvore1.remove(R, cpf, ok);
            if (ok == false)
            {
                cout << "Ocorreu um erro na remoção " << endl;
            }
            else
            {
                cout << "O objeto foi removido com sucesso" << endl;
            }
            cout << "-=-=---=--==-=---=--=-=-=-=-=-=-=---=-==-=--=-=-=-=-==--=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
        }
        else if (opc == 3)
        {
            cout << "Em PRE-ORDEM  : ";
            arvore1.imprimirPreOrdem(R);
            cout << endl;
            cout << "Em EM-ORDEM  : ";
            arvore1.imprimirPreOrdem(R);
            cout << endl;
            cout << "Em POS-ORDEM  : ";
            arvore1.imprimirPreOrdem(R);
            cout << endl;
        }
        else if (opc == 4)
        {
            cout << "A soma da arvore eh : " << arvore1.soma(R) << endl;
        }
        else if (opc == 5)
        {
            cout << "A altura da arvore eh : " << arvore1.altura(R) << endl;
        }
        else
        {
            cout << "Nenhuma opção encontrada , encerrando o programa" << endl;
            break;
        }
        cout << "Digite 0 para parar o programa\n";
        cout << "Digite 1 para inserir um elemento\n";
        cout << "Digite 2 para remover um elemento\n";
        cout << "Digite 3 para imprimir a arvore em pre ordem , em ordem e pos ordem\n";
        cout << "Digite 4 para ver a soma da arvore \n";
        cout << "Digite 5 para ver a altura da arovre\n";
        cout << "-=-=---=--==-=---=--=-=-=-=-=-=-=---=-==-=--=-=-=-=-==--=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
        cin >> opc;
    }
    return 0;
}