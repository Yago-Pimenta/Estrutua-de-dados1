/*
Nota - Quase 100
1 - O int  nao poderia ser por referencia
void Remove(ABB R, int& X, bool &ok)
{

    if (R == NULL)
    {
        CERTO
        ok = false; // caso em que  a arvore tiver vazia
    }
    else
    {
        2 - eu chamei info de R e ficou estranho
        if (R->X > X)
        {
            //função recursiva para andarmos para esquerda , haja vista que nosso elemento está la
            remove(R->esq, X, ok);
        }
        else if (R->X < X)
        { //nesse caso vamos andar para direita , pois ele está lá
            remove(R->dir, X, ok);
        }
        caso 1 e  2 CERTO
        else
        {
            // ->caso em que encontrou :
            o melhoor seria se fosse um ponteiro nodeptr
            ABB Aux = new ABB ;
            ABB Aux = R;
            
            ok = true;
            // 1 CASO -  NAO tem filhos
            if (R->dir == NULL && R->esq == NULL)
            {
                
                delete Aux;
                R = NULL;
                PERFEITO
            }
            //2 CASO - Tem dois filhos 
            else if (R->dir != NULL && R->esq != NULL)
            {
                
                //algoritmo para descobrir para quem vai apontar o nó de cima 
                // resumindo vai um para esquerda e o resto vai  o maximo possivel a direita
                Aux = R->esq;
                while (Aux->dir != NULL)
                {
                    Aux = Aux->dir;
                }
                // agora que achamos , vamos substituir o R->info(o que queremos eliminar==X) pelo do aux
                R->X = Aux->X;

                // agora precisamos remover o elemento remetido , que ficou la em baixo
                remove(R->esq, R->X, ok);
                // unica recursao usada para remover
                PERFEITO
            }
            //3 CASO - um unico filho
            else
            {
                //nesse caso o algoritmo consiste que o de cima vai apontar obrigatoriamente para o que sobrou
                if (R->esq == NULL)
                {
                    R = R->dir;
                }
                else
                {
                    R = R->esq;
                }
                delete Aux;
            }
            certo
        }
    }
}
Acho que mereço uma nota bem alta nessa questao
unica divergencia que encontrei foi que usei um if e else
para ver se a arvore está vazia , nao sei se teria problema
na recursao
*/