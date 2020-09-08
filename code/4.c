#include <stdio.h>
int main(){
    int a[100001];
    int n,h,i;
    long long sum=0;
    scanf("%d %d",&n,&h);
    for(i=0;i<n-1;i++){
        scanf("%d ",&a[i]);
    }
    scanf("%d",&a[n-1]);
    a[n]=h;
    for(int j=0;j<n;j++){
        if(a[j]<a[j+1]){sum+=a[j+1]-a[j];}
    }
    printf("%lld\n",sum);
    return 0;
}