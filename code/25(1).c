#include <stdio.h>
#define mod 2147483647
long long int num[2002];
int N;
long long int dp[2002][3000];//第i块木头的底部在j时的可能性数量
long long int MEMS(long long int layer,long long int tail){//是记忆化搜索不是微机电系统
    if(layer>N){return 1;}//所有木板都被加入
    if(dp[layer][tail]){return dp[layer][tail];}//先在记忆里寻找
    long long int i=num[layer-1]<tail?num[layer-1]:tail;
    long long int j=num[layer-1]>tail?num[layer-1]:tail;//分别是上一层木板的头尾，i是靠左的
    if(num[layer]>i){//这层木板箭头的位置可能在上一层木板左边、右边或是中间，分别对应1，1，2种可能；而这种做法把它们都兼顾了
        dp[layer][tail]=(dp[layer][tail]+MEMS(layer+1,i))%mod;
    }
    if(num[layer]<j){
        dp[layer][tail]=(dp[layer][tail]+MEMS(layer+1,j))%mod;
    }
    return dp[layer][tail];
}
int main(){
    scanf("%d",&N);
    for(int i=0;i<N+1;i++){
        scanf("%lld",&num[i]);
    }
    printf("%lld\n",MEMS(2,num[0]));
    return 0;
}

//好家伙，直接手把手教学http://lexue.bit.edu.cn/mod/forum/discuss.php?d=127304