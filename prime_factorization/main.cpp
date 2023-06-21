#include <iostream>
using namespace std;

void divide(int x){
    for(int i = 2;i <= x/i ;i++){//质因数只可能存在一个大于sqrt(n)的 单独考虑就行
        if(x % i == 0){
            int s = 0;
            while(x % i == 0){//只要这个数能够继续除以质因数 就除以质因数
                x = x/i;
                s++;
            }
            printf("%d %d\n",i,s);
        }
    }
    if(x > 1)printf("%d 1\n",x);
    puts("");
}

int main() {
    int n;
    cin >> n;
    int x ;
    for(int i = 1;i <=n;i++){
        scanf("%d",&x);
        divide(x);
    }
    return 0;
}
