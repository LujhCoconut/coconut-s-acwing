#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

int k = 0;
string str;

void dfs(){
    if(str[k]=='#'){
        k++;
        return;
    }
    char root = str[k++];
    dfs();
    cout << root << ' ';
    dfs();
}

int main() {
    cin >> str;
    dfs();
    return 0;
}
