#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 1e5+10;

int n ,m;
int h[N],se;//堆（从1开始），和规模se = size
int ph[N],hp[N];//映射关系 ph：第k个插入的下标 hp：从堆映射回下标

void heap_swap(int a,int b){//交换在heap中位置分别为a，b的两个元素
    swap(ph[hp[a]],ph[hp[b]]);//根据a和b的位置找到它们分别是第几个插入的元素，然后将其（在h数组中的）下标转换
    swap(hp[a],hp[b]);//将两个位置存的是第几号元素转换
    swap(h[a],h[b]);//最后再转换值(这三个语句位置可以换，但是从上到下逐渐变短的话比较美观)
}

void down(int u){
    int t = u;
    if(u*2 <= se && h[u*2] < h[t])t = 2 * u;//左（右）子节点都存在（判定只需下标小于size）
    if(u*2+1 <= se && h[2*u+1] < h[t])t = u * 2 + 1;//比较出这个结点和他两个儿子的的最小值所在下标，t记录下标
    if(u != t){//如果u!=t 即u（父节点）不是最小值，那么它和t（子节点的最小值下标）交换
        heap_swap(u,t);
        down(t);//递归这样的操作
    }
}

void up(int u){
    while(u/2 && h[u/2] > h[u]){
        heap_swap(u/2,u);
        u /= 2;
    }
}

int main() {
    int n,m = 0;//m当前是第几个要插入的数
    scanf("%d",&n);
    while(n--){
        char op[10];
        int k,x;
        scanf("%s",op);
        if(!strcmp(op,"I")){
            scanf("%d",&x);
            m ++;se++;
            ph[m] = se;hp[se] = m;//m代表是第几个插入的元素(point)->se指向的是插入的位置(heap)
            h[se] = x;
            up(se);
        }else if(!strcmp(op,"PM")){
            printf("%d\n",h[1]);
        }else if(!strcmp(op,"DM")){
            heap_swap(1,se);//将底部一个元素放上来
            se--;//所有元素数量减一
            down(1);//将放上来的元素沉下去
        }else if(!strcmp(op,"D")){
            scanf("%d",&k);//k存储拿到第几个输入的数字
            k = ph[k];//k从储存第几个输入的数字变换为储存那个数字存放在h的哪个位置,找到它在堆中的位置
            heap_swap(k,se);
            se--;
            down(k),up(k);//其可能大，可能小，都操作一遍准没错
        } else{
            scanf("%d%d",&k,&x);
            k = ph[k];//k从储存第几个输入的数字变换为储存那个数字存放在h的哪个位置,找到它在堆中的位置
            h[k] = x;//改它的值
            down(k),up(k);//其可能大，可能小，都操作一遍准没错
        }

    }
    return 0;
}


