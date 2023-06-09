#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
//匈牙利算法 二分图的最大匹配 （NTR算法、舔狗算法）
const int N = 500 + 10 , M = 1e5 + 10;
int h[N],e[M],ne[M],idx;
int n1,n2,m;
bool st[N];//表示当前另一集合的元素是否被考虑过，每个元素只考虑一次  原集合换元素需要清空
int match[N];//当前另一集合的匹配

void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

//匈牙利算法
bool find(int x){
    //依次访问有边相连的另一集合的所有元素
    for(int i = h[x] ;i!=-1;i = ne[i]){
        int j = e[i];//取出这个元素
        if(!st[j]){//如果没被访问过
            st[j] = true;//就标记访问过
            if(!match[j] || find(match[j])){//如果当前这个元素没被匹配 或者可以善意地NTR（给原来的元素找到下家）
                match[j] = x;//那墙脚就可以被牛头人挖走 匹配成功
                return true;
            }
        }
    }
    return false;//如果执行都这一步 要么就是NTR失败 要么就是天煞孤星
}

int main() {
    memset(h,-1,sizeof h);
    cin >> n1 >> n2 >> m;
    int x,y;
    while(m--){
        scanf("%d%d",&x,&y);
        add(x,y);
    }

    int res  = 0;
    for(int i = 1;i <= n1;i++){
        memset(st,false,sizeof st);//注意每次都需要清空另一集合的访问标记st
        if(find(i))res++;
    }

    cout << res << endl;
    return 0;
}
