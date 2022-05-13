//errei a b , pois falei que a complexidade era Ln(n)
//mas na verdade é log2(n)
#include <iostream>
using namespace std;
void max_heap(int *a, int m, int n)
{
    int j, t;
    t = a[m];
    j = 2 * m;
    while (j <= n)
    {
        if (j < n && a[j + 1] > a[j])
            j = j + 1;
        if (t > a[j])
            break;
        else if (t <= a[j])
        {
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j / 2] = t;
    return;
}
void build_maxheap(int *a, int n)
{
    int k;
    for (k = n / 2; k >= 1; k--)
    {
        max_heap(a, k, n);
    }
}
void CorrigeHeapSubindo(int *Heap, int LastPosition)
{
//1 , nao tratei o caso em que lastposition é menor que zero

    //com base no enuncaido estou apenas subindo , sem corrigir na horizontal
    while (Heap[LastPosition] > Heap[(LastPosition - 1) / 2])
    {
        int temp = Heap[LastPosition];
        Heap[LastPosition] = Heap[(LastPosition - 1) / 2];
        Heap[(LastPosition - 1) / 2] = temp;
        LastPosition = (LastPosition - 1) / 2;
    }


}
int main()
{
    int v[6] = {
        19, 16, 4, 7, 6, 50};
    CorrigeHeapSubindo(v, 5);
    cout << v[0] << endl;
    return 0;
}