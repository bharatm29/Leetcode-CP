#include <iostream>
#include <map>
using namespace std;

bool checkInclusion(string& a, string& b){
    
    int n = b.length();
    int swl = a.length();
    int i{0}, j{0};
    
    map<char, int> m;
    int cnt{0};

    for(const auto x : a){
        m[x]++;
    }
    
    cnt = m.size();

    while (j < n) {
        m[b[j]]--;
        if(!m[b[j]]){
            cnt--;
        }
        else if (j - i + 1 < swl) {
            j++;
        }
        else if (j - i + 1 == swl) {
            if(!cnt){
                return true;   
            }

            if(++m[b[j]] == 1){
                cnt++;   
            }

            i++;
            j++;
        }
    }

    return false;
}

int main(){
    string a = "ab";
    string b = "eidboaoo";

    if(checkInclusion(a, b)){
        
        cout<<"TRUE"<<endl;
    }
    else {
        cout<<"FALSE"<<endl;
    }

    return 0;
}
