#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    vector<vector<int>> ans;
    priority_queue<pair<int, pair<int, int>>> maxH;

    for(const auto p : points){
        int dist = p[0] * p[0] + p[1] * p[1];
        maxH.push({dist, {p[0], p[1]}});
        if(maxH.size() > k){
            maxH.pop();
        }
    }

    while (!maxH.empty()) {
        ans.push_back({maxH.top().second.first, maxH.top().second.second});
        maxH.pop();
    }

    return ans;
}

int main(){
    vector<vector<int>> p = {{1,3}, {-2, 2}};
    vector<vector<int>> ans = kClosest(p, 1);
    for(const auto v : ans){
        for(const auto x : v){
            cout<<x<<", ";
        }
        cout<<endl;
    }
    return 0;
}
