#include <stdio.h>
int beauti[500001]={0};
long long int dp[4][500001];//dp[i][j]表示前j个人选出i队且最后一队包含第j个人时的最大美丽度
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<n+1;i++){
        scanf("%d",&beauti[i]);
    }
    for(int i=0;i<n+1;i++){
        dp[0][i]=0;
    }
    long long int max=0;
    for(int i=1;i<4;i++){
        for(int j=i;j<n+1;j++){
            if(i==j){
                dp[i][j]=dp[i-1][j-1]+beauti[j];//i,j从1开始，这样比它小的就默认是0了
            }
            else{//此时有两种情况：前面有i-1队或前面有i队。
                max=max>dp[i-1][j-1]?max:dp[i-1][j-1];//使用max储存第一种情况时前面所有dp的最大美丽度
                dp[i][j]=max>dp[i][j-1]?max:dp[i][j-1];//与第二种情况比较选择较大的
                dp[i][j]+=beauti[j];
            }
        }
        max=dp[i][i];
    }
    for(int i=3;i<n+1;i++){
        max=max>dp[3][i]?max:dp[3][i];
    }
    printf("%lld\n",max);
    return 0;
}

//http://lexue.bit.edu.cn/mod/forum/discuss.php?d=127746