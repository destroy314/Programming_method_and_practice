#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int number;//成语末尾或开头的文字，或是索引
    struct node *next;
}Node;
Node *idiom[300000];//邻接链表
int count[300000];//储存每个节点子节点的数量
int pushed[300000];//储存节点是否已被压入查找队列，防止循环
int all[300000][4];//储存每个成语以查找开始和结束成语的索引
Node *endindex[1000001]={NULL};//索引链表，方便快速查找具有某个特定末尾或开头成语在idiom中的索引
Node *startindex[1000001]={NULL};
int main(){
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d %d %d %d",&all[i][0],&all[i][1],&all[i][2],&all[i][3]);
        Node *j=endindex[all[i][0]];
        if(j!=NULL){
            //printf("%d",j->number);
            for(;all[i][0]==idiom[j->number]->number;j=j->next){//遍历之前存入的成语，寻找能让新成语接在末尾的
                Node *p=idiom[j->number];
                while(p->next!=NULL){
                    p=p->next;
                }
                Node *new;
                new=(Node*)malloc(sizeof(Node));
                new->next=NULL;
                p->next=new;
                new->number=i;//存入索引
                count[j->number]++;
                if(j->next==NULL){break;}
            }
        }
        Node *root;
        root=(Node*)malloc(sizeof(Node));
        idiom[i]=root;//存入新成语
        root->number=all[i][3];//末尾
        Node *new;
        new=(Node*)malloc(sizeof(Node));
        root->next=new;
        new->number=all[i][0];//开头
        new->next=NULL;
        count[i]=0;
        pushed[i]=0;
        j=startindex[all[i][3]];
        if(j!=NULL){
            //printf("%d",j->number);
            for(;all[i][3]==idiom[j->number]->next->number;j=j->next){//遍历之前存入的成语，寻找能接在新成语末尾的
                Node *p=idiom[i];
                while(p->next!=NULL){
                    p=p->next;
                }
                Node *new;
                new=(Node*)malloc(sizeof(Node));
                new->next=NULL;
                p->next=new;
                new->number=j->number;//存入索引
                count[i]++;
                if(j->next==NULL){break;}
            }
        }
        new=(Node*)malloc(sizeof(Node));//将首末位排入索引链表
        new->number=i;
        new->next=NULL;
        Node *p=endindex[all[i][3]];
        if(p!=NULL){
            while(p->next!=NULL){p=p->next;}
            p->next=new;
        }
        else{
            endindex[all[i][3]]=new;
        }

        new=(Node*)malloc(sizeof(Node));
        new->number=i;
        new->next=NULL;
        p=startindex[all[i][0]];
        if(p!=NULL){
            while(p->next!=NULL){p=p->next;}
            p->next=new;
        }
        else{
            startindex[all[i][0]]=new;
        }
    }//邻接链表建立完成，接下来进行BFS
    int start_index,end_index;
    int A,B,C,D,a,b,c,d;//分别是开始和结束成语
    scanf("%d %d %d %d",&A,&B,&C,&D);
    scanf("%d %d %d %d",&a,&b,&c,&d);
    for(int i=0;i<m;i++){
        if(all[i][0]==A&&all[i][1]==B&&all[i][2]==C&&all[i][3]==D){
            start_index=i;
        }
        if(all[i][0]==a&&all[i][1]==b&&all[i][2]==c&&all[i][3]==d){
            end_index=i;
        }
    }
    if(start_index==end_index){
        printf("1\n");
        return 0;
    }
    Node *root;//指向搜索队列头节点
    root=(Node*)malloc(sizeof(Node));
    root->number=start_index;//初始状态压入
    root->next=NULL;
    Node *head=root,*tail=root;
    int level=1,sum=1,newsum;//搜索层数，上次压入的节点数，这次压入的节点数
    for(int j=0;j<m;j++){
        newsum=0;
        for(int i=0;i<sum;i++){//把上一次压入的节点的子节点压入队列，然后弹出旧节点
            if(pushed[head->number]!=1){//如果这个节点过去没被压入过队列，压入子节点
                tail->next=idiom[head->number]->next->next;//子节点链表连接到队列末尾
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
            if(p->number==end_index){
                printf("%d\n",level+1);
                return 0;
            }
            p=p->next;
        }
        level++;
    }
    printf("-1\n");
    return 0;
}

/*
思路是把每个成语当作一个节点，首位相连关系是有向边。感觉不如把成语当作边
idiom:
                (root)           (new)         (new)       (new)
idiom[0]->endnumber,next->startnumber,next->index,next->index,next->NULL
idiom[1]->endnumber,next->startnumber,next->NULL
...
idiom[m-1]

BFS队列:
root->free index,next->index,next->index,next->NULL
                =                       =
            head                    tail

endindex:
endindex[0]->index,next->index,next->NULL
endindex[1]->NULL
...
*/

//4-7.tle是因为遍历之前储存的成语耗时太长
//6.re是因为m过大爆栈了
//5-7re出现在读取
//5,7re出现在寻找连接，6不在