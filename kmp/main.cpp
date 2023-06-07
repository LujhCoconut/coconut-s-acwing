#include <iostream>
using namespace std;

const int N = 1e5 + 10, M  = 1e6 + 10;

int n,m;
char p[N],s[M];//s大
int ne[N];//next数组

int main() {
    //输入串信息
    //输入子串，下标从1开始
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        cin >> p[i];
    }
    //输入大串，下标从1开始
    scanf("%d",&m);
    for(int i = 1;i<=m;i++){
       cin >> s[i];
    }

    //next数组
    for(int i = 2,j = 0; i <= n;i++){
        while(j && p[i]!=p[j+1])j = ne[j];
        if(p[i] == p[j+1])j++;
        ne[i] = j;
    }

    //kmp匹配
    for(int i = 1,j = 0;i <= m;i++){
        while(j && s[i] != p[j+1] )j = ne[j];
        if(s[i] == p[j+1])j++;
        if(j == n){//匹配成功
            printf("%d ",i - n);//看题设条件
            j = ne[j];
        }
    }
    return 0;
}
