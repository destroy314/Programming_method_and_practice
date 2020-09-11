#include <stdio.h>
int main(){
    int input,insentence=0;
    while(scanf("%c",&input)!=EOF){
        if('A'<=input&&input<='Z'){
            if(insentence==0){insentence=1;goto output;}
            input+=32;
            goto output;
        }
        if('a'<=input&&input<='z'){
            if(insentence==1){goto output;}
            insentence=1;
            input-=32;
            goto output;
        }
        if(input=='.'||input=='!'||input=='?'){
            insentence=0;
        }
        output:;
        printf("%c",input);
    }
    return 0;
}