#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
int map[100][12][12];//层数，坐标
struct cord{
    int x1,y1,x2,y2;//这里x代表横坐标，y代表纵坐标，和题目里给的不一样
};
stack<cord> anser;
int vis[12][12];
int n,m;

void swap(int l,cord s){
    int temp=map[l][s.y1][s.x1];
    map[l][s.y1][s.x1]=map[l][s.y2][s.x2];
    map[l][s.y2][s.x2]=temp;
    return;
}

int linked(int l,int y,int x){
    vis[y][x]=1;
    int c=map[l][y][x];
    int num=1;
    if(map[l][y][x-1]==c&&vis[y][x-1]==0){
        num+=linked(l,y,x-1);
    }
    if(map[l][y-1][x]==c&&vis[y-1][x]==0){
        num+=linked(l,y-1,x);
    }
    if(map[l][y][x+1]==c&&vis[y][x+1]==0){
        num+=linked(l,y,x+1);
    }
    if(map[l][y+1][x]==c&&vis[y+1][x]==0){
        num+=linked(l,y+1,x);
    }
    return num;
}

/*dfs查找有几个相连的同色方块*/
int cal(int l, int y,int x){
    for(int i=0;i<n+2;i++){
        for(int j=0;j<m+2;j++){
            vis[i][j]=0;
        }
    }
    return linked(l,y,x);
}

/*dfs删除相连的同色方块*/
void erase(int l,int y,int x){
    int c=map[l][y][x];
    map[l][y][x]='0';
    if(map[l][y][x-1]==c){
        erase(l,y,x-1);
    }
    if(map[l][y-1][x]==c){
        erase(l,y-1,x);
    }
    if(map[l][y][x+1]==c){
        erase(l,y,x+1);
    }
    if(map[l][y+1][x]==c){
        erase(l,y+1,x);
    }
    return;
}

/*将第l层的地图拷贝到l+1层中*/
void copymap(int l){
    for(int i=0;i<n+2;i++){
        for(int j=0;j<m+2;j++){
            map[l+1][i][j]=map[l][i][j];
        }
    }
    return;
}

int dfs(int l,int y,int x){
    if(l==100){return 0;}
    if(map[l][y][x]=='0'){//输入的方块可能为零，这时要寻找下一个不为零的
        y++;
        if(y==n+1){
            y=1;
            x++;
            if(x==m+1){return 1;}
        }
        while(map[l][y][x]=='0'){
            y++;
            if(y==n+1){
                y=1;
                x++;
                if(x==m+1){return 1;}
            }
        }
    }

    if(map[l][y][x+1]=='0'&&map[l][y][x-1]=='0'&&map[l][y+1][x]=='0'&&map[l][y-1][x]=='0'){return 0;}

    int c=map[l][y][x];
    int ny=y+1,nx=x;//下一个非零方块的坐标
    if(ny==n+1){
        ny=1;
        nx++;
        if(nx==m+1){return 0;}
    }
    while(map[l][ny][nx]=='0'){
        ny++;
        if(ny==n+1){
            ny=1;
            nx++;
            if(nx==m+1){return 0;}
        }
    }

    if(dfs(l,ny,nx)==1){return 1;}//不交换

    cord s;
    s.x1=x;
    s.y1=y;

    if(map[l][y][x+1]!='0'&&map[l][y][x+1]!=c){//与右侧交换
        s.x2=x+1;
        s.y2=y;
        swap(l,s);
        int p=cal(l,y,x);
        int q=cal(l,y,x+1);
        if(p>=3||q>=3){
            copymap(l);
            if(p>=3){erase(l+1,y,x);}
            if(q>=3){erase(l+1,y,x+1);}
            anser.push(s);
            if(dfs(l+1,1,1)==1){return 1;}
            else{anser.pop();}
        }
        swap(l,s);
    }

    if(map[l][y+1][x]!='0'&&map[l][y+1][x]!=c){//与下方交换
        s.x2=x;
        s.y2=y+1;
        swap(l,s);
        int p=cal(l,y,x);
        int q=cal(l,y+1,x);
        if(p>=3||q>=3){
            copymap(l);
            if(p>=3){erase(l+1,y,x);}
            if(q>=3){erase(l+1,y+1,x);}
            anser.push(s);
            if(dfs(l+1,1,1)==1){return 1;}
            else{anser.pop();}
        }
        swap(l,s);
    }

    return 0;
}

int main(){
    for(int i=0;i<11;i++){
        for(int j=0;j<11;j++){
            map[0][i][j]='0';
        }
    }
    scanf("%d %d",&n,&m);
    for(int i=0;i<n+2;i++){//读入数据，外围用0包裹
        for(int j=0;j<m+2;j++){
            if(i==0||i==n+1||j==0||j==m+1){
                continue;
            }
            map[0][i][j]=getchar();
            if(map[0][i][j]==' '){map[0][i][j]=getchar();}
        }
        if(i!=n+1){getchar();}
    }

    dfs(0,1,1);

    stack<cord> panser;
    int sum=0;
    while(!anser.empty()){
        cord t=anser.top();
        anser.pop();
        panser.push(t);
        sum++;
    }
    printf("%d\n",sum);
    for(int i=0;i<sum;i++){
        cord t=panser.top();
        printf("%d %d %d %d\n",t.y1,t.x1,t.y2,t.x2);
        panser.pop();
    }
    
    return 0;
}