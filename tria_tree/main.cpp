#include <iostream>
using namespace std;
//tria树 字典树 用于高效存储和查找字符串集合
const int N = 2e5 + 10;
//全部变量不赋初值默认初值为0，局部变量必须赋初值
//下表为0的点 既是空结点也是头结点
int son[N][26];//本题字典为26个小写英文字母，所以第二维只需26个大小空间，N为数据规模（存在空间浪费，可以在MAIN里定义），int是映射来的
int cnt[N],idx;//idx当前用到了哪个下标

char str[N];
/*插入操作*/
void insert_tria(char str[]){
    int p = 0;
    for(int i = 0; str[i]; i++){//字符串以\0结尾 这就可以作为判断条件
        int u  = str[i]- 'a';//将26个字母映射成数字
        if(!son[p][u])son[p][u] = ++idx;//保证每一个结点都有一个唯一的编号
        p = son[p][u];//逻辑上的找子结点，每个子结点都存储了唯一的编号 值等于给他值的那个idx
    }
    cnt[p] ++;//每个字符串读完，p的值就是那个结点，代表这个字符串结束，意味着以这个子节点为最后一个字符的单词++；
}

/*询问查找操作 返回存储多少次这个字符串*/
int query_tria(char str[]){
    int p = 0;
    for(int i = 0;str[i];i++){
        int u = str[i]  - 'a';
        if(!son[p][u])return 0 ;//挨个查，没有就是没有这个字符串
        p = son[p][u];//挨个查 的 移动过程
    }
    return cnt[p]; //按照上述逻辑，这个字符串存在，且在这个p指的结点终止，只需要看看这个结点作为字符串结尾的最后一个字符的字符串的个数
}

int main() {
    int n;
    cin >> n;
    while(n--){
        char op[2];
        scanf("%s%s",&op,&str);
        if(op[0]=='I')insert_tria(str);
        else printf("%d\n", query_tria(str));
    }
    return 0;
}
