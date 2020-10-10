#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<vector<int>>tree;
vector<vector<int>>anser;
int value[200010]={0};
int tag[200010]={0};
int temp[200010];
int isroot[200010]={0};
int sontemp[200010]={0};
int tagged;
int root;
int num=1;
int n;
void output(int i){
    if(num==1){
        printf("[%d",i);
    }
    else if(num==n){
        printf(",%d]\n",i);
    }
    else{
        printf(",%d",i);
    }
    num++;
    return;
}
void ansersort(int k,int start,int stop){
    if (start<stop){
        int i=start;
        int j=stop;
        int base=anser[k][i];
        while(i!=j){
            while((anser[k][j]>=base)&&(i<j)){
                j--;
            }
            while((anser[k][i]<=base)&&(i<j)){
                i++;
            }
            if(i<j){
                int t=anser[k][j];
                anser[k][j]=anser[k][i];
                anser[k][i]=t;
            }
        }
        anser[k][start]=anser[k][i];
        anser[k][i]=base;
        ansersort(k,start,i-1);
        ansersort(k,i+1,stop);
    }
}
void treesort(int k,int start,int stop){
    if (start<stop){
        int i=start;
        int j=stop;
        int base=tree[k][i];
        while(i!=j){
            while((tree[k][j]>=base)&&(i<j)){
                j--;
            }
            while((tree[k][i]<=base)&&(i<j)){
                i++;
            }
            if(i<j){
                int t=tree[k][j];
                tree[k][j]=tree[k][i];
                tree[k][i]=t;
            }
        }
        tree[k][start]=tree[k][i];
        tree[k][i]=base;
        treesort(k,start,i-1);
        treesort(k,i+1,stop);
    }
}
void ADD(int i){
    anser[tagged].push_back(value[i-1]);
    while(!tree[i].empty()){
        int j=tree[i][0];
        ADD(j);
        tree[i].erase(tree[i].begin());
    }
}
void GENE(int i){
    int j=0;
    if(tag[i-1]){
        tagged=i;
        ADD(i);
        ansersort(i,0,anser[i].size()-1);
        for(j=0;j<anser[i].size();j++){
            output(anser[i][j]);
        }
        anser[i].clear();
        return;
    }
    output(value[i-1]);
    j=0;
    while(!tree[i].empty()){
        j=tree[i][0];
        if(tag[i-1]){tag[j-1]=0;}
        GENE(j);
        tree[i].erase(tree[i].begin());
    }
    return;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n+1;i++){
        vector<int>a;
        tree.push_back(a);
        anser.push_back(a);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&value[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&tag[i]);
    }
    if(n==1){
        printf("[%d]\n",value[n-1]);
        return 0;
    }
    for(int i=0;i<n-1;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        tree[x].push_back(y);
        if(!isroot[x]){isroot[x]++;}
        if(!isroot[y]){isroot[y]++;}
        isroot[y]++;
    }
    for(int i=1;i<n+1;i++){
        if(tree[i].size()>1){
            treesort(i,0,tree[i].size()-1);
        }
    }
    for(int i=1;i<n+1;i++){
        if(isroot[i]==1){
            root=i;
            break;
        }
    }
    GENE(root);
    return 0;
}

/*
vector<vector<int>>tree
tree[0]
tree[1]
tree[2] 3 4 5
tree[3] 1 6
...
*/