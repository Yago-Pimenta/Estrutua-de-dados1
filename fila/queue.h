

typedef int tipo_da_variavel;
//defini que o tamanho maximo desse "array circular" é 20
//Ou seja NAO irei fixar o primeiro elemento a posição 1 do array
const int max_itens = 20;
class queue {
private:
    //diferentemente da pilha eu preciso saber o valor da posição do primeiro
    // e tambem do ultimo elemento , afim de poder alocar bem meus elementos
    int primeiro,ultimo;
    tipo_da_variavel* vetor;


public:
//basicamente sao os mesmos métodos ja usadas com pilhas muda apenas a implementação
    queue(); //constructor
    ~queue(); //destructor
    bool esta_cheia(); //isempty
    bool esta_vazia(); //isfull
    void inserir(tipo_da_variavel item,bool& DeuCerto);//enqueue
    void remover(tipo_da_variavel& item,bool& DeuCerto);// dequeue
    void imprimir();//print;
    void qualtamanho();//lenght


};