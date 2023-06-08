#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
//SPFA 算法求最短路
/* 实际上是对bellman_ford算法进行的优化 BF算法的逻辑是遍历更新每条边
/* 事实上只有前驱的点改变了dist 当前这个点才会改变 SPFA就优化在这里 但是SPFA长得和队列很像
/* */
const int N = 1E5 + 10;
const int err = -0x3f3f3f3f;
int n,m;
int h[N],w[N],e[N],ne[N],idx;
int dist[N];
bool st[N];//当前这个点是否存储在队列当中 重复的点是没有用的

void add(int a,int b,int c){
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx ++;
}

int spfa(){
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;

    queue<int> q;//SPFA的队列里存的是更新的点
    q.push(1);
    st[1] = true;

    while(q.size()){
        int t = q.front();
        q.pop();

        st[t] = false;//队头从队列中出来 就说明不在队列当中
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];//取出每个结点的值
            if (dist[j] > dist[t] + w[i]) {//如果能更新dist就更新dist
                dist[j] = dist[t] + w[i];
                if(!st[j]){//如果在队列里 就不用加了 没有意义的 如果不在，就需要加入更新队列
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    if(dist[n] == 0x3f3f3f3f)return err;
    else return dist[n];
}

int main() {
    cin >> n >> m;
    int x,y,z;
    memset(h,-1,sizeof h);
    while(m--){
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
    }

    int t = spfa();
    if(t == err)puts("impossible");
    else cout << t << endl;
    return 0;
}
