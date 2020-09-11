#include <stdio.h>
int main(){
    int L,A[100002],i=0,e=0;
    scanf("%d",&L);
    getchar();
    while((A[i]=getchar())!='\n'){
        i++;
    }//此时A有i位
    again:;
    if(i%L!=0){
        for(int j=0;j<i/L+1;j++){
            printf("1");
            for(int k=0;k<L-1;k++){
                printf("0");
            }
        }
        printf("\n");
        return 0;
    }
    int node[L+1];//循环节
    for(int j=0;j<L;j++){
        node[j]=A[j];
    }
    node[L]='\n';
    for(int j=0;j<i/L;j++){
        for(int k=0;k<L;k++){
            if(node[k]>A[L*j+k]){goto stop;}
            if(node[k]<A[L*j+k]){
                node[L-1]++;
                for(int l=L-1;l>0;l--){//进位
                    if(node[l]>'9'){
                        node[l]='0';
                        node[l-1]++;
                    }
                }
                goto endloop;
            }
            if(node[k]==A[L*j+k]){e++;}
        }
    }
    stop:;
    if(e==i){
        A[i-1]++;
        for(int j=i-1;j>0;j--){
            if(A[j]>'9'){
                A[j]='0';
                A[j-1]++;
            }
        }
        if(A[0]>'9'){
            for(int j=i;j>0;j--){
                A[j]=A[j-1];
            }
            A[0]='1';
            A[1]='0';
            i++;
        }
        goto again;
    }
    endloop:;
    for(int j=0;j<i/L;j++){
        int k=0;
        while(node[k]!='\n'){
            putchar(node[k]);
            k++;
        }
    }
    printf("\n");
    return 0;
}