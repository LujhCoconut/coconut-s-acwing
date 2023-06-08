#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2E5 + 10;
int n,m;
int p[N];//并查集

struct Edge{
    int a;
    int b;
    int w;
    //结构体内嵌比较函数
    bool operator< (const Edge &W)const{
        return w < W.w;
    }
}edges[N];

int find(int x){
    if(p[x] != x)p[x] = find(p[x]);
    return p[x];
}

int main() {
    cin >> n >> m;
    int x,y,z;

    for(int i = 0;i<m;i++){
        scanf("%d%d%d",&x,&y,&z);
        edges[i] = {x,y,z};
    }

    for(int i = 0;i<n;i++)p[i] = i;//并查集千万记得初始化 开始时每个集合都只有自己
    //kruskal 算法 首先需要对边按权值从小到大排序
    sort(edges,edges + m);
    int res = 0, cnt = 0;
    //从小到大枚举所有的边 如果边的两端不连通 就把它连通 也即是这条边被选作是最小生成树的一部分
    for(int i = 0; i < m;i ++){
        int a = edges[i].a ,b = edges[i].b , w = edges[i].w;
        a = find(a),b = find(b);
        if(a != b){
            p[a] = b;//只是两个集合合并 （实际上根本就没有存储图）
            res += w;//每次连通 就把当前这条边的权值 加到总和里
            cnt ++;//每次选中一条边 cnt++
        }
    }
    //n个点的最小生成树 只有n-1条边 当cnt < n-1 说明不连通
    if(cnt < n-1)puts("impossible");
    else cout << res <<endl;

    return 0;
}
