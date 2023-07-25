#include <iostream>
#include <vector>
using namespace std;

int findMajority(vector<int>& v){
    int el{0}, cnt{0};

    for(const auto x : v){
        if(!cnt){
            cnt = 1;
            el = x;
        }
        else if(el == x){
            cnt++;
        }
        else{
            cnt--;
        }
    }

    return el;
}

int main(){
    vector<int> v = {0, 0, 1, 6, 7, 7, 3, 7, 7, 9};
    cout<<findMajority(v)<<endl;
    return 0;
}
