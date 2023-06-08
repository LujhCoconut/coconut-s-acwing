#include <iostream>
#include<vector>

using namespace std;

//高精度乘法
vector<int> mutiply(vector<int>&A,int b){
    vector<int> C;
    if(b == 0){
        C.push_back(0);
        return C;
    }
    int t = 0;
    for(int i=0;i<A.size();i++){
        C.push_back((A[i]*b+t)%10);
        t = (A[i]*b+t)/10;
    }
    if(t>0)C.push_back(t);
    return C;
}


//高精度除法
vector<int> division(vector<int> &A,int b){
    vector<int> C;
    if(A.size()==1 && A[0]==0){
        C.push_back(0);
        return C;
    }
    int r = A[A.size()-1];
    int flag = 0;
    for(int i = A.size()-1;i>=0;i--){
        int temp = r / b;
        if(!C.empty() || temp !=0)C.push_back(temp);
        flag = 1;
        if(i != 0)r = r%b*10+A[i-1];
        else r = r%b;
    }
    if(C.empty())C.push_back(0);
    C.push_back(r);
    return C;
}


int main() {
    string a;
    int b;
    cin>>a>>b;

    vector<int> A;
    for(int i = a.size()-1;i>=0;i--)A.push_back(a[i]-'0');

    auto C = division(A,b);
    if(C.size() == 1)printf("%d",C[0]);
    else for(int i = 0;i<C.size()-1;i++)printf("%d",C[i]);

    printf("\n");
    printf("%d",C[C.size()-1]);

    return 0;
}
