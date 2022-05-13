typedef char TipoItem;
//hoje irei fazer com char
struct Node{
    //cada "pedaço" da minha lista vai ter um valor(info) e o endereço do proximo elemento(next)
    TipoItem info;
    Node* next;
};

class fila_encadeada {



public:
    fila_encadeada(); //constructor
    ~fila_encadeada(); //destructor
    bool estacheia(); 
    bool estavazia();
    void inserir(TipoItem item,bool& DeuCerto);//enqueue
    TipoItem remover(bool& DeuCerto); //dequeue
    void imprimir();//print;
    int qualtamanho();

    //operações nao primitivas reaproveitadas de outros exercicios
    void Juncao_Elementos(fila_encadeada& fila1,fila_encadeada& fila2,fila_encadeada& fila3);
   
    bool Mais_Elementos( fila_encadeada& fila1,fila_encadeada& fila2);
private:
    
    Node* primeiro;//front
    Node* ultimo;//rear

};
