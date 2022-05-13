//verificar que o heap maximo é o maior 
#include <iostream>
using namespace std;

//consideração importante , sempre o pai tem que ser maior que o filho . 
#define pai(i) ((i - 1) / 2 )
#define fesq(i) (i * 2 + 1)
#define fdir(i) (i * 2 + 2 )


bool IsHeap(int* V, int LastPosition){

        //vamos ver se existe pelo menos um elemento nesse array
        if(LastPosition<=0){
            return false;
        }


        int i=1;
        //nesse while , vamos garantir que percorra o array inteiro e veja se o pai será sempre maior que o filho
        while(i++ != LastPosition){
            if(V[i]>V[pai(i)]){return false;}
            if(V[0]<V[i]){return false;}
           
            
        }
      return true;

}
int main(){
int V[6]={
    2,8,16,4,7,6
};
bool ok;

ok = IsHeap(V,6);
cout << ok << endl;

    return 0;
}