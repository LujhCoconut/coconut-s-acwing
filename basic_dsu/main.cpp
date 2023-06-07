#include <iostream>
using namespace std;
//并查集

const int N = 1E5 + 10;//数据规模
int n,m;//n个数 m个操作
int p[N];//父亲数组，初始时每个数 都各自是 一个集合 判断是否是树根的方法就是p[x] == x
int se[N];//并查集的集合元素数量（原题加强）

/*并查集核心操作 find函数（使用路径压缩优化）*/
int find(int x){
    //只要它爹不是根节点，就看看它爹的爹是不是
    if(p[x] != x)p[x] = find(p[x]);//只要不是树根，递归地网上找树根，并给路径上的每个结点都修改它的父亲结点为根节点（路径压缩）
    return p[x];
}


int main() {
    //本题输入数据规模n 所有的数即1，2，3......n
    scanf("%d%d",&n,&m);
    for(int i = 1 ;i <= n; i++){
        p[i] = i;
        se[i] = 1;//初始时每个集合数量都是1
    }

    while(m--){
        char op[5];
        int a = 0,b = 0;
        scanf("%s",op);

        if(op[0]=='C'){
            scanf("%d%d",&a,&b);
            if(find(a) != find(b))se[find(b)] += se[find(a)];//合并 注意一下是不是同一个集合，谁是最后的根节点
            p[find(a)]= find(b);//集合合并操作：将a,b所在集合合并，以b为根

        }
        else if(op[1]=='1'){
            scanf("%d%d",&a,&b);
            if(find(a) == find(b))puts("Yes");
            else puts("No");
        }else{
            scanf("%d",&a);
            printf("%d\n",se[find(a)]);
        }

    }
    return 0;
}
