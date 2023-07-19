#include <iostream>
#include <vector>
using namespace std;


//variant of unbounded knapsack
int findCoins(vector<int>& v, const int amt){
    const int n = v.size();
    const int INF = (int) 1e9 + 7;
    vector<vector<int>> dp(n + 1, vector<int>(amt + 1));

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= amt; j++){
            if(i == 0 || j == 0){
                dp[i][j] = i == 0 ? INF : 0;
            }
            else if(i == 1){
                const int rem = j % v[i - 1];
                dp[i][j] = !rem ? (j / v[i - 1]) : INF;
            }
            else if(v[i - 1] <= j){
                dp[i][j] = min(1 + dp[i][j - v[i - 1]], dp[i - 1][j]);
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][amt] == INF ? -1 : dp[n][amt];
}

int main(){
    vector<int> v = {1, 2, 5};
    int amt = 11;
    cout<<findCoins(v, amt)<<endl;
    return 0;
}
