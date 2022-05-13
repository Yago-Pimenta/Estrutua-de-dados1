//FILA ENCADEADA NAO CIRCULAR ORDENADA


//convém resesaltar que estamos implementando essa fila , como sendo uma lista encadeada com dois ponteiros
//próprios dela um apontando para a primeira posição e outra apontando para a ultima
//estamos utilizando uma struct Node para ajudar na implementação

struct Node{
    //cada "pedaço" da minha lista vai ter um valor(info) e o endereço do proximo elemento(next)
    int idade;
    Node* next;
};

class fila_encadeada {



public:
    fila_encadeada(); //constructor
    ~fila_encadeada(); //destructor
    bool estacheia(); 
    bool estavazia();
    void inserir(int item);//enqueue
    
    void imprimir();//print;
    int qualtamanho();

private:
    
    Node* FV;//front Fv a pedido do exercicio
    Node* ultimo;//rear

};
