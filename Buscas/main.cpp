#include <iostream>
#include <cstddef>

#include <chrono>
#include <thread>
int a = 0;
using namespace std;
int buscaSequencial(int *, int, int);
int buscaBinariaAUX(int *, int, int);
int main()
{
    cout << "Iremos sempre analisar o pior caso : "<<endl;
     
    cout << "-=---=--==---=-=-=-=-=-==-=-=-=--=-=-==--=-=-=-=-==--=-=-=-=" << endl;
    int v[20] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200};
    int x;
    cout << "Digite o x que vc vai querer fazer a busca no vetor: " << endl;
    cin >> x;
    cout << "-=---=--==---=-=-=-=-=-==-=-=-=--=-=-==--=-=-=-=-==--=-=-=-=" << endl;
    cout << "Começando por a busca Sequencial : " << endl;
    auto t1 = std::chrono::high_resolution_clock::now();
    int index = buscaSequencial(v, 20, x);
    cout << "Esta na posição : " << index + 1 << endl;
    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << "Busca Sequencial levou "
              << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()
              << " microseconds\n"
              << endl;
    cout << "-=---=--==---=-=-=-=-=-==-=-=-=--=-=-==--=-=-=-=-==--=-=-=-=" << endl;
    cout << "Vamos fazer a  busca Binaria : " << endl;
    auto t3 = std::chrono::high_resolution_clock::now();
    int index1 = buscaBinariaAUX(v, 20, x);
    cout << "Esta na posição : " << index1 + 1 << endl;
    auto t4 = std::chrono::high_resolution_clock::now();
    std::cout << "Busca Binaria levou "
              << std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count()
              << " microseconds\n"
              << endl;
    cout << "-=---=--==---=-=-=-=-=-==-=-=-=--=-=-==--=-=-=-=-==--=-=-=-=" << endl;

    return 0;
}

// ambos algoritmos em sequencia foram dados nas aulas
int buscaSequencial(int v[], int tam, int x)
{
    int i = 0;

    bool ok = false;
    while ((i < tam) && (v[i] < x))
    {
        i++;
    }
    if (i < tam)
    {

        return i;
        ok = true;
    }
    else
    {
        return -1;
    }

    
}

int buscaBinaria(int v[], int min, int max, int x)
{
    if (min > max)
    {
        return -1;
    }
    int m;

    m = (min + max) / 2;
    
    if (v[m] == x)
    {
        return m;
    }
    if (v[m] < x)
    {
        return buscaBinaria(v, m + 1, max, x);
    }
    else
    {
        return buscaBinaria(v, min, m - 1, x);
    }
}

int buscaBinariaAUX(int v[], int n, int x)
{
    return buscaBinaria(v, 0, n - 1, x);
}

