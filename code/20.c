#include <stdio.h>
int start[200001];
int main(){
    int n;
    init:;
    while(scanf("%d",&n)!=EOF){
        int ps=0,max=0,no=0;
        for(int i=0;i<n;i++){
            int height;
            scanf("%d",&height);
            if(ps==0){
                start[ps++]=height;
                continue;
            }
            if(height==start[ps-1]){
                max=max>height?max:height;
                ps--;
            }
            else if(height!=start[ps-1]){
                if(height>start[ps-1]){
                    no=1;
                    continue;
                }
                start[ps++]=height;
            }
        }
        if(no==1){
            printf("NO\n");
        }
        else if(ps==0){
            printf("YES\n");
        }
        else if(ps>=2){
            printf("NO\n");
        }
        else if(start[0]<max){
            printf("NO\n");
        }
        else{printf("YES\n");}
    }
    return 0;
}