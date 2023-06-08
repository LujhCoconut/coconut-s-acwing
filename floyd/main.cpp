#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 210;
const int INF = 0X3f3f3f3f;
int d[N][N];
int n,m,Q;

void floyd(){
    for(int k = 1 ;k <= n;k ++){
        for(int i = 0;i < n; i ++){
            for(int j = 0;j < n;j ++){
                d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for(int i = 0;i<n;i++){
        for(int j = 0;i < n;j++){
            if(i == j)d[i][j] = 0;
            else d[i][j] = INF;
        }
    }

    floyd();
    int x,y;
    while(Q--){
        scanf("%d%d",&x,&y);
        if(d[x][y] >= INF / 2)puts("impossible");
        else printf("%d",d[x][y]);
    }
    return 0;
}
