#include <iostream>
using namespace std;
//八皇后问题 n-皇后 DFS 回溯剪枝

const int N = 21;
int n;//棋盘大小
char p[N][N];//大棋盘
bool col[N],dig[N],udig[N];//同一列不可取，同一正负对角线不可取，初始默认false
//y = x + b 或者 y = -x + b 因为同方向比例系数是一致的 所以是否属于每条对角线可以通过截距判断，注意y-x可能为负数，取补数n+y-x就可以了

void dfs(int u){
    //每个位置都枚举了，所以打印当前状态就可以
    if(u == n){
        for(int i = 0;i<n;i++)puts(p[i]);
        puts("");
    }

    for(int i = 0;i<n;i++){
        if(!col[i] && !dig[n-u+i] && !udig[u+i]){//i列 未被选中 ,(u,i)所在正负对角线未标记，才能够被枚举，此所谓剪枝
            p[u][i] = 'Q';
            col[i] = true;
            dig[n-u+i] = true;
            udig[u+i] = true;
            //dfs 递归前需要改变约束
            dfs(u+1);
            //dfs 递归后需要恢复现场
            p[u][i] = '.';
            col[i] = false;
            dig[n-u+i] = false;
            udig[u+i] = false;
        }
    }
}

int main() {
    scanf("%d",&n);
    //棋盘初始化
    for(int i = 0;i < n; i++)
        for(int j = 0;j < n;j ++)
            p[i][j]='.';

    dfs(0);
    return 0;
}
