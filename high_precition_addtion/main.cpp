#include <iostream>
#include <vector>
using namespace std;
const int N = 1e6 + 10;

//高精度加法代码
//C = A + B
vector<int> add(vector<int>&A,vector<int>&B){
    vector<int>C;

    int t = 0;//控制进位变量
    for(int i =0;i<A.size() || i<B.size();i++){
        if(i<A.size())t+=A[i];
        if(i<B.size())t+=B[i];
        C.push_back(t%10);//当前数位的值
        t /= 10;//进位值
    }
    if(t)C.push_back(1);
    return C;
}

//比较A >= B 前是否大于后
bool cmp(vector<int> &A,vector<int> &B){
    if(A.size() != B.size()) return A.size()>B.size();
    for(int i = A.size()-1;i>=0;i--){
        if(A[i] != B[i])return A[i]>B[i];
    }
    return true;
}

//高精度减法，保证正数
vector<int> sub(vector<int> &A,vector<int> &B){
    vector<int> C;
    for(int i = 0 ,t = 0;i < A.size();i++){
        t = A[i] - t;
        if(i<B.size())t -= B[i];//B没有这一位就是0
        C.push_back((t+10)%10);
        if(t<0)t = 1;
        else t = 0;
    }
    while(C.size()>1 && C.back()==0)C.pop_back();
    return C;
}

int main() {
    string a,b;
    vector<int>A,B;

    cin>>a>>b;
    for(int i = a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
    for(int i = b.size()-1;i>=0;i--)B.push_back(b[i]-'0');
//高精度加法
//    auto C = add(A,B);
//    for(int i = C.size()-1;i>=0;i--)printf("%d",C[i]);


//高精度减法
    if(cmp(A,B)){
        auto C = sub(A,B);
        for(int i = C.size()-1;i>=0;i--)printf("%d",C[i]);
    }else{
        auto C = sub(B,A);
        printf("-");
        for(int i = C.size()-1;i>=0;i--)printf("%d",C[i]);
    }
    return 0;
}
