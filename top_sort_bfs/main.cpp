#include <iostream>
#include <cstring>
using namespace std;
//拓扑序 BFS实现

const int N = 1E5 +10;
int h[N],e[N],ne[N],idx;//图的存储 唯手熟尔
int q[N],d[N];//手写队列 入度队列

int n,m;//n个点 m条边

void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

bool topsprt(){
    int hh = 0 , tt = -1;

    for(int i = 1;i <= n;i++){
        if(d[i] == 0)q[++tt] = i;
    }

    while(hh <= tt){
        int t = q[hh++];
        for(int i = h[t];i != -1;i = ne[i]){
            int j = e[i];// !!!!!注意 这里是下一个结点 我们需要的是结点的值
            d[j] --;
            if(d[j] == 0)q[++tt] = j;
        }
    }

    return tt == n-1;
}

int main() {
    cin >> n >> m;
    int a,b;
    memset(h,-1,sizeof h);
    while(m--){
        scanf("%d%d",&a,&b);
        add(a,b);
        d[b] ++;
    }

    if(topsprt()){
        for(int i = 0;i <n;i++){
         printf("%d ",q[i]);
        }
        puts("");
    }else puts("-1");

    return 0;
}
