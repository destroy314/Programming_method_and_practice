#include <stdio.h>
long long sum=0;
void merge(int arr[],int start,int mid,int stop,int temp[]){//合并
    int i=start;
    int j=mid+1;
    int t=0;
    while(i<=mid&&j<=stop){
        if(arr[i]<=arr[j]){
            temp[t++]=arr[i++];//先赋值再给每个变量加1
        }
        else{
            sum+=mid+1-i;//arr[i]到arr[mid]分别与arr[j]构成逆序对
            temp[t++]=arr[j++];
        }
    }
    while(i<=mid){
        temp[t++]=arr[i++];
    }
    while(j<=stop){
        temp[t++]=arr[j++];
    }
    t=0;
    while(start<=stop){
        arr[start++]=temp[t++];
    }
}
void sort(int arr[],int start,int stop,int temp[]){//分离
    if(start<stop){
        int mid=(start+stop)/2;
        sort(arr,start,mid,temp);
        sort(arr,mid+1,stop,temp);
        merge(arr,start,mid,stop,temp);
    }
}
int main(){
    int n,j;
    scanf("%d",&n);
    int a[n],temp[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,0,n-1,temp);
    printf("%lld\n",sum);
    return 0;
}

//并归排序，合并时计算逆序数
//https://www.cnblogs.com/chengxiao/p/6194356.html