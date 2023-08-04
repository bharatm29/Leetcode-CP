#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool checkPair(string& s1, string& s2){
    const int n = s1.length();
    const int m = s2.length();

    if(n != m + 1){
        return false;
    }

    int i{0}, j{0};

    while(i < n){
        if(j < m && s1[i] == s2[j]){
            i++;
            j++;
        }
        else{
            i++;
        }
    }

    return i == n && j == m;
}

int lonStringChain(vector<string>& v){
    const int n = v.size();

    vector<int> dp(n, 1);
    int ans{0};

    sort(v.begin(), v.end(), [&](string a, string b){
                return a.length() < b.length();
            });

    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(dp[j] + 1 > dp[i] && checkPair(v[i], v[j])){
                dp[i] = dp[j] + 1;
            }
        }
        ans = max(dp[i], ans);
    }

    return ans;
}

int main(){
    vector<string> v = {"xbc","pcxbcf","xb","cxbc","pcxbc"};
    cout<<lonStringChain(v)<<endl;
    return 0;
}
