#include <iostream>
#include <cstddef>
using namespace std;
void ordena(int *V, int N)
{
    // vou usar o algoritmo por seleção
    // como não está pedindo otimizado  será da maneira mais simplória mesmo
    int a, menor, aux, b;
    for (a = 0; a < N - 1; a++)
    {
        menor = a;
        //ao percorrer o vetor vamos fixar a variavel compradora "menor " no primeiro elemento , e com ela 
        //vamos comparar com todos os elementos do  vetor e trocar suas posições quando tal elemento for menor
        for (b = a + 1; b < N; b++)
        {
            if (V[a] < V[menor])
            {
                //mudando nossa variavel compradora pois achamos um menor
                menor = b;
            }
        }
        //algoritmo para troca após achar o menor valor 
        aux = V[a];
        V[a] = V[menor];
        V[menor] = aux;
    }
    //invariavelmente esse algoritmo vai percorrer n*n vezes esse vetor , um gasto computacional excessivo para arrays grandes

}