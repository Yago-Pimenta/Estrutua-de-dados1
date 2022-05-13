struct ABB
{
    ABB *dir;
    ABB *esq;
    int info;
};
#include <iostream>
#include <cstddef>
void Remove(ABB *R, int X, bool &ok)
{
    bool erro;
    if (R == NULL)
    {
        ok = false;
    }
    else if (R->info > X)
    {
        Remove(R->esq, X, erro);
    }
    else if (R->info < X)
    {
        Remove(R->dir, X, erro);
    }
    else
    {
        ABB *Aux;
        Aux = R;
        ok = true;
        if (R->esq == NULL && R->esq == NULL)
        {
            delete Aux;
            R == NULL;
        }
        else if (R->esq != NULL && R->esq != NULL)
        {
            Aux = R->esq;
            while (Aux->dir != NULL)
            {
                Aux = Aux->dir;
            }
            R->info = Aux->info;
            Remove(R->esq, Aux->info, ok);
        }
        else
        {
            if (R->esq == NULL)
            {
                R = R->dir;
                R = R->esq;
                delete Aux;
            }
        }
    }
}
