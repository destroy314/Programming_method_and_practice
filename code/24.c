#include <stdio.h>
int rot[5][5];
void spin(char cha[16][17],int j,int k){
    if(rot[j][k]<3){
        rot[j][k]++;
    }
    else{
        rot[j][k]=0;
    }
    char temp[4][4];
    int sj=(j-1)*4;
    int sk=(k-1)*4;
    for(int m=0;m<4;m++){
        for(int n=0;n<4;n++){
            temp[3-n][m]=cha[sj+m][sk+n];
        }
    }
    for(int m=0;m<4;m++){
        for(int n=0;n<4;n++){
            cha[sj+m][sk+n]=temp[m][n];
        }
    }
}
int checkl(char cha[16][17],int line,int len){
    int list[128]={0};
    for(int j=0;j<len*4;j++){
        int s=cha[line-1][j];
        list[s]++;
        if(list[s]>1){
            return 0;
        }
    }
    return 1;
}
int checkr(char cha[16][17],int row,int len){
    int list[128]={0};
    for(int j=0;j<len*4;j++){
        int s=cha[j][row-1];
        list[s]++;
        if(list[s]>1){
            return 0;
        }
    }
    return 1;
}
int DFS(char su[16][17],int rotj,int rotk){
    int nextj=rotj;
    int nextk=rotk+1;
    int isend=0;
    if(nextk>4){
        nextk-=4;
        nextj++;
    }
    if(nextj>4){
        isend=1;
    }

    if(checkl(su,rotj*4,rotk)==1&&checkr(su,rotk*4,rotj)==1){
        if(isend==0){
            int r=DFS(su,nextj,nextk);
            if(r==1){return 1;}
        }
        else{return 1;}
    }
    
    spin(su,rotj,rotk);
    if(checkl(su,rotj*4,rotk)==1&&checkr(su,rotk*4,rotj)==1){
        if(isend==0){
            int r=DFS(su,nextj,nextk);
            if(r==1){return 1;}
        }
        else{return 1;}
    }

    spin(su,rotj,rotk);
    if(checkl(su,rotj*4,rotk)==1&&checkr(su,rotk*4,rotj)==1){
        if(isend==0){
            int r=DFS(su,nextj,nextk);
            if(r==1){return 1;}
        }
        else{return 1;}
    }

    spin(su,rotj,rotk);
    if(checkl(su,rotj*4,rotk)==1&&checkr(su,rotk*4,rotj)==1){
        if(isend==0){
            int r=DFS(su,nextj,nextk);
            if(r==1){return 1;}
        }
        else{return 1;}
    }

    spin(su,rotj,rotk);
    return 0;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        char sudoku[16][17];
        for(int j=0;j<16;j++){
            scanf("%s",&sudoku[j]);
        }
        int t=DFS(sudoku,1,1);
        int step1=0,step2=0;
        int rot2[5][5];
        for(int j=1;j<5;j++){
            for(int k=1;k<5;k++){
                step1+=rot[j][k];
                switch (rot[j][k]){//可能陷入局部最优解。每个方块都旋转两次后也是合法数独，但总步数可能更少
                case 0:
                    step2+=2;
                    rot2[j][k]=2;
                    break;
                case 1:
                    step2+=3;
                    rot2[j][k]=3;
                    break;
                case 2:
                    rot2[j][k]=0;
                    break;
                case 3:
                    step2+=1;
                    rot2[j][k]=1;
                    break;
                }
            }
        }
        if(step1<step2){
            printf("%d\n",step1);
            for(int j=1;j<5;j++){
                for(int k=1;k<5;k++){
                    if(rot[j][k]>0){
                        for(int l=0;l<rot[j][k];l++){
                            printf("%d %d\n",j,k);
                        }
                        rot[j][k]=0;
                    }
                }
            }
        }
        else{
            printf("%d\n",step2);
            for(int j=1;j<5;j++){
                for(int k=1;k<5;k++){
                    rot[j][k]=0;
                    if(rot2[j][k]>0){
                        for(int l=0;l<rot2[j][k];l++){
                            printf("%d %d\n",j,k);
                        }
                    }
                }
            }
        }
    }
    return 0;
}

//http://lexue.bit.edu.cn/mod/forum/discuss.php?d=126631