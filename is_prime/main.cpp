#include <iostream>
using namespace std;

bool is_prime(int n){
    if(n < 2) return false;
    for(int i = 2 ;i <= n/i;i++){//这一步 i*i<=n 可能会溢出 i<=sqrt(n)执行效率较低 注意是从2开始
        if(n % i == 0)return false;
    }
    return true;
}


int main() {
    int n;
    cin >> n;
    int x;
    for(int i = 1; i <= n;i++){
        scanf("%d",&x);
        if(is_prime(x))puts("Yes");
        else puts("No");
    }
    return 0;
}
