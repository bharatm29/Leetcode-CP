#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

vector<int> findAns(vector<int>& v, int k){
    vector<int> ans;
    map<int, int> m;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minH;

    for (const auto x : v){
        m[x]++;
    }

    for(const pair<int, int> p : m){
        minH.push({p.second, p.first});
        if (minH.size() > k) {
            minH.pop();
        }
    }

    while (!minH.empty()) {
        ans.push_back(minH.top().second);
        minH.pop();
    }

    return ans;
}

int main(){
    
    vector<int> v = {1, 1, 1, 3, 2, 2, 4};
    int k = 2;
    vector<int> ans = findAns(v, k);
    for(const auto x : ans){
        cout<<x<<" ";
    }
    return 0;
}
