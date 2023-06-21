#include <iostream>
using namespace std;
//筛质数法 时间复杂度O(nloglogn) 近似O(n)
const int N = 1e6 + 10;
int primes[N];
int cnt;
bool st[N];//筛选质数

int sieve_prime(int x){
    for(int i=2; i<=x; i++){
        if(!st[i]){
            primes[cnt++] = x;
            for(int j = i+i;j<=x;j += i)st[j] = 1;//质数的倍数不是质数 2i，3i，...都需要标记为筛去
        }
    }
    return cnt;
}

int main() {
    int n;
    cin >>n;
    cout << sieve_prime(n) << endl;
    return 0;
}
