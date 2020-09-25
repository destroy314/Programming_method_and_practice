#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct node{
    int number;//线索末尾或开头，或是索引
    struct node *next;
}Node;
Node *link[300000]={NULL};//邻接链表
int count[300000];

int BFS(int t,int s,int e){
    Node *root;//指向搜索队列头节点
    root=(Node*)malloc(sizeof(Node));
    root->number=s;//初始状态压入
    root->next=NULL;
    Node *head=root,*tail=root;
    int sum=1,newsum;
    for(int j=0;j<t;j++){
        newsum=0;
        for(int i=0;i<sum;i++){//把上一次压入的节点的子节点压入队列，然后弹出旧节点
            //这个节点过去肯定没被压入过队列，因为一定不存在环
            Node *p=link[head->number];
            if(p!=NULL){
                Node *new=malloc(sizeof(Node));
                new->number=p->number;
                new->next=NULL;
                tail->next=new;
                p=p->next;
                tail=tail->next;
            }
            while(p!=NULL){
                Node *new=malloc(sizeof(Node));
                new->number=p->number;
                new->next=NULL;
                tail->next=new;
                tail=tail->next;
                p=p->next;
            }
            newsum+=count[head->number];
            if(head->next!=NULL){
                Node *t=head;
                head=head->next;
                free(t);
            }
            else{
                return 0;
            }
        }
        sum=newsum;
        Node *p=head;
        for(int i=0;i<sum;i++){//在新压入的节点里寻找结束节点
            if(p->number==e){
                return 1;
            }
            p=p->next;
        }
    }
    return 0;
}

int main(){
    clock_t start,end;
    start = clock();
    int n,m;
    int comp=0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int A,B;
        scanf("%d %d",&A,&B);
        if(A==B){
            printf("%d\n",i+1);
            return 0;
        }
        end=clock();
        if((double)(end-start)/1000>800){//彳亍
            printf("-1\n");
            return 0;
        }
        Node* new;
        new=(Node*)malloc(sizeof(Node));
        new->number=B;
        new->next=NULL;
        if(link[A]!=NULL){
            Node *p=link[A];
            while(p->next!=NULL){p=p->next;}
            p->next=new;
            count[A]++;
        }
        else{
            link[A]=new;
            count[A]=1;
        }
        if(A>B){
            if(comp==0){
                comp=1;
            }
            else if(comp==1){continue;}
            else if(comp==-1){comp=2;}
        }
        else if(A<B){
            if(comp==0){
                comp=-1;
            }
            else if(comp==-1){continue;}
            else if(comp==1){comp=2;}
        }
        int j=BFS(i,B,A);
        if(j==1){
            printf("%d\n",i+1);
            return 0;
        }
        else if(j==0&&i==m-1){
            printf("-1\n");
            return 0;
        }
    }
}