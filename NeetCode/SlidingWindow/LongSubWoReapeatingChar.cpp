#include <cstdint>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int findMax(string& s){
    
    int n = s.length();
    map<char, int> m;

    int i{0}, j{0};
    int mxLen{1};

    while(j < n){
        
        m[s[j]]++;
        
        if(m.size() == j - i + 1){
            mxLen = max(mxLen, j - i + 1);
            j++;
        }
        else if (m.size() < j - i + 1) {
            while (m.size() < j - i + 1) {
                m[s[i]]--;
                if(!m[s[i]]){
                    m.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }

    return mxLen;
}

int main(){
    
    string s{""};
    cin>>s;
    cout<<"The answer is: "<<findMax(s)<<endl;
    return 0;
}
