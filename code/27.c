#include <stdio.h>
int main(){
    int n,V;
    scanf("%d %d",&n,&V);
    int p[2000];
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
        p[i]%=V;
        if(!p[i]){p[i]=V;}
    }
    int dp[2][2001];//第一行是旧，第二行是新；dp[][j]表示使总体积%V后得j的取法总数
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<V;j++){
            dp[1][(j+p[i])%V]=dp[0][(j+p[i])%V]+dp[0][j];
        }
        for(int j=0;j<V+1;j++){
            dp[0][j]=dp[1][j]%10000000;//计算完用新覆盖旧
        }
    }
    printf("%d\n",dp[0][0]-1);//dp[0][0]既储存了总体积为V的倍数的取法总数，又储存了代表不取当前物体的1，后者要减去
    return 0;
}

/*
dp[i]=dp[i]+dp[i-p]
输入：
4 5↵
1 2 3 2

dp   0 1 2 3 4
init 1 0 0 0 0
add1 1 1 0 0 0
add2 1 1 1 1 0
add3 2 2 1 2 1
add2 4 3 3 4 2
ans=3
只需要储存两行就够了
*/