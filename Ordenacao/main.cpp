
#include <iostream>
#include <chrono>
#include <vector>
using namespace std;
// vamos começar pelo mais simples que é o Inserção
// Big O (n^2)->invariavelmente irei percorrer sempre um for que tem um outro dentro
void SelectionSort(int v[], int size)
{
    int i, min, aux, j;
    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
        {
            if (v[j] < v[min])
            {
                min = j;
            }
        }
        aux = v[i];
        v[i] = v[min];
        v[min] = aux;
    }
}

// esse é o de Troca , no melhor caso vai ser um O(n) já no pior continua sendo O(n^2)
void InserctionSort(int v[], int size)
{
    int i, j, aux;
    for (i = 1; i < size ; i++)
    {

        aux = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > aux)
        {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = aux;
    }
}
void printVector(int v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main()
{
    int v[1000];
    int n = 1000;
    // primeiro teste : vamos testar com um vetor já ordenado (MELHOR CASO)
    cout << "Vamos começar testando o melhor caso , ou seja , um vetor ORDENADO  " << endl;
    for (int i = 0; i < n; i++)
    {
        v[i] = i;
    }
    // começando por selection sort array de 1000 elementos
    auto t1 = std::chrono::high_resolution_clock::now();

    SelectionSort(v, n);

    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << "Ordenação por Seleção em um vetor ja ORDENADO levou "
              << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()
              << " microseconds\n"
              << endl;
    cout << "-=---=--==---=-=-=-=-=-==-=-=-=--=-=-==--=-=-=-=-==--=-=-=-=" << endl;
    auto t3 = std::chrono::high_resolution_clock::now();

    InserctionSort(v, n);

    auto t4 = std::chrono::high_resolution_clock::now();
    std::cout << "Ordenação por Inserção em um vetor ja ORDENADO levou "
              << std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count()
              << " microseconds\n"
              << endl;
    cout << "-=---=--==---=-=-=-=-=-==-=-=-=--=-=-==--=-=-=-=-==--=-=-=-=" << endl;
    cout << "Agora irei iremos testar para vetores pequenos desordenados" << endl;
    int vec[5] = {52, 8, 62, 1, 57};
    printVector(vec, 5);
    cout << "Por seleção : ";
    SelectionSort(vec, 5);
    printVector(vec, 5);
    cout << "-=---=--==---=-=-=-=-=-==-=-=-=--=-=-==--=-=-=-=-==--=-=-=-=" << endl;
    
    int vector[5] = {52, 8, 62, 1, 57};
    cout << "Por Inserção : ";
    InserctionSort(vector, 5);
    printVector(vector, 5);
    cout << "-=---=--==---=-=-=-=-=-==-=-=-=--=-=-==--=-=-=-=-==--=-=-=-=" << endl;
    return 0;
}