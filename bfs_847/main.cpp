#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
//图的层次遍历
const int N = 1E5 + 10;
int h[N],e[N],ne[N],idx;
int n,m;
int sign[N];//表示是否被访问过以及层次
int q[N];//手写队列

void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

int bfs(int u){
    int hh = 0 ,tt = 0;
    q[0] = 1;
    memset(sign,-1,sizeof sign);
    sign[1] = 0;

    while(hh <= tt){
        int t = q[hh ++];
        for(int i = h[t];i!=-1;i=ne[i]){
            int j = e[i];
            if(sign[j] == -1){
                sign[j] = sign[t] + 1;
                q[++tt] = j;
            }
        }
    }
    return sign[n];
}

int main() {
    cin >> n >> m;
    int a,b;
    memset(h,-1,sizeof h);

    for(int i = 0;i < m;i++){
        scanf("%d%d",&a,&b);
        add(a,b);
    }

    cout<<bfs(1)<<endl;
    return 0;
}
