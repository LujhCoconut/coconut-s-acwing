#include <iostream>
#include <cstring>
using namespace std;
//BFS 迷宫问题

typedef pair<int,int> PII;
const int N = 110;
int n,m;//棋盘大小
int p[N][N];//棋盘
int d[N][N];//记录是否被访问过
PII que[N*N];//手写队列

int bfs(){
    //初始化队列
    int hh = 0, tt = 0;
    que[0] = {0,0};
    //起点标志为访问过
    memset(d,-1,sizeof d);
    d[0][0] = 0;
    //方向移动向量
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    //队列不空
    while(hh <= tt){
        auto t = que[hh++];//获得队头的点
        //朝四个方向尝试拓展
        for(int i = 0; i < 4;i++){
            int x = t.first + dx[i];
            int y = t.second + dy[i];
            //不越过棋盘 且符合访问条件 并且没有被访问过 就把这个结点加入队列，更新这个结点的d为访问层序（上一层点+1）
            if(x >= 0 && x < n && y >= 0 && y < m && p[x][y]==0 && d[x][y] == -1){
                d[x][y] = d[t.first][t.second]+1;
                que[++tt]={x,y};
            }
        }

    }
    //返回目标点
    return d[n-1][m-1];
}

int main() {
    cin >> n >> m;
    for(int i = 0;i<n;i++)
        for(int j = 0;j < m;j++)
            scanf("%d",&p[i][j]);

    cout << bfs() << endl;
    return 0;
}
