#include <stdio.h>
int height[1000000],position[1000000],color[1000000],countcolor[1000001];
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        for(int j=0;j<1000001;j++){
            countcolor[j]=0;
        }
        int ph=0;//对应栈末尾
        int pc;
        int sumcolor=0;
        int n;
        scanf("%d",&n);
        for(int j=0;j<n;j++){
            scanf("%d",&color[j]);
        }
        for(int j=0;j<n;j++){
            pc=j;
            int h;
            scanf("%d",&h);
            if(ph==0&&sumcolor==0){
                height[ph]=h;
                position[ph]=j;
                goto jcolor;
            }
            else if(height[ph]>h){
                height[++ph]=h;//push
                position[ph]=j;//存入楼的位置，方便查找其颜色
                goto jcolor;
            }
            for(;height[ph]<=h;ph--){//pop
                countcolor[color[position[ph]]]--;
                if(countcolor[color[position[ph]]]==0){sumcolor--;}
                if(ph==0){break;}
            }
            if(ph==0&&height[ph]<=h){
                height[ph]=h;
                position[ph]=j;
            }
            else{
                height[++ph]=h;
                position[ph]=j;
            }
            jcolor:;
            if(countcolor[color[j]]==0){
                sumcolor++;
            }
            countcolor[color[j]]++;
            printf("%d",sumcolor);
            if(j!=n-1){printf(" ");}
        }
        printf("\n");
    }
    return 0;
}