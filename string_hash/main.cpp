#include <iostream>
using namespace std;
//字符串哈希 p进制预处理前缀 通过比较哈希判断两个区间字符串是否相等
typedef unsigned long long ULL; // p进制预处理需要mod 2^64 通过ull就可以做到（保证>=0）
const int N = 1e5 + 10;
const int P = 131;//13331也可以 经验值
char str[N];
ULL h[N],p[N];//p存放p进制

/* 函数作用：字符串哈希求给定区间哈希核心代码
 * 原理逻辑：数组从左到右是高位到地位，最高位的权重与区间长度有关，区间越长，权值越大
 * 给定区间，要想求得区间哈希，需要将 [1,l-1]区间哈希乘上进制区间差（p^(r-l+1)）作为被减数
 * 即可求得哈希 其中p进制为131进制或者13331进制（能解决99.99%冲突），ull隐含mod（2^（64））
 * */
ULL get_str_hash(int l,int r){
    return h[r] - h[l-1]*p[r-l+1];
}

int main() {
    int n,m;
    scanf("%d%d%s",&n,&m,str+1);
    p[0] = 1;
    for(int i = 1;i<=N;i++){
        p[i] = p[i-1]*P;
        h[i] = h[i-1]*P + str[i];
    }

    while(m--){
        int l1,r1,l2,r2;
        scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
        if(get_str_hash(l1,r1) == get_str_hash(l2,r2))puts("Yes");//哈希相同，判断区间字符串相同
        else puts("No");
    }
    return 0;
}
