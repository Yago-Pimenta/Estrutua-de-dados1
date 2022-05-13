void CorrigeSubindo(int *Heap, int LastPosition)
{

    int corr = LastPosition;
    while (corr > 0 && Heap[Pai(corr)] < Heap[corr])
    {
        troca(&Heap[corr], &Heap[Pai(corr)]);
        corr = Pai(corr);
    }
}
int Pai(int i)
{
    return (i - 1) / 2;
}
void troca(int *i, int *j)
{
    int aux = *i;
   *i = *j;
    *j = aux;
}
