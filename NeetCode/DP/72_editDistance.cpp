#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int findAns(int n, int m, string& a, string& b){
    if (n == 0 && m == 0){
        return 0;
    }
    if(n == 0 && m > 0){
        return m;
    }
    if(n > 0 && m == 0){
        return n;
    }
    if(a[n - 1] == b[m - 1]){
        return findAns(n - 1, m - 1, a, b);
    }
    int insert = 1 + findAns(n, m - 1, a, b);
    int deleteOp = 1 + findAns(n - 1, m, a, b);
    int replace = 1 + findAns(n - 1, m - 1, a, b);

    return min(insert, min(deleteOp, replace));
}

int editDistance(string& a, string& b){
    int n = a.length();
    int m = b.length();
    // return findAns(n, m, a, b);
    vector<vector<int>> dp(n + 1, vector<int>(m +1));
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0 || j == 0){
                if(i == 0 && j == 0){
                    dp[i][j] = 0;
                }
                else if (i == 0 && j > 0) {
                    dp[i][j] = j;
                }
                else {
                    dp[i][j] = i;
                }
            }
            else if(a[i - 1] == b[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                int insert = 1 + dp[i][j - 1];
                int deleted = 1 + dp[i - 1][j];
                int replace = 1 + dp[i - 1][j - 1];
                dp[i][j] = min(insert, min(deleted, replace));
            }
        }
    }

    return dp[n][m];
}

int main(){
    string a, b;
    cin>>a>>b;
    cout<<editDistance(a, b)<<endl;
    return 0;
}
