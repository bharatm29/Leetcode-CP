#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void nextPermutation(vector<int>& v){
    const int n = v.size();   
    int index{-1};

    for(int i = n - 2; i >= 0; i--){
        if(v[i] < v[i + 1]){
            index = i;
            break;
        }
    }

    if(index == -1){
        reverse(v.begin(), v.end());
        return;
    }

    for(int i = n - 1; i >= 0; i--){
        if(v[index] < v[i]){
            swap(v[index], v[i]);
            reverse(v.begin() + index + 1, v.end());
            return;
        }
    }
}

int main(){
    vector<int> v = { 3, 1, 2};
    nextPermutation(v);
    for(const auto x : v){
        cout<<x<<", ";
    }
    cout<<endl;
    return 0;
}
