//Perfeito só faltou chamar size de n 
#include <iostream>
#include <new>
using namespace std;
//nao podia ter usado size , deveria ter usado N 
void BubbleSort(int *v, const int size)
{
    int temp = 0; // vai servir de auxiliar para trocar fazer a "troca"
    int fim = 0;  // IMPORTANTE para OTIMIZACAO , haja vista que o array vai percorrer apenas o necessario
    while (fim++ != size)
    {

        bool troca = false;
        for (int i = 0; i < size; i++)
        {
            // para otimizar vamos sempre comparar apenas de dois em dois elementos
            if (v[i] > v[i + 1])
            { // ve se o elemento anterior é maior que o posterior
                temp = v[i];
                v[i] = v[i + 1]; // Change the positions
                v[i + 1] = temp;
                troca = true;
            }
        }
        // pela sugestao do enunciado , se ao percorrer o array inteiro e nao houve troca deve parar imediatamente
        if (!troca)
            break;
    }
}
int main()
{

    
    return 0;
}