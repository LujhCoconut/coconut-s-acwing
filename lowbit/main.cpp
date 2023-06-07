#include<iostream>
#include<math.h>
using namespace std;
//二进制中1的个数
const int N =  1e5 + 10;//数据规模

//二进制转换，求第k位数字
void test(int x){
    int t = 0;
    while(pow(2,t)<=x){
        t++;
    }
    for(int k = t-1;k>=0;k--){
        printf("%d ",x>>k&1);
    }
    printf("\n");
}

//lowbit操作，得到二进制的最后一个1的位置
int lowbit(int x){
    return x & (-x);
}

void printLowBit(int x){
    printf("%d\n", lowbit(x));
    printf("%d",x- lowbit(x));
}

int main(){
//    int n;
//    cin>>n;
//    while(n--){
//        int x;
//        cin>>x;
//        int res = 0;//结果
//        while(x)x -= lowbit(x),res++;//这行代码 意思是每次减去（二进制）x的最后一个1，把1减完了就是0，每减去一次1，意味着有1个1
//        cout<<res<<' ';
//    }
    test(256);
    printLowBit(12);
    return 0;
}