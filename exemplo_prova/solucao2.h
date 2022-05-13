
//tal como o enunciado tem que ser uma fila  encadeada com um unico ponteiro FV circular
struct Node{
    //cada "pedaço" da minha lista vai ter um valor(info) e o endereço do proximo elemento(next)
    int info;
    Node* next;
    Node* ant;
};

class FILA {



public:
    FILA(); //constructor
    ~FILA(); //destructor

    void Insere(FILA& FilaDeVacinacao , int idade);
    void Remover(FILA& FilaDeVacinacao, int& idade);
    void imprimir(FILA& FilaDeVacinacao);//print;
    

private:
    
    Node* FV;//aponta sempre para o primeiro elemento
    

};
