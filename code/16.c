#include <stdio.h>
long long maxx[500000],maxy[500000],minx[500000],miny[500000];//两个大顶堆和两个小顶堆
void shiftup_max(long long arr[],int t){//大顶堆加入
    if(t==0){return;}
    if(arr[t]>arr[(t-1)/2]){
        int temp=arr[t];
        arr[t]=arr[(t-1)/2];
        arr[(t-1)/2]=temp;
        shiftup_max(arr,(t-1)/2);
    }
}
void shiftup_min(long long arr[],int t){
    if(t==0){return;}
    if(arr[t]<arr[(t-1)/2]){
        int temp=arr[t];
        arr[t]=arr[(t-1)/2];
        arr[(t-1)/2]=temp;
        shiftup_min(arr,(t-1)/2);
    }
}
void shiftdown_max(long long arr[],int t,int end){//大顶堆堆化
    int p;
    if(2*t+1>end){return;}
    if(2*t+2<=end){
        if(arr[t]>=arr[2*t+1]&&arr[t]>=arr[2*t+2]){return;}
        if(arr[t]<arr[2*t+1]&&arr[t]<arr[2*t+2]){
            if(arr[2*t+1]>arr[2*t+2]){
                int temp=arr[t];
                arr[t]=arr[2*t+1];
                arr[2*t+1]=temp;
                p=2*t+1;
                goto next;
            }
            if(arr[2*t+1]<=arr[2*t+2]){
                int temp=arr[t];
                arr[t]=arr[2*t+2];
                arr[2*t+2]=temp;
                p=2*t+2;
                goto next;
            }
        }
        if(arr[t]<arr[2*t+1]){
            int temp=arr[t];
            arr[t]=arr[2*t+1];
            arr[2*t+1]=temp;
            p=2*t+1;
            goto next;
        }
        if(arr[t]<arr[2*t+2]){
            int temp=arr[t];
            arr[t]=arr[2*t+2];
            arr[2*t+2]=temp;
            p=2*t+2;
            goto next;
        }
        return;
    }
    if(2*t+1<=end){
        if(arr[t]>=arr[2*t+1]){return;}
        int temp=arr[t];
        arr[t]=arr[2*t+1];
        arr[2*t+1]=temp;
        p=2*t+1;
    }
    next:;
    shiftdown_max(arr,p,end);
}
void shiftdown_min(long long arr[],int t,int end){
    int p;
    if(2*t+1>end){return;}
    if(2*t+2<=end){
        if(arr[t]<=arr[2*t+1]&&arr[t]<=arr[2*t+2]){return;}
        if(arr[t]>arr[2*t+1]&&arr[t]>arr[2*t+2]){
            if(arr[2*t+1]<arr[2*t+2]){
                int temp=arr[t];
                arr[t]=arr[2*t+1];
                arr[2*t+1]=temp;
                p=2*t+1;
                goto next;
            }
            if(arr[2*t+1]>=arr[2*t+2]){
                int temp=arr[t];
                arr[t]=arr[2*t+2];
                arr[2*t+2]=temp;
                p=2*t+2;
                goto next;
            }
        }
        if(arr[t]>arr[2*t+1]){
            int temp=arr[t];
            arr[t]=arr[2*t+1];
            arr[2*t+1]=temp;
            p=2*t+1;
            goto next;
        }
        if(arr[t]>arr[2*t+2]){
            int temp=arr[t];
            arr[t]=arr[2*t+2];
            arr[2*t+2]=temp;
            p=2*t+2;
            goto next;
        }
        return;
    }
    if(2*t+1<=end){
        if(arr[t]<=arr[2*t+1]){return;}
        int temp=arr[t];
        arr[t]=arr[2*t+1];
        arr[2*t+1]=temp;
        p=2*t+1;
    }
    next:;
    shiftdown_min(arr,p,end);
}
int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int endof_maxx=0,endof_maxy=0,endof_minx=0,endof_miny=0;//堆的长度
        long long distx=0,disty=0;//两个方向上的曼哈顿距离
        long long x,y,midx,midy;//两个方向上读入的数和中位数
        printf("Case: %d\n",i+1);
        int n;
        scanf("%d",&n);
        scanf("%lld %lld",&x,&y);
        midx=x;
        midy=y;
        printf("%lld.0000\n",distx+disty);
        for(int j=0;j<n-1;j++){
            scanf("%lld %lld",&x,&y);
            int smaxx=0,sminx=0,smaxy=0,sminy=0;
            long long tmidx=midx,tmidy=midy;
            if(x<midx){
                distx+=midx-x;
                maxx[endof_maxx]=x;
                shiftup_max(maxx,endof_maxx);
                endof_maxx++;
            }
            else if(x>=midx){
                distx+=x-midx;
                minx[endof_minx]=x;
                shiftup_min(minx,endof_minx);
                endof_minx++;
            }
            if(endof_maxx-endof_minx>=2){
                smaxx=1;//midx变为maxx中最大值
                minx[endof_minx]=midx;
                shiftup_min(minx,endof_minx);
                endof_minx++;
                midx=maxx[0];
                maxx[0]=maxx[endof_maxx-1];
                endof_maxx--;
                shiftdown_max(maxx,0,endof_maxx-1);
            }
            else if(endof_minx-endof_maxx>=2){
                sminx=1;
                maxx[endof_maxx]=midx;
                shiftup_max(maxx,endof_maxx);
                endof_maxx++;
                midx=minx[0];
                minx[0]=minx[endof_minx-1];
                endof_minx--;
                shiftdown_min(minx,0,endof_minx-1);
            }
            if(smaxx==1){
                distx-=(tmidx-midx)*(endof_maxx+1);
                distx+=(tmidx-midx)*endof_minx;
            }
            else if(sminx==1){
                distx+=(midx-tmidx)*endof_maxx;
                distx-=(midx-tmidx)*(endof_minx+1);
            }
            if(y<midy){
                disty+=midy-y;
                maxy[endof_maxy]=y;
                shiftup_max(maxy,endof_maxy);
                endof_maxy++;
            }
            else if(y>=midy){
                disty+=y-midy;
                miny[endof_miny]=y;
                shiftup_min(miny,endof_miny);
                endof_miny++;
            }
            if(endof_maxy-endof_miny>=2){
                smaxy=1;
                miny[endof_miny]=midy;
                shiftup_min(miny,endof_miny);
                endof_miny++;
                midy=maxy[0];
                maxy[0]=maxy[endof_maxy-1];
                endof_maxy--;
                shiftdown_max(maxy,0,endof_maxy-1);
            }
            else if(endof_miny-endof_maxy>=2){
                sminy=1;
                maxy[endof_maxy]=midy;
                shiftup_max(maxy,endof_maxy);
                endof_maxy++;
                midy=miny[0];
                miny[0]=miny[endof_miny-1];
                endof_miny--;
                shiftdown_min(miny,0,endof_miny-1);
            }
            if(smaxy==1){
                disty-=(tmidy-midy)*(endof_maxy+1);
                disty+=(tmidy-midy)*endof_miny;
            }
            else if(sminy==1){
                disty+=(midy-tmidy)*endof_maxy;
                disty-=(midy-tmidy)*(endof_miny+1);
            }
            printf("%lld.0000\n",distx+disty);
        }
    }
    return 0;
}

//堆是一个很有趣的数据类型，在这道题里用堆来储存大于和小于中位数的数。可以很方便(?)的操作堆中最大或最小的数。