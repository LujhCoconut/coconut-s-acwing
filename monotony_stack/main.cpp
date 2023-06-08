#include <iostream>
using namespace std;
//单调栈 O(N) 输出每个数左边第一个比它小的数
const int N = 1E5 + 10;//数据规模
int n;
int stk[N],tt;//栈 和 栈顶下标（1开始表示有值）

int main() {
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        while(tt && stk[tt] >= x){//栈不空 并且 栈顶元素大于X  这意味着再往后这个栈顶元素不可能是答案，直接弹出
            tt --;
        }//直到栈顶元素小于x
        if(tt)printf("%d ",stk[tt]);//栈不空 意味着栈顶元素就是答案
        else printf("-1 ");//空 就是找不到
        stk[++tt] = x;//同时我们还应该把这个元素入栈
    }
    return 0;
}
