#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int findLis1(vector<int>& nums){
    const int n = nums.size();
    int maxLen{0}, end{0};

    vector<int> dp(n + 1, 1);
    vector<int> seq(n);

    for(int i = 0; i < n; i++){
        seq[i] = i;
        for(int j = 0; j < i; j++){
            if(nums[i] > nums[j] && dp[i] < 1 + dp[j]){
                dp[i] = 1 + dp[j];
                seq[i] = j;
            }
        }

        if(maxLen < dp[i]){
            maxLen = dp[i];
            end = i;
        }
    }

    stack<int> s;
    s.push(nums[end]);

    while(end != seq[end]){
        end = seq[end];
        s.push(nums[end]);
    }
    
    while(!s.empty()){
        cout<<s.top()<<", ";
        s.pop();
    }
    cout<<endl;

    return maxLen;
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
