#include <stdio.h>
#include <math.h>
int light[16][16],test[16][16];
int m,n,step=0,min=10000;
void edit(int y,int x){
    test[y][x]=test[y][x]==1?0:1;
    if(x-1>=0){test[y][x-1]=test[y][x-1]==1?0:1;}
    if(x+1<m){test[y][x+1]=test[y][x+1]==1?0:1;}
    if(y+1<n){test[y+1][x]=test[y+1][x]==1?0:1;}
    step++;
}
int main(){ 
    scanf("%d %d",&n,&m);
    getchar();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            light[i][j]=getchar()-'0';
        }
        getchar();
    }
    for(int init=0;init<pow(2,m);init++){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                test[i][j]=light[i][j];
            }
        }
        for(int i=0;i<m;i++){
            if(((init>>i)&1)==1){edit(0,i);}
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(test[i-1][j]==1){edit(i,j);}
            }
        }
        for(int j=0;j<m;j++){
            if(test[n-1][j]==1){goto end;}
        }
        min=step<min?step:min;
        end:step=0;
    }
    printf("%d\n",min);
    return 0;
}