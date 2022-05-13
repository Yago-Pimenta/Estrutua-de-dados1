//Lista duplamente encadeada , circular , com header , sem repetição

//posso escolher o tipo que quero fazer , hoje será int
typedef int Elemento;

struct Node
{
    //como se trata de um a lista duplamente encadeada
    //cada "pedaço" da minha lista vai ter um valor(info) e o endereço do proximo elemento(next) e o anterior(prev)
    Elemento info; // vai conter o valor
    Node *Dir; //aponta para o proximo
    Node *Esq; //aponta para o anterior
};

class FILA 
{

public:
    FILA();

    bool Vazia(FILA& F);    // essas sao as 3 funções pedidas e iremos usar outras
    //para auxiliar a construção dessas e fazer uma solução portatil
    ~FILA();
    void Destroi(FILA &F);
    void Retira(FILA &F, Elemento &X, bool &OK);





//essas  vao servir apenas para auxiliar

   
    void Insere(FILA &F, Elemento &X, bool &DeuCerto);
    void print(FILA& F);
private:
//ambos sao do tipo NodePtr
    Node *Primeiro;
    Node *Ultimo;

    };