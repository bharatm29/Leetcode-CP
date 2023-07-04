#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

vector<int> larDivSub(vector<int>& nums){
    int n = nums.size();
    vector<int> dp(n, 1), seq(n), ans;
    int maxLen{INT32_MIN}, end{0};
    
    sort(nums.begin(), nums.end());
    
    for(int i = 1; i < n; i++){
        seq[i] = i;
        for(int j = 0; j < i; j++){
            if (nums[i] % nums[j] == 0 && dp[i] < 1 + dp[j]) {
                dp[i] = dp[j] + 1;
                seq[i] = j;
            }
        }
        if(maxLen < dp[i]){
            maxLen = dp[i];
            end = i;
        }
    }

    ans.push_back(nums[end]);
    while(end != seq[end]){
        end = seq[end];
        ans.push_back(nums[end]);
    }
    reverse(ans.begin(), ans.end());

    return ans;
}

int main(){
    vector<int> input = {1, 2, 4, 8};
    vector<int> ans = larDivSub(input);
    for(const auto x : ans){
        cout<<x<<", ";
    }
    cout<<endl;
    return 0;
}
