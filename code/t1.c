#include <stdio.h>
#include <locale.h>
int main(){
    unsigned char a[5];
    scanf("%s",&a[0]);
    printf("%x,%x,%x,%x\n",a[0],a[1],a[2],a[3]);
    getchar();
    setlocale(LC_ALL,"chs");
    wchar_t input[10]={0};
    wscanf(L"%c",input);
    wprintf(L"%x",input);
    return 0;
}