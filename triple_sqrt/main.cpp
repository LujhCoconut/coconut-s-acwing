#include <iostream>
using namespace std;

int main() {
    double x;
    cin >> x;

    double l,r;
    if(x >= 1){
        l = 0;
        r = x;
    }else if(x <= -1){
        l = x;
        r = 0;
    }else if( x>0 && x<1){
        l = x;
        r = 1;
    }else{
        l = -1;
        r = x;
    }

    while(r - l > 1e-9){
        double mid = (l+r)/2.0;
        if(x >= 0) {
            if (mid * mid * mid >= x)r = mid;
            else l = mid;
        } else{
            if(mid*mid*mid <= x)l = mid;
            else r = mid;
        }
    }
    printf("%lf",r);
    return 0;
}
