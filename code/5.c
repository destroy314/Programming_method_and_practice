#include <stdio.h>
int main(){
    int u[100000],d[100000];
    int T,n;
    long long durt=0,sum=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d",&n);
        durt=0;
        sum=0;
        for(int j=0;j<n-1;j++){
            scanf("%d ",&u[j]);
            d[j]=u[j];
            durt+=u[j];
        }
        scanf("%d",&u[n-1]);
        durt+=u[n-1];
        d[n-1]=u[n-1];
        for(int up=0;up<n-1;up++){
            if(u[up]>u[up+1]){u[up+1]=u[up];}
        }
        for(int down=n-1;down>0;down--){
            if(d[down]>d[down-1]){d[down-1]=d[down];}
        }
        for(int j=0;j<n;j++){
            u[j]=u[j]<d[j]?u[j]:d[j];
            sum+=u[j];
        }
        printf("%lld\n",sum-durt);
    }
}