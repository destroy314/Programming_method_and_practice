#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int>tree[200001];//无根树的邻接链表
long long int sonsize[200001]={0},deepth[200001]={0};
int father[200001],visited[200001]={0};
long long int dist=0,oodline;//距离和，长度为奇数的边的数量
long long int odd=0,even=0;//深度为奇数或偶数节点的数量
int nodenumber=0;
void DFS(int n){
    deepth[n]=deepth[father[n]]+1;
    if(deepth[n]%2!=0){
        even++;
    }
    else{
        odd++;
    }
    sonsize[n]=1;
    visited[n]=1;
    while(!tree[n].empty()){
        int next=tree[n].back();
        tree[n].pop_back();
        if(visited[next]==0){
            father[next]=n;
            DFS(next);
            sonsize[n]+=sonsize[next];
        }
    }
    dist+=sonsize[n]*(nodenumber-sonsize[n]);//当前节点和父节点之间的边两边的每个点对都通过这条边，为总距离贡献1
    return;
}
int main(){
    deepth[0]=-1;
    scanf("%d",&nodenumber);
    for(int i=0;i<nodenumber-1;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        tree[a].push_back(b);//因为是无根树，所以所有的相邻节点都要存
        tree[b].push_back(a);
    }
    DFS(1);//把节点1当作根节点
    oodline=odd*even;
    printf("%lld\n",(dist+oodline)/2);
    return 0;
}

//思路http://lexue.bit.edu.cn/mod/forum/discuss.php?d=127476
//实现http://lexue.bit.edu.cn/mod/forum/discuss.php?d=127070
//原理http://lexue.bit.edu.cn/mod/forum/discuss.php?d=126416