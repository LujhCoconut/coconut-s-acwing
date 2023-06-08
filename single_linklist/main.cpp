#include <iostream>
using namespace std;
//数组模拟单链表 静态链表
const int N = 1e5 + 10;//数据规模

/* head : 头结点的下标
 * e[i] ： 表示结点i的值
 * ne[i] ： 表示结点i的next
 * idx  : index 即存储当前用到了哪一个点了
 * 数组下表从0开始
 * */
int head, e[N], ne[N], idx;

//初始化
void init(){
    head =  -1;//头结点下标志 -1 意味着空
    idx = 0; //当前可用存储索引下标为 0
}

//将值X插入头结点(逻辑上的第一个位置)
void insert_to_head(int x){
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx ++;
}

//将值x插入到第k个结点（数组下标为k-1）的后面
void insert_to_logicPosition(int k,int x){
    e[idx] = x;
    ne[idx] = ne[k-1];
    ne[k-1] = idx;
    idx ++;
}

//将值x插入到k下标的后面
void insert_to_phyPosition(int k,int x){
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx ++;
}

//将第k个插入的结点删除（下标k-1）
void del_from_k(int k){
    if(!k)head = ne[head];//<=> k=0 时，删除头结点
    else ne[k-1] = ne[ne[k-1]];
}

int main() {
    int m;//进行m次操作
    cin >> m;

    init();

    while(m--){
        char op;
        cin >> op;
        int k,x;
        if(op == 'H'){
            cin >> x;
            insert_to_head(x);
        }else if(op == 'D'){
            cin >> k;
            del_from_k(k);
        }else{
            cin >> k >> x;
            insert_to_phyPosition(k-1,x);
        }
    }

    for(int i = head;i != -1;i = ne[i]){
        cout<<e[i]<<' ';
    }

    cout<<endl;
    return 0;
}
