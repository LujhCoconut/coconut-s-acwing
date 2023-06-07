#include <iostream>
#include <cstring>
using namespace std;
//拉链法处理哈希
const int N = 1e5 + 3;//哈希取模运算的这个模 最好是质数 并且离2的整数幂次尽可能远 冲突概率会降低
int h[N],e[N],ne[N],idx;//h[N] 哈希映射的值域 e[N]存的是值 ne存的是下一个位置 idx标志了每一个结点

void insert_hash(int x){
    int k = (x % N + N) % N;//负数也要映射成正数 并且防止过程数据溢出
    e[++idx] = x;//赋值 ,也可以写e[idx] 再后面再++
    ne[idx] = h[k];//idx的next是h[k] 也就是原来的头变成当前idx的next
    h[k] = idx;//h[k]的值是当前的idx 即头插法
}

bool find_hash(int x){
    int k = (x % N + N) % N;
    for(int i = h[k]; i!= -1;i = ne[i]){//从头开始遍历
        if(e[i] == x)return true;
    }
    return false;
}


int main() {
    int n;
    scanf("%d",&n);

    memset(h , -1 , sizeof h);//初始化 -1
    while(n--){
        char op[2];
        int x;
        scanf("%s%d",op,&x);

        if(*op == 'I')insert_hash(x);
        else{
            if(find_hash(x))puts("Yes");
            else puts("No");
        }
    }

    return 0;
}
