//乐学UTF8输入
#include <stdio.h>
#include <math.h>
int character[65536];
int j=0;
unsigned char input[50000000]={0};
int adduni2(int a,int b){
    int sum=(a-64-128)*64+(b-128);
    if(character[sum]!=0){
        character[sum]++;
        j++;
        return 0;
    }
    character[sum]=1;
    return 0;
}
int adduni3(int a,int b,int c){
    int sum=(a-32-64-128)*pow(2,12)+(b-128)*64+(c-128);
    if(character[sum]!=0){
        character[sum]++;
        j++;
        return 0;
    }
    character[sum]=1;
    return 0;
}
int main(){
    for(int i=0;i<65536;i++){character[i]=0;}
    while(scanf("%s",&input)!=EOF){
        for(int i=0;input[i]!='\0';i++){
            if(input[i]<128){continue;}
            if(input[i]<224){
                adduni2(input[i],input[i+1]);
                i+=1;
                continue;
            }
            adduni3(input[i],input[i+1],input[i+2]);
            i+=2;
        }
    }
    if(j==0){
        printf("No repeat!\n");
        return 0;
    }
    for(int i=0;i<65536;i++){
        if(character[i]<=1){continue;}
        unsigned char a[3];
        if(i>=2048){
            a[0]=i/4096+32+64+128;
            a[1]=(i/64)%64+128;
            a[2]=i%64+128;
            printf("%c%c%c ",a[0],a[1],a[2]);
        }
        if(i<2048){
            a[0]=i/64+64+128;
            a[1]=i%64+128;
            printf("%c%c ",a[0],a[1]);
        }
        printf("0x%0 4x ",i);
        printf("%d\n",character[i]);
    }
    return 0; 
}