#include <stdio.h>
#include <string.h>
int find(char arr[100000],int num,int len){
    if(0<=num&&num<len){
        return(arr[num]);
    }
    else{
        return 48;
    }
}
char a[100001],b[100001];
int result[100001];
int main(){
    int T,j;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%s %s",a,b);
        int enda=strlen(a)-1;
        int endb=strlen(b)-1;
        int max=enda>endb?enda:endb;
        for(int i=0;i<max+2;i++){
            result[i]=0;
        }
        for(j=0;j<=max;j++){
            result[j]+=find(a,enda-j,enda+1)+find(b,endb-j,endb+1)-96;
            if(result[j]>1){
                result[j]-=2;
                result[j+1]=1;
            }
        }
        if(result[max+1]==1){max+=1;}
        max++;
        for(j=0;j<max+1-enda;j++){printf(" ");}
        printf("%s\n+",a);
        for(j=0;j<max-endb;j++){printf(" ");}
        printf("%s\n",b);
        for(j=0;j<max+2;j++){printf("-");}
        printf("\n  ");
        for(j=max-1;j>=0;j--){printf("%d",result[j]);}
        printf("\n");
    }
    return 0;
}