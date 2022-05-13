#include <iostream>

//sugestao ao inves de implementar com struct tentar um class para ele 
struct Node
{
    int cpf; 
    Node *dir;
    Node *esq;
};

class BinaryTree
{
    // BST binary seacrch tree
public:
    BinaryTree();

    virtual ~BinaryTree();
    void deletar(Node *Atual);
    Node *obterRaiz();
    bool estavazio();
    bool estacheio();
    void inserir(Node* temp,int cpf,bool& ok);
    void remove(Node* R,int &cpf,bool& ok);
    bool EstaNaArvore(Node* R,int &cpf);
    void imprimirPreOrdem(Node *Atual);
    void imprimirEMOrdem(Node *Atual);
    void imprimirPOSOrdem(Node *Atual);
    int soma(Node* R);
    int altura(Node* R);
    bool temAlguemMaior(Node* R,int cpf);
    bool temAlguemMenor(Node* R,int cpf);
    
    

    Node *raiz;
};