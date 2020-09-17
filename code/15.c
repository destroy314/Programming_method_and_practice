#include <stdio.h>
#include <stdlib.h> 
struct dragon{
    int x;
    int y;
    int xy;
};
int cmpx(const void *a ,const void *b){//返回正数b排在前，返回负数a排在前
    return (*(struct dragon *)a).x > (*(struct dragon *)b).x ? 1 : -1;//升序排列
}
int cmpxy(const void *a ,const void *b){
    return (*(struct dragon *)a).xy < (*(struct dragon *)b).xy ? 1 : -1;
}
int main(){
    int n;
    scanf("%d",&n);
    struct dragon pdragon[n],ndragon[n];
    int x,y,a=0,b=0;
    for(int i=0;i<n;i++){
        scanf("%d %d",&x,&y);
        if(y>=0){
            pdragon[a++].x=x;
            pdragon[a-1].y=y;
            pdragon[a-1].xy=x+y;
        }
        if(y<0){
            ndragon[b++].x=x;
            ndragon[b-1].y=y;
            ndragon[b-1].xy=x+y;
        }
    }
    qsort(pdragon,a,sizeof(pdragon[0]),cmpx);
    qsort(ndragon,b,sizeof(ndragon[0]),cmpxy);
    long long int money=0,A=0;
    for(int i=0;i<a;i++){
        if(A>=pdragon[i].x){
            A+=pdragon[i].y;
            continue;
        }
        money+=pdragon[i].x-A;
        A=pdragon[i].xy;
    }
    for(int i=0;i<b;i++){
        if(A>=ndragon[i].x){
            A+=ndragon[i].y;
            continue;
        }
        money+=ndragon[i].x-A;
        A=ndragon[i].xy;
    }
    printf("%lld\n",money);
    return 0;
}