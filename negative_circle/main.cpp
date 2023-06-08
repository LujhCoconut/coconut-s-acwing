#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
//SPFA判断负环
const int N = 1E5 + 10;
int h[N],e[N],w[N],ne[N],idx;
int dist[N],cnt[N];//相比于SPFA 多了一个cnt记录路劲中到i结点的边的数量
//根据抽屉原理 当边的数量 > 结点数量 的时候 存在负环
bool st[N];
int n,m;

void add(int a,int b,int c){
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx ++;
}

bool spfa_nega(){
    memset(dist,0x3f,sizeof dist);
    //不需要对dist[1]初始化 因为是判断图里有无负环 而不是1-n的最短路
    queue<int> q;//因为任何一个节点都有可能开始，所以开始的时候把所有结点加入队列
    for(int i = 1 ;i <=n;i++){
        st[i] = true;
        q.push(i);
    }

    while(q.size()){
        int t = q.front();
        q.pop();

        st[t] = false;
        for(int i = h[t];i !=-1;i = ne[i]){
            int j = e[i];
            if(dist[j] > dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;//新增的更新逻辑 很简单 每次更新 相当于数量从上一个节点的数量加1
                if(!st[j]){//还是SPFA的操作
                    st[j] = true;
                    q.push(j);
                }
                if(cnt[j] > n)return true;//这是负环的判断条件
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    memset(h,-1,sizeof h);
    int x,y,z;
    while(m--){
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
    }

    if(spfa_nega())puts("Yes");
    else puts("No");
    return 0;
}
