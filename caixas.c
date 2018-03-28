#include<stdio.h>
#include<stdlib.h>

typedef struct caixa{
    int a, l, p, pos;
}caixa;

caixa v[1000000+1];

int compara(const void *a, const void *b){
    return ((*(caixa*)b).l * (*(caixa*)b).p) - (*(caixa*)a).l * (*(caixa*)a).p;
}


int main(int argc, char* argv[]){

    int n=0;//numero de caixas

    do{
        scanf("%d %d %d", &v[n].a, &v[n].l, &v[n].p);
        v[n].pos=n+1;
        ++n;
    }
    while(getchar() != EOF);
    
    qsort(v, n, sizeof(caixa), compara);//ordena pela area da base
    
    int bx[n], mx[n];
    
    for(int i=0;i<n;++i){
        bx[i]=i;
        mx[i]=v[i].a;
    }
    
    for(int i=1;i<n;++i){
        for(int j=0;j<i;++j){
            if(v[i].p < v[j].p && v[i].l < v[j].l && ((v[i].a + mx[j]) > mx[i])){
                mx[i]=mx[j]+v[i].a;
                bx[i]=j;
            }
        }
    }

    int max=0;

    for(int i=1;i<n;++i){
        if(mx[max]<mx[i])
            max=i;
    }

    int k=1, aux=max;

    while(bx[aux]!=aux){
        aux=bx[aux];
        ++k;
    }
    
    int ind[k];
    
    for(int i=0;i<k;++i){
        ind[i]=v[max].pos;
        max=bx[max];
    }

    for(int i=0;i<k;++i){
        printf("%d\n", ind[i]);
    }
}