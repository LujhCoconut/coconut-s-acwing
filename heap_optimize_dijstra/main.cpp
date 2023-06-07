#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int,int> PII;
const int N = 1.5E5 + 10;

int h[N],e[N],ne[N],w[N],idx;//手熟
int n,m;
int s[N],dist[N];//标记是否被选中最短路 和需要动态维护的distance

//插入带权值邻接表
void add(int a,int b,int c){
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}
//堆优化的dijstra算法 采用<queue>的priority_queue
int heap_dijstra(){
    memset(dist,0x3f,sizeof dist);//定义初始状态无穷大
    dist[1] = 0;
    priority_queue<PII,vector<PII>,greater<PII>> heap;//小根堆
    heap.push({0,1});//第一个点是直到的

    while(heap.size()){//只要堆不空
        auto t= heap.top();//取出堆top 当前堆中最小值
        heap.pop();//弹出
        int ver = t.second,distance = t.first;//让 t 为当前top
        if(s[ver])continue;//如果 当前top已经被选中最短路，就跳过
        s[ver]=true;//说明当前top还没被选中过，标记为选中
        for(int i = h[ver]; i!=-1;i=ne[i]){//更新dist
            int j = e[i];
            if(dist[j] > distance + w[i]){
                dist[j] = distance + w[i];
                heap.push({dist[j],j});
            }
        }
    }
    if(dist[n] == 0x3f3f3f3f)return -1;
    else return dist[n];
}

int main() {
    cin >> n >> m;
    memset(h,-1,sizeof h);

    int a,b,c;
    while(m--){
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
    }
    cout << heap_dijstra() << endl;
    return 0;
}


/* 整个dijstra的核心逻辑就是
 * t <- 未被s选中的那个最小值
 * s[t] = 1 选它
 * 更新dist
 * 重复这样的操作
 * */