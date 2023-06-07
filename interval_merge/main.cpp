#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//区间合并
typedef pair<int,int> PII;//定义pair用来解决此题目的区间左右端点值
int n;//初始区间规模
vector<PII> segs;//存放初始的所有区间，并在此区间进行区间合并

/*  此函数用于合并区间 */
void merge(vector<PII> &segs){
    vector<PII> res;
    sort(segs.begin(),segs.end());//区间合并首先需要对各区间左端点进行排序

    int st = -1e9 - 1;//初始边界定义为负无穷大 （值域-1e9 ~ 1e9）
    int ed = -1e9 - 1;//初始边界定义为负无穷大 （值域-1e9 ~ 1e9）

    for(auto seg:segs){//枚举各个区间
        if(ed < seg.first){//如果当前区间的右端点小于枚举区间的左端点，意味着没有交集
            if(st != -1e9-1)res.push_back({st,ed});//这种情况下，只要当前区间不是初始化的负无穷大，这个区间就已经能加入res
            st = seg.first,ed = seg.second;//接着考虑下一个区间
        }
        else ed = max(ed,seg.second);//else意味着有交集，然而这个区间的左端点一定不小于比较区间的左端点，所以只需考虑右端点，谁大取谁
    }
    if (st != -1e9-1)res.push_back({st,ed});//如果只有一个区间，需要单独加入res，#20，21对单区间只更新了st ed
    segs = res;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        int l , r;
        cin >> l >> r;
        segs.push_back({l,r});
    }
    merge(segs);
//    printf("[");
//    for(int i=0;i<segs.size();i++)cout << '[' << segs[i].first <<',' << segs[i].second << ']'<<',';
//    printf("]");
    cout << segs.size() << endl;
    return 0;
}
