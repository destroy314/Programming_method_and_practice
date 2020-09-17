#include <stdio.h>
void quicksort(int arr[],int a[],int start,int stop){//快速排序结束时间，开始时间一起移动
    if (start<stop){
        int i=start;
        int j=stop;
        int base=arr[i];
        while(i!=j){
            while(arr[j]>=base&&i<j){
                j--;
            }
            while(arr[i]<=base&&i<j){
                i++;
            }
            if(i<j){
                int temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
                temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
        }
        arr[start]=arr[i];
        arr[i]=base;
        int temp=a[i];
        a[i]=a[start];
        a[start]=temp;
        quicksort(arr,a,start,i-1);
        quicksort(arr,a,i+1,stop);
    }
}
int main(){
    int n;
    int time=0;
    int num;
    scanf("%d",&n);
    int tasks[n],taske[n];
    for(int i=0;i<n;i++){
        scanf("%d %d",&tasks[i],&taske[i]);
    }
    quicksort(taske,tasks,0,n-1);
    num=1;//第一个任务一定能做
    time=taske[0];
    for(int i=1;i<n;i++){
        if(tasks[i]>=time){//因为结束时间已经排好，找到能做的任务直接做
            time=taske[i];
            num++;
        }
    }
    printf("%d\n",num);
    return 0;
}