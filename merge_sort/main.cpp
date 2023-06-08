#include <iostream>
//merge_sort algorithm
const int N = 1e6+10;
int n=0;
int q[N],tmp[N];//归并排序需要辅助数组

void merge_sort(int q[],int l,int r){
    if(l>=r)return;//边界判定
    int mid = (l+r)/2; //归并按照数组中间的值来排
    //递归地解决左右两边
    merge_sort(q,l,mid);
    merge_sort(q,mid+1,r);
    // k is a number to get sum of(temp)
    int k = 0, i = l, j =mid +1;
    while(i<=mid && j<=r){
        if(q[i]<=q[j])tmp[k++]=q[i++];
        else tmp[k++]=q[j++];
    }
    while (i <= mid)tmp[k++]=q[i++];
    while (j <= r)tmp[k++]=q[j++];

    for(i = l,j = 0;i<=r;i++,j++)q[i]=tmp[j];
}

int main() {
    scanf("%d",&n);//n个数
    for(int i =0;i<n;i++){
        scanf("%d",&q[i]);
    }
    merge_sort(q,0,n-1);
    for(int i =0;i<n;i++){
        printf("%d ",q[i]);
    }
    return 0;
}
