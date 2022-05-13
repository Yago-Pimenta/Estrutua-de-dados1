
typedef int tipo_da_variavel;
//defini que o tamanho maximo dessa pilha será 20 , já que o exercicio nao deixou especificado
const int max_itens = 20;
class pilha
{
private:
    int posicao_Topo;
    tipo_da_variavel *vetor;
    

public:
    //OPERAÇÕES PRIMITIVAS:
    pilha();                               //constructor
    ~pilha();                              //destructor
    bool esta_cheia();                     // isfull
    bool esta_vazia();                     //is empty
    void inserir(tipo_da_variavel objeto); //push
    tipo_da_variavel remover();            //pop
   
   //OPERAÇÔES NAO PRIMIIVAS
    void imprimir();                       //print;
    int qualtamanho();                     //lenght

// nao é um método
    bool DeuCerto; //por sugestao do professor
};