#include <stdio.h>
#include <string.h>
char L1[4000000],L2[10000];
int get[2000000]={0};
int main(){
    int i=0;
    while((L1[i]=getchar())!='\n'){i++;}
    for(int j=0;j<i;j++){
        L1[i+j]=L1[j];
    }
    scanf("%s",&L2);
    int p1=0,p2=0,init=2*i;
    start:;
    while(L2[p2]!='\0'){
        while(1){
            if(p1>=init+i){
                p1=init+1;
                p2=0;
                init=2*i;
                for(int j=0;j<i;j++){
                    get[j]=0;
                }
                goto start;
            }
            if(L1[p1]==L2[p2]){
                if(init==2*i){init=p1;}
                if(p1>=i){get[p1-i]=1;}
                if(p1<i){get[p1]=1;}
                p2++;
                p1++;
                break;
            }
            p1++;
        }
    }
    i=0;
    for(;i<2000000;i++){
        if(get[i]==1){
            printf("%d",i+1);
            i++;
            break;
        }
    }
    for(;i<2000000;i++){
        if(get[i]==1){
            printf(" %d",i+1);
        }
    }
    printf("\n");
    return 0;
}