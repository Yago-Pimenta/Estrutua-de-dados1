//Lista duplamente encadeada , circular , com header , sem repetição
typedef int TipoItem;
//hoje irei fazer com int
struct Node
{
    //como se trata de um a lista duplamente encadeada
    //cada "pedaço" da minha lista vai ter um valor(info) e o endereço do proximo elemento(next) e o anterior(prev)
    TipoItem info;
    Node *next;
    Node *prev;
};

class linked_list
{

public:
    linked_list();
    ~linked_list();
    bool estacheia();
    bool estavazia();
    void imprimir(linked_list& lista1);
    int qualtamanho(linked_list& lista1);
    void PegaOprimeiro(linked_list &lista1, TipoItem &X, bool &DeuCerto);
    void PegaOproximo(linked_list &lista1, TipoItem &X, bool &DeuCerto);
    bool estaNalista(linked_list &lista1, TipoItem &X);
    void InsereADireitadeP(linked_list &lista1, bool &DeuCerto, TipoItem X);
    void Retira(linked_list &lista1, TipoItem &X, bool &OK);
    void Insere(linked_list &lista1, TipoItem &X, bool &DeuCerto);
    void uniao(linked_list &lista1,linked_list &lista2, linked_list &lista3);
private:
    Node *Header;
    Node *Atual;

    };