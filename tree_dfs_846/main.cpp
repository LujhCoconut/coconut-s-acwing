#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1E5 + 10 , M = N * 2;
int n;
int h[N],e[M],ne[M],idx;//h存储每个结点的邻接单链表，e存储的边，ne存储的是next，idx每个结点的唯一编号
int ans = N;//最后的答案 连通最大值的最小值
bool st[N];//标记是否被搜过了

void add(int a,int b){
    e[idx] = b;//结点存储的是边的末尾，头隐含在h【a】
    ne[idx] = h[a];//头插
    h[a] = idx ++;//让头等于idx的这个结点
}

//以u为根子树中点的数量,也就是这颗子树的大小
int dfs(int u){
    st[u] = true;

    int sum = 1 ,res = 0;// sum 当前子树的点数 res:去掉这个点连通块的点数的最大值
    for(int i = h[u];i!=-1;i = ne[i]){
        int j = e[i];//e存的是边 ，按找ne[i]找到的e[i]，是u为起点，i为终点的边 所以j是点
        if(!st[j]){//j没访问过 我们才操作
            int s = dfs(j);//用S表示j这个子树的大小
            res = max(res,s);//更新 res 为子树大小最大的那一个 即连通块中点最多的那一个
            sum += s;//当前树的大小等于1+子树的大小
        }
    }

    res = max((n - sum),res);//去掉一个点之后 上下两个连通块 可能上面大可能下面大 ，更新res
    ans = min(ans,res);//每次得到的res 去和现在的最大值中的最小值ans比较 得出答案
    return sum;//返回树的大小
}


int main() {
    cin >> n;
    memset(h,-1,sizeof h);
    int a,b;
    for(int i = 0;i < n-1;i++){
        scanf("%d%d",&a,&b);
        add(a,b);
        add(b,a);
    }

    dfs(1);
    cout << ans << endl;
    return 0;
}
