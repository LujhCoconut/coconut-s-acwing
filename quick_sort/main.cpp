#include <iostream>

using namespace std;
//quick_sort algorithm

const int N = 1E6+10;
int n = 0;
int q[N];

void quick_sort(int q[],int l,int r){
    //判断边界条件
    if(l>=r)return;//l>r 没有意义，l=r就一个元素无需排序
    //确定分界点 q[l],q[(l+r)/2],q[r],q[Random]都行
    int x = q[(l+r)/2];   //最好还是取（l+r）/2，因为两侧的值碰到强测试用例 会超时
    //设置两个移动指针指向两侧
    int i = l-1 , j = r+1;
    //调整区间 左边小于等于x 右边大于等于x
    while(i<j){
        do i++;while(q[i]<x);
        do j--;while(q[j]>x);
        if(i<j)swap(q[i],q[j]);
        /*
         * swap <--using namespace std给的
         * 自己写可以写
         * int temp = q[j];
         * q[j] = q[i];
         * q[i] = temp;
         * */
    }
    //递归地解决左右两边
    quick_sort(q,l,j);
    quick_sort(q,j+1,r);
}

int main() {
    scanf("%d",&n);//多少个数
    for(int i = 0 ;i<n;i++){
        scanf("%d",&q[i]);
    }//读入n个数
        quick_sort(q,0,n-1);//快速排序
    for(int i=0;i<n;i++){
        printf("%d ",q[i]);
    }
    return 0;
}
