// Lista duplamente encadeada , com header , sem repetição , circular
typedef int Elemento;
// hoje irei fazer com int , mas basta  alterar a variavel elemento
struct Node
{
    // como se trata de um a lista duplamente encadeada
    // cada "pedaço" da minha lista vai ter um valor(info) e o endereço do proximo elemento(next) e o anterior(prev)
    Elemento info;
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
    void imprimir(linked_list &lista1);
    int qualtamanho(linked_list &lista1);
    void PegaOprimeiro(linked_list &lista1, Elemento &X, bool &DeuCerto);
    void PegaOproximo(linked_list &lista1, Elemento &X, bool &DeuCerto);
    bool estaNalista(linked_list &lista1, Elemento &X);
    void InsereADireitadeP(linked_list &lista1, bool &DeuCerto, Elemento X);
    void Retira(linked_list &lista1, Elemento &X, bool &OK);
    void Insere_Lista_Original(linked_list &lista1, Elemento &X, bool &DeuCerto);
    void Insere_Carrinho_Compras(linked_list &lista1, Elemento &X, bool &DeuCerto);
    int ItensCompradosErroneamente(linked_list &lista1, linked_list &lista2);

private:
    Node *Header;
    Node *Atual;
};