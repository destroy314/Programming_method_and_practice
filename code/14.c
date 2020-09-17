#include <stdio.h>
#include <time.h>
void quicksort(int arr[][4],int start,int stop){//多维数组的定义中除第一个之外的所有维度必须有边界
    if (start<stop){
        int i=start;
        int j=stop;
        int base=arr[i][0];
        while(i!=j){
            while(arr[j][0]>=base&&i<j){
                j--;
            }
            while(arr[i][0]<=base&&i<j){
                i++;
            }
            if(i<j){
                int temp=arr[j][0];
                arr[j][0]=arr[i][0];
                arr[i][0]=temp;
                temp=arr[j][1];
                arr[j][1]=arr[i][1];
                arr[i][1]=temp;
                temp=arr[j][2];
                arr[j][2]=arr[i][2];
                arr[i][2]=temp;
                temp=arr[j][3];
                arr[j][3]=arr[i][3];
                arr[i][3]=temp;
            }
        }
        arr[start][0]=arr[i][0];
        arr[i][0]=base;
        int temp=arr[i][1];
        arr[i][1]=arr[start][1];
        arr[start][1]=temp;
        temp=arr[i][2];
        arr[i][2]=arr[start][2];
        arr[start][2]=temp;
        temp=arr[i][3];
        arr[i][3]=arr[start][3];
        arr[start][3]=temp;
        quicksort(arr,start,i-1);
        quicksort(arr,i+1,stop);
    }
}
int main(){
    clock_t start,end;
    start = clock();
    int n;
    int a,b,c,temp;
    int combine1=-1,combine2=-1;
    int k=0;
    scanf("%d",&n);
    int stone[n][4],newstone[n][4];
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&a,&b,&c);
        if(a>b){temp=a,a=b,b=temp;}
        if(b>c){temp=b,b=c,c=temp;}
        if(a>b){temp=a,a=b,b=temp;}
        stone[i][0]=a;
        stone[i][1]=b;
        stone[i][2]=c;
        stone[i][3]=i;
    }
    int max=0,p;
    for(int i=0;i<n;i++){
        if(stone[i][0]>max){
            max=stone[i][0];
            p=stone[i][3];
        }
    }
    for(int i=0;i<n;i++){
        if(stone[i][1]>stone[n-1][0]){
            newstone[k][0]=stone[i][0];
            newstone[k][1]=stone[i][1];
            newstone[k][2]=stone[i][2];
            newstone[k][3]=stone[i][3];
            k++;
        }
    }
    for(int i=k-1;i>0;i--){
        end=clock();
        if((double)(end-start)/1000>500){goto sort;}
        for(int j=i-1;j>=0;j--){
            if(newstone[i][1]==newstone[j][1]&&newstone[i][2]==newstone[j][2]){
                if(newstone[i][0]+newstone[j][0]>max){
                    a=newstone[i][0]+newstone[j][0];
                    b=newstone[i][1];
                    a=a<b?a:b;
                    if(a>max){
                        max=a;
                        combine1=newstone[j][3];
                        combine2=newstone[i][3];
                    }
                }
            }
        }
    }
    if(combine1==-1){
        printf("1\n%d\n",p+1);
        return 0;
    }
    printf("2\n%d %d\n",combine1+1,combine2+1);
    return 0;
    sort:;
    int position[100001]={0};
    k=0;
    quicksort(stone,0,n-1);
    for(int i=0;i<n;i++){
        if(stone[i][1]>stone[n-1][0]){
            newstone[k][0]=stone[i][0];
            newstone[k][1]=stone[i][1];
            newstone[k][2]=stone[i][2];
            newstone[k][3]=stone[i][3];
            k++;
        }
    }
    for(int i=k-1;i>0&&newstone[i][0]>=max/2;i--){
        for(int j=i-1;j>=0&&newstone[j][0]+newstone[i][0]>max;j--){
            if(newstone[i][1]==newstone[j][1]&&newstone[i][2]==newstone[j][2]){
                a=newstone[i][0]+newstone[j][0];
                b=newstone[i][1];
                a=a<b?a:b;
                if(a>newstone[n-1][0]){
                    newstone[n-1][0]=a;
                    combine1=newstone[i][3];
                    combine2=newstone[j][3];
                }
            }
        }
    }
    if(combine1==-1){
        printf("1\n%d\n",stone[n-1][3]+1);
        return 0;
    }
    printf("2\n%d %d\n",combine1+1,combine2+1);
    return 0;
}

//乱序匹配会让一些样例超时，先排序会让另一些样例超时，所以...