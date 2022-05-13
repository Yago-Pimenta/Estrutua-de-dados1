#include <iostream>
#include "solucao1.h"
using namespace std;
int main()
{
    FILA F;
    int X;
    bool Ok;
 
    cin >> X;
    F.Insere(F, X, Ok);
    Ok = F.Vazia(F);
    cout << Ok <<endl;
    cin >> X;
    F.Insere(F, X, Ok);
    cin >> X;
    F.Insere(F, X, Ok);
    cout << Ok <<endl;
    F.Retira(F,X,Ok);
    F.Retira(F,X,Ok);
    F.Retira(F,X,Ok);
    cout << Ok <<endl;
    return 0;
}