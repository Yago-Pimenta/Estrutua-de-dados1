typedef int TipoItem;
//hoje irei fazer com int
struct Node{
    //cada "pedaço" da minha lista vai ter um valor(info) e o endereço do proximo elemento(next)
    TipoItem info;
    Node* next;
};

class linked_list {



public:
    linked_list(); //constructor
    ~linked_list(); //destructor
    bool estacheia(); 
    bool estavazia();
    void inserir(TipoItem item,bool& DeuCerto);
    TipoItem remover(bool& DeuCerto,TipoItem item); 
    void imprimir();//print;
    int qualtamanho();

    //operações nao primitivas reaproveitadas de outros exercicios
    void Juncao_Elementos(linked_list& fila1,linked_list& fila2,linked_list& fila3);
   
    bool Mais_Elementos( linked_list& fila1,linked_list& fila2);
private:
    
    Node* primeiro;//front
    Node* ultimo;//rear

};
