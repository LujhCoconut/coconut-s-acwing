#include <iostream>
using namespace std;
//八皇后问题 更原始的DFS求解

const int N = 21;
int n;
char p[N][N];
bool row[N],col[N],dig[N],udig[N];

void dfs(int x,int y,int s){//（x,y）坐标 s是当前皇后的数量
    if(y == n)y = 0 , x ++;
    if(x == n){
        if(s == n){
            for(int i = 0;i<n;i++)puts(p[i]);
            puts("");
        }
        return;
    }
    /*这里是真的一个一个枚举过去，所以是很慢的*/
    //不放
    dfs(x,y+1,s);
    //放
    if(!row[x] && !col[y] && !dig[x+y] && !udig[y-x+n]){
        p[x][y] = 'Q';
        row[x] = col[y] = dig[x+y] = udig[y-x+n] = true;
        dfs(x,y+1,s+1);
        p[x][y] = '.';
        row[x] = col[y] = dig[x+y] = udig[y-x+n] = false;
    }
}

int main() {
    cin >> n;
    //初始化棋盘
    for(int i = 0;i< n;i++)
        for(int j = 0;j< n;j++)
            p[i][j] = '.';

    dfs(0,0,0);
    return 0;
}
