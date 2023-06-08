#include <iostream>
using namespace std;
//最长连续不重复序列长度 O(n)时间复杂度，O(n)空间复杂度
const int N = 1e5 + 10;
int n;//数据规模
int a[N];//存放原整数序列
int s[N];//动态数组用于控制是否有重复  如果区间内有重复，重复数的个数一定会大于1，这是触发指针移动的逻辑条件

int main() {
    cin>>n;//输入数据规模
    for(int i = 0;i < n;i++)cin>>a[i];//输入整数序列
    int max = 0;//初始化最长长度
    for(int i = 0,j = 0;i < n;i++){//右指针从头扫描整个数组
        s[a[i]]++;//右指针移动一位，动态数组的a[i]位置的数量就会加1；
        while(s[a[i]] > 1){//当a[i]位置的数量大于1，意味着出现重复，移动左指针，直到没有重复
            //每移动一次左指针，就要减少a[j]的数量（实际上就是依次找到a[j]=a[i]的那个j）
            s[a[j]]--;
            j++;
        }
        max = max > (i - j + 1) ? max:(i-j+1);//每次执行完，看看是否能进行更新max
    }
    cout<<max<<endl;
    return 0;
}
