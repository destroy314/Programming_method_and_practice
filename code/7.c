//windows下GBK输入
#include <stdio.h>
#include <locale.h>
int character[65536]={0};
int j=0;
int add(int l){
    if(character[l]!=0){
        character[l]++;
        j++;
        return 0;  
    }
    character[l]=1;
    return 0;
}
int main(){
    setlocale(LC_ALL,"chs");
    wchar_t input[10];
    while(wscanf(L"%c",input)!=EOF){//强制以Unicode输入
        if(input[0]<127){continue;}
        add(input[0]);
        if(input[0]==24494){break;}
    }
    if(j==0){
        printf("No repeat!\n");
        return 0;
    }
    for(int i=0;i<65536;i++){
        if(character[i]<=1){continue;}
        wprintf(L"%c ",i);//强制以Unicode输出
        wprintf(L"0x%0 4x ",i);
        printf("%d\n",character[i]);
    }
    return 0; 
} 