#include <iostream>
#include <vector>
using namespace std;

bool findAns(int n, int m, string& a, string& b){
    if(n == 0 && m == 0){
        return true;
    }
    if(n == 0 && m > 0){
        return false;
    }
    if(n > 0 && m == 0){
        for(int i = 0; i < n; i++){
            if(a[i] != '*'){
                return false;
            }
        }

        return true;
    }
    
    if(a[n - 1] == b[m - 1] || a[n - 1] == '?'){
        return findAns(n - 1, m - 1, a, b);
    }
    else if(a[n - 1] == '*'){
        return findAns(n - 1, m, a, b) || findAns(n, m - 1, a, b);
    }

    return false;
}

bool isMatch(string& a, string& b){
    int n = a.length();
    int m = b.length();
    // return findAns(m, n, b, a);

    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0 || j == 0){
                if(i == 0 && j == 0){
                    dp[i][j] = true;
                }
                else if(i == 0 && j > 0){
                    bool flag = true;
                    for(int k = 0; k < j; k++){
                        if (b[k] != '*') {
                            flag = false;
                            break;
                        }
                    }
                    dp[i][j] = flag;                    
                }
                else{
                    dp[i][j] = false;
                }
            }
            else if(a[i - 1] == b[j - 1] || b[j - 1] == '?'){
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if(b[j - 1] == '*'){
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
        }
    }
    
    return dp[n][m];
}

int main(){
    string a, b;
    cin>>a>>b;
    if(isMatch(a, b)){
        cout<<"TRUE";
    }
    else{
        cout<<"FALSE";
    }
    return 0;
}
