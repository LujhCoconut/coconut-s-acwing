#include <iostream>
using namespace std;
typedef long long LL;
const int N = 1e6 + 10;
int q[N],temp[N];

LL merge_sort(int *q,int l,int r){
    // l = r 时 意味着当前递归的位置只有一个数字 就不需要排序（当然也就不存在逆序数对了）
    if(l>=r) return 0;
    // mid 时归并排序的边界点 对半分
    int mid = l + r >> 1;
    // res 是最后需要的那个答案; res 包括了 左边区间 + 右边区间 + 跨区间的三部分
    // 其中左右区间 可通过递归访问得到
    LL res = merge_sort(q,l,mid)+ merge_sort(q,mid+1,r);

    /*归并的过程，递归和整个程序的核心部分*/
    /* 主要解决的是 跨区间的res 部分；因为递归到最底层是左区间1个数，右区间1个数，只存在跨区间的数
     * 算出这个跨区间的数，就得到仅仅包含这两个数的区间的res ，返回到上一次递归调用
     * 同时 归并的过程 也顺便完成了对各自区间的排序*/
    int k = 0,i = l,j = mid+1;//i,j 左右区间的起始指针
    while(i <= mid && j<=r){
        if(q[i] <= q[j])temp[k++] = q[i++];//在q[i]>q[j]之前 显然不会出现跨区间的逆序对
        else{
            temp[k++] = q[j++];//这一步和上一步本质上是归并排序的一部分 ，将两个区间的i,j指针比较，把较小值按顺序插入辅助数组
            res += mid- i + 1;//而当q[i] > q[j] 代表着从 i 到 mid 这个区间里的所有数都和q[j]是逆序数对,而个数显然为mid-i+1
        }
    }

    //上述的temp数组 是基于比较产生的 而两个区间的其中一个并不一定完全走完了，所以只需要看看有没有走完，没走完就继续走完就可以了
    while (i <= mid)temp[k++]=q[i++];
    while (j <= r)temp[k++]=q[j++];

    //扫尾 把辅助数组 -> 真的那个数组，i，j已经脏了，所以循环时需要重新赋值；在这里，i指的是q的起始地址，j指的是temp的起始地址
    for(i = l,j = 0;i<=r;i++,j++)q[i]=temp[j];

    return res;
}

int main() {
    int n = 0;
    scanf("%d",&n);
    for(int i = 0 ;i<n;i++){
        scanf("%d",&q[i]);
    }

    cout<< merge_sort(q,0,n-1) <<endl;
    return 0;
}


//    int count = 0 ;
/*暴力解法 Time Limited Exceeded*/
//    for(int i = 0 ;i<n;i++){
//        for(int j = i+1;j<n;j++){
//            if(q[j] < q[i])count++;
//        }
//    }
//    printf("%d",count);
