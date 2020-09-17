#include <stdio.h>
int handcard[200001]={0},drawtablecard[200001]={0},tablecardp[200001]={0};
int main(){
    int n,start=-10,e=0,situation=0,temp;
    int end;//牌堆底部
    scanf("%d",&n);
    int tablecard[n];
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        if(temp==1){situation=3;}//情况3：1在手牌中
        handcard[temp]=1;
    }
    for(int i=0;i<n;i++){
        scanf("%d",&tablecard[i]);
        tablecardp[tablecard[i]]=i;
        if(tablecard[i]==1){
            start=i-1;
        }
        if(start!=-10){
            if(tablecard[start+1]+i-start-1==tablecard[i]){continue;}
        }
        if(start==-10){continue;}
        situation=2;//情况2：1在牌堆中，但之后的牌不按顺序
    }
    if(situation==0){situation=1;}//情况1：1在牌堆中，且之后的牌按顺序
    end=tablecard[n-1];
    if(situation==1){
        for(int i=end+1;i<=n;i++){
            
            if(handcard[i]==1||drawtablecard[i]==1){
                drawtablecard[tablecard[i-end-1]]=1;
                continue;
            }
            printf("%d\n",n+start+2);
            return 0;
        }
        printf("%d\n",start+1);
        return 0;
    }
    int t=0;
    if(situation==2){
        t=start+2;
    }
    int draw,max=0;
    for(int i=2;i<=n;i++){
        if(handcard[i]==1){continue;}
        draw=tablecardp[i]+1-i+1-t;
        max=max>draw?max:draw;
    }
    printf("%d\n",max+t+n);
    return 0;
}

//屎山