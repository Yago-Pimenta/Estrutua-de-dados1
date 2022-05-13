#include <iostream>
#include <cstddef>
// IMPORTANTE: aqui ele fez funções publicas e privadas , sendo que nas publicas ele usou o node root
using namespace std;
struct node
{
  int key_value;
  node *left;
  node *right;
};
class btree
{
public:
  btree();
  ~btree();

  void insert(int key);
  node *search(int key);
  void destroy_tree();
  void remove(int key);
  void imprimirPreOrdem();

private:
  // leaf = folhas
  void destroy_tree(node *leaf);
  void insert(int key, node *leaf);
  node *search(int key, node *leaf);
  void remove(int key, node *leaf);
  void imprimirPreOrdem(node *leaf);
  node *root;
};
btree::btree()
{
  // construtor , igual ao que eu tava fazendo
  root = NULL;
}
btree::~btree()
{

  destroy_tree();
}
void btree::destroy_tree(node *leaf)
{
  if (leaf != NULL)
  {
    // igualzinho ao que eu tava fazendo
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}

void btree::insert(int key, node *leaf)
{
  // aqui fala que se o valor que eu for inserir foi menor que o valor do node atual vai percorrer ele
  if (key < leaf->key_value)
  {
    if (leaf->left != NULL) // se o node atual apontando a esquerda for diferente de zero , eu vou chamar a função recursiva para a esquerda
      insert(key, leaf->left);
    // ou seja , irei percorrer a arvore o maximo possivel a esquerda
    else
    {
      // ou seja finalmente achei o lugar em que deve ser inserido
      leaf->left = new node;
      leaf->left->key_value = key;
      leaf->left->left = NULL;  // Sets the left child of the child node to null
      leaf->left->right = NULL; // Sets the right child of the child node to null

      // foi inserido com sucesso
    }
  }
  else if (key >= leaf->key_value)
  // aqui vamos percorrer a arvore a direita
  {
    if (leaf->right != NULL)
      insert(key, leaf->right);
    // maximo a direita ate achar o lugar que eu devo inserir
    else
    {
      leaf->right = new node;
      leaf->right->key_value = key;
      leaf->right->left = NULL;  // Sets the left child of the child node to null
      leaf->right->right = NULL; // Sets the right child of the child node to null
    }
  }
}
node *btree::search(int key, node *leaf)
{
  if (leaf != NULL)
  {
    // exatamente igual ao que eu ja tava procurando
    if (key == leaf->key_value)
      return leaf;
    if (key < leaf->key_value)
      return search(key, leaf->left);
    else
      return search(key, leaf->right);
  }
  else
    return NULL;
}
void btree::insert(int key)
{
  if (root != NULL)
    insert(key, root);
  else
  {
    root = new node;
    root->key_value = key;
    root->left = NULL;
    root->right = NULL;
  }
}
node *btree::search(int key)
{
  return search(key, root);
}
void btree::destroy_tree()
{
  destroy_tree(root);
}
void btree::remove(int key, node *leaf)
{
//pensar na soluçção com um serach para achar o node que tenho que remover , depois disso só remover
}
void btree::remove(int key)
{
  
}
void btree::imprimirPreOrdem(node *leaf)
{
  // recursivo tambem
  // nesse vamos imprimir todos elementos partindo da raiz e indo para esqeurda
  if (leaf != NULL)
  {

    

    imprimirPreOrdem(leaf->left);
    if(leaf->key_value!=0 && leaf->key_value!=1) cout << leaf->key_value << endl;
    imprimirPreOrdem(leaf->right);
  }
}
void btree::imprimirPreOrdem(){
  imprimirPreOrdem(root);
}
int main()
{
  btree tree;
  tree.insert(5);
  tree.insert(15);
  tree.insert(3);
  tree.insert(2);
  tree.insert(16);
  tree.insert(6);
  //tree.remove(3);
  node *leaf;
  leaf = tree.search(2);
  cout << leaf->key_value << endl;
  cout <<endl<<endl;
  
  tree.imprimirPreOrdem();

  return 0;
}