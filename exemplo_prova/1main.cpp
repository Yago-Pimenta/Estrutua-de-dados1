#include <iostream>
#include "1.h"
using namespace std;
int main()
{
    FILA F;
    int X;
    bool Ok;
 
    cin >> X;
    F.Insere(F, X, Ok);
    cin >> X;
    F.Insere(F, X, Ok);
    cin >> X;
    F.Insere(F, X, Ok);
    F.Retira(F,X,Ok);
    return 0;
}