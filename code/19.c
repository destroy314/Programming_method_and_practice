#include <stdio.h>
int a[200001];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int p=0;
        for(int i=0;i<n;i++){
            int height;
            scanf("%d",&height);
            if(p==0){
                a[p++]=height;
                continue;
            }
            if(height%2==a[p-1]%2){//奇偶性相同pop
                p--;
            }
            else if(height%2!=a[p-1]%2){
                a[p++]=height;
            }
        }
        if(p<=1){printf("YES\n");}
        else{printf("NO\n");}
    }
    return 0;
}