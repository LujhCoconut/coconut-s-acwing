#include <iostream>
using namespace std;
//整数二分
//数的范围 一个有序数列 求某个数的起始地址和结束地址
const int N = 1e5 + 10;
int q[N];

int main() {
    //n多少个数据 m表示寻问的个数，也就是输入的次数
    int n = 0,m = 0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&q[i]);
    }

    while(m--){
        int x;
        scanf("%d",&x);

        //先二分起始地址
        //无脑两侧先写
        int l = 0 , r = n -1;
        while(l<r){
            //先无脑写mid = l+r >> 1 ,后面再考虑改不改成 l+r+1 >> 1
            int mid = l + r >> 1;
            if(q[mid] >= x) r = mid;
            else l = mid + 1;
        }
        if(q[l] != x)cout << "-1 -1" << endl;
        else{
            cout << l << ' ';
            int l = 0 , r = n -1;
            while(l<r){
                //先无脑写mid = l+r >> 1 ,后面再考虑改不改成 l+r+1 >> 1
                int mid = l + r + 1 >> 1;
                if(q[mid] <= x) l = mid;
                else r = mid - 1;
            }
            cout << l << endl;
        }
    }

    return 0;
}
