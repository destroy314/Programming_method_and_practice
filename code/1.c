#include <stdio.h> 
unsigned long long expo(int base,int index){
    unsigned long long re=1;
    for(int i=0;i<index;i++){
        re*=base;
    }
    return re;
}
int main() 
{ 
    unsigned long long a[100];
    int i;
    for(i=0;i<=60;i++){
        a[i]=expo(2,i);
    }

    unsigned long long n;
    int T,j;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%llu",&n);
        for(j=0;a[j]<n;j++){}
        printf("%d\n",j);
    }
    return 0;
}  

/*%lld和%llu是linux下gcc/g++用于long long int类型(64 bits)输入输出的格式符。
而%I64d和%I64u则是Microsoft VC++库里用于输入输出__int64类型的格式说明。
在我的电脑（mingw）上两种都可以用，但乐学的服务器不认识%I64u。*/