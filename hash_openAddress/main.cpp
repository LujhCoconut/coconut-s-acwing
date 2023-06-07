#include <iostream>
#include <cstring>
using namespace std;
//开放寻址法 哈希
const int N = 2E5 + 3;//质数
const int nul = 0x3f3f3f3f;
int h[N];

int find_open_address(int x){
    int k = (x % N + N) % N;
    while(h[k] != nul && h[k] != x){
        k++;
        if(k == N)k = 0;
    }
    return k;
}

int main() {
    int n;
    scanf("%d",&n);

    memset(h, nul, sizeof h);
    while(n --){
        char op[2];
        int x;
        scanf("%s%d",op,&x);

        if(*op == 'I')h[find_open_address(x)] = x;
        else{
            if(h[find_open_address(x)] != nul)puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
