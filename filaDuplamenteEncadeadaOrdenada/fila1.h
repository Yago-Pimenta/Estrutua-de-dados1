//Lista duplamente encadeada , NAO circular , com dois ponteiro  , sem repetição 
typedef char TipoItem;
//hoje irei fazer com char
struct Node
{
    
    TipoItem info;
    Node *dir;
    Node *esq;
};

class fila
{

public:
    fila();
    ~fila();
    bool estacheia();
    bool estavazia();
    void imprimir(fila& lista1);
    int qualtamanho(fila& lista1);
    void PegaOprimeiro(fila &lista1, TipoItem &X, bool &DeuCerto);
    void PegaOproximo(fila &lista1, TipoItem &X, bool &DeuCerto);
    bool estaNalista(fila &lista1, TipoItem &X);
    void InsereADireitadeP(fila &lista1, bool &DeuCerto, TipoItem X);
    void Retira(fila &lista1, TipoItem &X, bool &OK);
    void Insere(fila &lista1, TipoItem &X, bool &DeuCerto);
  
    void uniao(fila &lista1,fila &lista2, fila &lista3);
private:
    Node *ultimo;
    Node *primeiro;

    };