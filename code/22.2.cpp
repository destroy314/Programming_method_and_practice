#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;
deque<int> sj;//搜索队列j
deque<int> sk;//搜索队列k
deque<int> st;//坐标对应的时间
deque<int> sy;
//四个队列同时操作，保证在相同位置的数字描述同一个节点
int maze[102][102];//迷宫地图
int tag[102][102][50];//坐标，时间对k取模
int sum,newsum;
void addin(int j,int k,int t,int y){
    if(tag[j][k][y]==0){
        tag[j][k][y]=1;
        sj.push_back(j);
        sk.push_back(k);
        st.push_back(t);
        sy.push_back(y);
        newsum++;
    }
}
int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n,m,dis;
        scanf("%d %d %d",&n,&m,&dis);
        int start[2],end[2];
        for(int j=0;j<n+2;j++){//读取迷宫地图，外围用#包裹
            for(int k=0;k<m+2;k++){
                if(j==0||j==n+1||k==0||k==m+1){
                    maze[j][k]='#';
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
                if(maze[j][k]=='*'&&dis==1){
                    maze[j][k]='.';
                }
                for(int l=0;l<50;l++){
                    tag[j][k][l]=0;
                }
            }
            if(j!=n+1){getchar();}
        }
        sj.push_back(start[0]);
        sk.push_back(start[1]);
        st.push_back(0);
        sy.push_back(0);
        tag[start[0]][start[1]][0]++;
        int nj=sj.front();//当前节点的j,k
        int nk=sk.front();
        sum=1;
        while(1){
            newsum=0;
            for(int k=0;k<sum;k++){//把上一次压入的节点的子节点压入队列，然后弹出旧节点
                int nt=st.front();//当前节点的t
                nj=sj.front();
                nk=sk.front();
                sj.pop_front();
                sk.pop_front();
                st.pop_front();
                sy.pop_front();

                if(nj==end[0]&&nk==end[1]){
                    printf("%d\n",nt);
                    goto end;
                }
                tag[nj][nk][nt%dis]=1;

                //按照上、左、下、右的顺序查找子节点
                if(maze[nj-1][nk]=='.'&&tag[nj-1][nk][(nt+1)%dis]==0){
                    addin(nj-1,nk,nt+1,(nt+1)%dis);
                }
                else if(maze[nj-1][nk]=='*'&&maze[nj][nk]!='*'&&tag[nj-1][nk][(nt+1)%dis]==0&&(nt+1)%dis==0){
                    addin(nj-1,nk,nt+1,(nt+1)%dis);
                }

                if(maze[nj][nk-1]=='.'&&tag[nj][nk-1][(nt+1)%dis]==0){
                    addin(nj,nk-1,nt+1,(nt+1)%dis);
                }
                else if(maze[nj][nk-1]=='*'&&maze[nj][nk]!='*'&&tag[nj][nk-1][(nt+1)%dis]==0&&(nt+1)%dis==0){
                    addin(nj,nk-1,nt+1,(nt+1)%dis);
                }

                if(maze[nj+1][nk]=='.'&&tag[nj+1][nk][(nt+1)%dis]==0){
                    addin(nj+1,nk,nt+1,(nt+1)%dis);
                }
                else if(maze[nj+1][nk]=='*'&&maze[nj][nk]!='*'&&tag[nj+1][nk][(nt+1)%dis]==0&&(nt+1)%dis==0){
                    addin(nj+1,nk,nt+1,(nt+1)%dis);
                }

                if(maze[nj][nk+1]=='.'&&tag[nj][nk+1][(nt+1)%dis]==0){
                    addin(nj,nk+1,nt+1,(nt+1)%dis);
                }
                else if(maze[nj][nk+1]=='*'&&maze[nj][nk]!='*'&&tag[nj][nk+1][(nt+1)%dis]==0&&(nt+1)%dis==0){
                    addin(nj,nk+1,nt+1,(nt+1)%dis);
                }

                if(sj.empty()==true){
                    printf("-1\n");
                    goto end;
                }
            }
            sum=newsum;
        }
        end:;
        sj.clear();
        sk.clear();
        st.clear();
    }
    return 0;
}

//三维vis数组的BFS