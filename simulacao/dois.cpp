void BubbleSort(int *v,int n){
int i,j,aux,pos_ult,lim_dir;
lim_dir = n ;
for(j=0;j<n;j++){
    pos_ult = 0;
    for(i=1;i<lim_dir;i++){
        if(v[i-1]>v[i]){
            aux=v[i-1];
            v[i-1]=v[i];
            v[i]=aux;
            pos_ult = i;
        }
        
    }
    lim_dir = pos_ult ;
}
}