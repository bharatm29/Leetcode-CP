#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> sortAll(vector<int>& v, int k){
    vector<int> ans;
    priority_queue<int, vector<int>, greater<>> minH;

    for(const auto x : v){
        minH.push(x);
        if (minH.size() > k) {
            ans.push_back(minH.top());
            minH.pop();
        }
    }

    while (!minH.empty()) {
        ans.push_back(minH.top());
        minH.pop();
    }

    return ans;
}

int main(){
    vector<int> v = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    vector<int> ans = sortAll(v, k);
    for(const auto x : ans){
        cout<<x<<" ";
    }
    return 0;
}
