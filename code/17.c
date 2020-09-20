#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int n;
    char command[10],name[20];
    typedef struct node{
        char student[20];
        struct node *next;
    }Node;
    Node *root;
    root=(Node*)malloc(sizeof(Node));
    root->next=NULL;
    Node *head=root,*tail=root;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",&command[0]);
        if(strcmp(command,"Arrive")==0){
            Node *new;
            new=(Node*)malloc(sizeof(Node));
            scanf("%s",&new->student[0]);
            new->next=NULL;
            tail->next=new;
            tail=new;
            if(head==root){
                head=new;
            }
        }
        else if(strcmp(command,"Leave")==0){
            if(head!=root&&tail!=root){
                int p=0;
                if(head==tail){p=1;}
                root->next=head->next;
                Node *t=head;
                head=head->next;
                free(t);
                if(p==1){
                    head=root;
                    tail=root;
                }
            }
        }
        else if(strcmp(command,"QueueHead")==0){
            if(head==root&&tail==root){
                printf("Empty queue\n");
                continue;
            }
            printf("%s\n",head->student);
        }
        else if(strcmp(command,"QueueTail")==0){
            if(head==root&&tail==root){
                printf("Empty queue\n");
                continue;
            }
            printf("%s\n",tail->student);
        }
    }
    return 0;
}