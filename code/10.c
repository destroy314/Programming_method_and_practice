#include <stdio.h>
int arr[2000000]={0};
int main(){
    int n,sleft,sright,sum=0;
    scanf("%d",&n);
    getchar();
    char input;
    for(int i=0;i<n;i++){
        sleft=0,sright=0;//左右括号总数
        while((input=getchar())!='\n'){
            if(input=='('){sleft++;}
            if(input==')'){
                if(sleft==0){sright++;}
                if(sleft>0){sleft--;}//右括号抵消左括号
            }
        }
        if(sleft!=0&&sright!=0){
            continue;
        }
        if(sleft!=0){
            arr[1000000-sleft]++;
            continue;
        }
        if(sright!=0){
            arr[1000000+sright]++;
            continue;
        }
        if(sleft==0&&sright==0){
            arr[1000000]++;
        }
    }
    sum+=arr[1000000]/2;
    for(int i=1;i<n;i++){
        sum+=arr[1000000-i]<arr[1000000+i]?arr[1000000-i]:arr[1000000+i];
    }
    printf("%d\n",sum);
    return 0;
}