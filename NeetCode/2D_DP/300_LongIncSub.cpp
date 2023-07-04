#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int findLis1(vector<int>& nums){
    int n = nums.size();
    vector<int> dp(n, 1), seq(n);
    int ans{1}, end{0};
    
    for(int i = 1; i < n; i++){
        seq[i] = i;
        for(int j = 0; j < i; j++){
            if(nums[j] < nums[i] && dp[i] < dp[j] + 1){
                dp[i] = 1 + dp[j];
                seq[i] = j;
            }
        }
        if (ans < dp[i]) {
            ans = dp[i];
            end = i;
        }
    }

    vector<int> lis = {nums[end]};
    while (end != seq[end]) {
        end = seq[end];
        lis.push_back(nums[end]);
    }
    reverse(lis.begin(), lis.end());
    for (const auto x : lis){
        cout<<x<<", ";
    }
    cout<<endl;

    return ans;
}

int findLis2(vector<int>& nums){
    int n = nums.size();
    vector<int> buff = {nums[0]};

    for(int i = 1; i < n; i++){
        if(buff.back() < nums[i]){
            buff.push_back(nums[i]);
        }
        else {
            int index = lower_bound(buff.begin(), buff.end(), nums[i]) - buff.begin();
            buff[index] = nums[i];
        }
    }

    return buff.size();
}

int main(){
    vector<int> v = {10,9,2,5,3,7,101,18};
    cout<<findLis1(v)<<endl;
    return 0;
}
