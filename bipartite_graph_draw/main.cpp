#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
//二分图（二部图） 染色（判定）
const int N = 1E5 + 10 , M =2E5 + 10;
int h[N],e[M],ne[M],idx;//注意边的数据范围 无向边相当于连了两条有向边
int color[N];//染色数组 初始为0表示未染色 1表示颜色1 2表示颜色2 x若是当前颜色 给邻接点染色只需3-x
int n,m;//数据量
//经典数组模拟邻接表
void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

//DFS 关注的是顺序 和 判断逻辑
bool dfs(int u,int c){
    color[u] = c;//首先需要染色
    //给邻接点染色 需要置入矛盾逻辑
    for(int i = h[u];i != -1;i = ne[i]){
        int j = e[i];
        if(!color[j]){//未染色情况下 若在往深层调用中出现矛盾 则判断矛盾
            if(!dfs(j,3-c))return false;
        }//染色情况下 本质的矛盾逻辑就是 邻接点的颜色等于自己的颜色 这是DFS的最底层的返回逻辑
        else if(color[j] == c)return false;
    }
    //全都DFS一遍 没有矛盾 就证明是二部图
    return true;
}

int main() {
    memset(h,-1,sizeof h);
    cin >> n >> m;
    int x,y;
    while(m--){
        scanf("%d%d",&x,&y);
        add(x,y),add(y,x);//记得这是无向边
    }

    bool flag = true;//开始标记是二分图
    for(int i = 1; i <= n;i++){//染色开始
        if(!color[i]){//如果没染色 那就染色
            //染色是一个递归的DFS解决 当然BFS也可以做
            if(!dfs(i,1))flag = false;//如果dfs返回false 说明dfs过程中出现矛盾
        }
    }

    if(!flag)puts("No");//最后还是有矛盾
    else puts("Yes");
    return 0;
}
