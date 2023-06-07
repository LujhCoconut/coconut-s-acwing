#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 510;
int G[N][N];//稠密图 邻接矩阵
int dist[N];//distance 初始定义0x3f3f3f3f 即正无穷
bool s[N];//是不是已经被选作最短路

int n,m;

int dijstra(){
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    for(int i = 1;i<=n;i++){//n次 每次选中一个加入s
        int t = -1;
        for(int j = 1;j<=n;j++){//开始遍历 如果未被最短路选中 并且 当前dist值更小的点
            if(!s[j] && (t == -1 || dist[t] > dist[j]))
                t = j;//也就是 最后的t 是最短路选中的点
        }
        s[t] = true;//t被选中

        for(int j = 1; j <= n;j++){//选中一个t 就要更新整个dist
            dist[j] = min(dist[j],dist[t]+G[t][j]);
        }
    }
    if(dist[n]==0x3f3f3f3f)return -1;
    else return dist[n];
}

int main() {
    memset(G,0x3f,sizeof G);
    cin >> n >> m;
    int a,b,c;
    while(m--){
        scanf("%d%d%d",&a,&b,&c);
        G[a][b] = min(G[a][b],c);//对于重边 在最短路问题中只需要存权值最小的那个
    }
    cout << dijstra() << endl;
    return 0;
}
