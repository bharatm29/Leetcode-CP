#include <cstdint>
#include <iostream>
#include <map>
using namespace std;

int charReplace(string& s, int k){
    int n = s.length();
    map<char, int> m;
    
    int i{0}, j{0}, ans{INT32_MIN};

    while (j < n) {
        m[s[j]]++;

        if(m.size() < 2){
            j++;
        }
        else if(m.size() == 2){
            for(const auto [key, val] : m){
                if(val == k){
                    ans = max(ans, j - i + 1); 
                }
            }

            j++;
        }
        else if (m.size() > 2) {
            while (m.size() > 2) {
                if(--m[s[i]] == 0){
                    m.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }

    return ans;
}

int main(){
    string s{""};
    int k{0};
    cin>>s>>k;
    cout<<charReplace(s, k)<<endl;
    return 0;
}
