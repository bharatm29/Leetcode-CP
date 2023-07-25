#include <iostream>
using namespace std;

double power( double n,  int p){
    if(p == 0){
        return 1;
    }

    if(p < 0){
        p = abs(p);
        n = 1.00000 / n;
    }

    double res = 1.00000;

    while(p > 0){
        if(p & 1){
            res *= n;
        }
        n *= n;
        p /= 2;
    }

    return res;
}

int main(){
    double n{0.0};
    int p{0};
    cin>>n>>p;
    cout<<power(n, p)<<endl;
    return 0;
}
