#include <iostream>
#include <map>

#include <vector>
using namespace std;

vector<int> findAnagrams(string& a, string& b){
    vector<int> ans;

    int n = a.length();
    int swl = b.length();

    map<char,int> m;
    
    int cnt{0}, i{0}, j{0};

    for(const auto c : b){
        m[c]++;   
    }
    cnt = m.size();

    while (j < n) {
        if (--m[a[j]] == 0) {
            cnt--;
        }

        if (j - i + 1 < swl) {
            j++;
        }
        else if (j - i + 1 == swl) {
            //ans => remove calculations for i => slide the window! 
            if(!cnt){
                ans.push_back(i);   
            }

            if(++m[a[i]] == 1){
                cnt++;   
            }
            i++;
            j++;
        }
    }

    return ans;
}

int main(){
    
    string a, b;
    cin>>a>>b;
    vector<int> ans = findAnagrams(a, b);
    cout<<"[ ";
    for(const auto x : ans){
        cout<<x<<", ";
    }
    cout<<" ]"<<endl;
    return 0;
}
