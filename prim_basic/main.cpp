#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 500 + 10;
const int INF = 0x3f3f3f3f;
const int ERR = -0x3f3f3f3f;

int g[N][N];
int n,m;
int dist[N];
bool st[N];

int prim(){
    memset(dist,0x3f,sizeof dist);

    int res = 0;
    for(int i = 0;i < n;i++){
        int t = -1;
        // 找不在最小生成树中的最小边
        for(int j = 1;j <= n;j++){//如果 j 没有被选进 最小生成树
            // 并且 要么是本次迭代中 t 还没更新过 要么是它不是最小的边 我们就要更新让t最小
            if(!st[j] && (t == -1  || dist[t] > dist[j])){
                t = j;
            }
        }
        // 如果更新的这条最小的点dist还是INF 且不是第一个选的点 说明不连通
        if(i && dist[t] == INF)return INF;
        if(i) res += dist[t];//只要不是第一个选的点 我们就更新res += dist 注意先累加在更新
        for(int j = 1;j <=n ;j++){//更新所有的dist 看看是否有连向当前最小生成树更小的边
            dist[j] = min(dist[j],g[t][j]);
        }
        st[t] = true;
    }

    return res;
}

int main() {
    memset(g,0x3f,sizeof g);
    cin >> n >> m;

    int a,b,w;
    //无向图 邻接矩阵 需要更新两条边
    while(m--){
        scanf("%d%d%d",&a,&b,&w);
        g[a][b] = g[b][a] = min(g[a][b],w);
    }

    int t = prim();
    if(t == INF)puts("impossible");
    else cout << t << endl;

    return 0;
}
