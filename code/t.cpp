#include <iostream>
#include <ctime>

using namespace std;

int main() {
    freopen("input.txt","w",stdout);
    int T=rand()%100;
    char elem[17]={'.','.','.','.','.','.','.','.','.','.','*','*','.','#','#','#','*'};
    bool iS = false,iE = false;
    srand(time(NULL));
    for(cout << T <<endl;T>0;T--){
        int n = rand()%10+1, m = rand()%10+1, k = rand()%4;
        printf("%d %d %d\n",n,m,k);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(i==0&&j==0){
                    cout << 'S';
                    continue;
                }
                if(i==n-1&&j==m-1){
                    cout << 'E';
                    break;
                }
                cout << elem[rand()%17];
            }
            cout << endl;
        }
    }
    return 0;
}
