#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& v){
    int next{0};

    for(const auto x : v){
        if(x){
            v[next++] = x;
        }
    }

    for(int i = next; i < v.size(); i++){
        v[i] = 0;
    }
}

int main(){
    vector<int> v = {1, 0, 2, 2, 9, 0, 0, 1, 2};
    moveZeroes(v);
    for(const auto x : v){
        cout<<x<<", ";
    }
    cout<<endl;
    return 0;
}
