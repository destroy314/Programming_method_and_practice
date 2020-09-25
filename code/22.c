#include <stdio.h>
#include <stdlib.h>
int maze[102][102];//迷宫地图
int tag[102][102];//位置标记，已经标记的位置不能再走
int arrive[102][102];//到达某位置的最短时间
int min_step;//最短时间
int dis;//怪物消失周期
int start[2],end[2];
int DFS();
int rec(int j,int k,int t){
    tag[j][k]=1;
    int r=DFS(j,k,t);
    tag[j][k]=0;
    return r;
}
int DFS(int j,int k,int t){//搜索开始的行，列，当前用时
    //printf("arrive%d,%dwhent=%d\n",j,k,t);
    if(t>=min_step||t-arrive[j][k]>dis){
        return 1;
    }
    arrive[j][k]=t;
    if(j==end[0]&&k==end[1]){
        min_step=t;
        return 0;
    }
    int step_up=1,step_left=1,step_down=1,step_right=1;

    if((maze[j-1][k]=='.')&&tag[j-1][k]!=1){//按照上、左、下、右的顺序
        step_up=rec(j-1,k,t+1);
    }
    else if(maze[j-1][k]=='*'&&tag[j-1][k]!=1){//遇到怪物，判断能否通过，能通过则时间设为最短通过时间
        if((t+1)%dis==0){
            step_up=rec(j-1,k,t+1);
        }
        else if((((t+1)/dis+1)*dis-(t+1))%2==0){
            step_up=rec(j-1,k,((t+1)/dis+1)*dis);
        }
        else if((((t+1)/dis+2)*dis-(t+1))%2==0){
            step_up=rec(j-1,k,((t+1)/dis+2)*dis);
        }
    }

    if((maze[j][k-1]=='.')&&tag[j][k-1]!=1){
        step_left=rec(j,k-1,t+1);
    }
    else if(maze[j][k-1]=='*'&&tag[j][k-1]!=1){
        if((t+1)%dis==0){
            step_left=rec(j,k-1,t+1);
        }
        else if((((t+1)/dis+1)*dis-(t+1))%2==0){
            step_left=rec(j,k-1,((t+1)/dis+1)*dis);
        }
        else if((((t+1)/dis+2)*dis-(t+1))%2==0){
            step_left=rec(j,k-1,((t+1)/dis+2)*dis);
        }
    }

    if((maze[j][k+1]=='.')&&tag[j][k+1]!=1){
        step_right=rec(j,k+1,t+1);
    }
    else if(maze[j][k+1]=='*'&&tag[j][k+1]!=1){
        if((t+1)%dis==0){
            step_right=rec(j,k+1,t+1);
        }
        else if((((t+1)/dis+1)*dis-(t+1))%2==0){
            step_right=rec(j,k+1,((t+1)/dis+1)*dis);
        }
        else if((((t+1)/dis+2)*dis-(t+1))%2==0){
            step_right=rec(j,k+1,((t+1)/dis+2)*dis);
        }
    }

    if((maze[j+1][k]=='.')&&tag[j+1][k]!=1){
        step_down=rec(j+1,k,t+1);
    }
    else if(maze[j+1][k]=='*'&&tag[j+1][k]!=1){
        if((t+1)%dis==0){
            step_down=rec(j+1,k,t+1);
        }
        else if((((t+1)/dis+1)*dis-(t+1))%2==0){
            step_down=rec(j+1,k,((t+1)/dis+1)*dis);
        }
        else if((((t+1)/dis+2)*dis-(t+1))%2==0){
            step_down=rec(j+1,k,((t+1)/dis+2)*dis);
        }
    }

    if(step_up==0||step_right==0||step_down==0||step_left==0){
        //printf("%d,%dreturn0\n",j,k);
        return 0;
    }
    else{
        //printf("%d,%dreturn1\n",j,k);
        return 1;
    }
}
int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        min_step=10000;
        int n,m;
        scanf("%d %d %d",&n,&m,&dis);
        for(int j=0;j<n+2;j++){//读取迷宫地图，外围用#包裹
            for(int k=0;k<m+2;k++){
                if(j==0||j==n+1||k==0||k==m+1){
                    maze[j][k]='#';
                    arrive[j][k]=0;
                    continue;
                }
                maze[j][k]=getchar();
                if(maze[j][k]=='S'){
                    maze[j][k]='.';
                    start[0]=j;
                    start[1]=k;
                }
                if(maze[j][k]=='E'){
                    maze[j][k]='.';
                    end[0]=j;
                    end[1]=k;
                }
                tag[j][k]=0;
                arrive[j][k]=10000;
            }
            if(j!=n+1){getchar();}
        }/*
        for(int j=0;j<n+2;j++){
            for(int k=0;k<m+2;k++){
                printf("%c",maze[j][k]);
            }
            printf("\n");
        }*/
        tag[start[0]][start[1]]=1;
        int R=DFS(start[0],start[1],0);
        if(R==1){
            printf("-1\n");
            continue;
        }
        else{
            printf("%d\n",min_step);
            continue;
        }
    }
    return 0;
}

//DFS，只能过第一个样例