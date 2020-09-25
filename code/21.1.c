#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int number;//成语末尾或开头的文字，或是索引
    struct node *next;
}Node;
Node *link[1000000]={NULL};//邻接链表
int pushed[1000000],count[1000000];

int main(){
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int a,b,c,d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        Node* new;
        new=(Node*)malloc(sizeof(Node));
        new->number=d;
        new->next=NULL;
        if(link[a]!=NULL){
            Node *p=link[a];
            while(p->next!=NULL){p=p->next;}
            p->next=new;
            count[a]++;
        }
        else{
            link[a]=new;
            pushed[a]=0;
            count[a]=1;
        }
    }
    int A,B,C,D,a,b,c,d;//分别是开始和结束成语
    scanf("%d %d %d %d",&A,&B,&C,&D);//D->a
    scanf("%d %d %d %d",&a,&b,&c,&d);
    if(A==a&&B==b&&C==c&&D==d){
        printf("1\n");
        return 0;
    }
    Node *root;//指向搜索队列头节点
    root=(Node*)malloc(sizeof(Node));
    root->number=D;//初始状态压入
    root->next=NULL;
    Node *head=root,*tail=root;
    int level=2,sum=1,newsum;
    for(int j=0;j<m;j++){
        newsum=0;
        for(int i=0;i<sum;i++){//把上一次压入的节点的子节点压入队列，然后弹出旧节点
            if(pushed[head->number]!=1){//如果这个节点过去没被压入过队列，压入子节点
                tail->next=link[head->number];//子节点链表连接到队列末尾
                pushed[head->number]=1;
                while(tail->next!=NULL){tail=tail->next;}
                newsum+=count[head->number];
            }
            if(head->next!=NULL){
                Node *t=head;
                head=head->next;
                free(t);
            }
            else{
                printf("-1\n");
                return 0;
            }
        }
        sum=newsum;
        Node *p=head;
        for(int i=0;i<sum;i++){//在新压入的节点里寻找结束节点
            if(p->number==a){
                printf("%d\n",level+1);
                return 0;
            }
            p=p->next;
        }
        level++;
    }
    printf("-1");
    return 0;
}

//确实不如把成语当作边
/*
link:
link[1]->index,next->index,next->NULL
link[2]->NULL
...
link[index]->index,next->NULL
...
link[1000000]->NULL
*/