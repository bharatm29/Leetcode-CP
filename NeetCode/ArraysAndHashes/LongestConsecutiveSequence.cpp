#include <cstdint>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int findMax(vector<int>& v){
    
    set<int> s;
    for(const auto x : v){
    
        s.insert(x);
    }
    int ans{INT32_MIN}, cnt{0};
    for(const auto x : v){
        
        if(!s.count(x - 1)){
            
            cnt++;
            int temp = x + 1;
            while(s.count(temp)){
                
                temp++;
                cnt++;
            }
            ans = max(ans, cnt);
            cnt = 0;
        }
    }

    return ans;
}

int main(){
    
    vector<int> v = {100, 200, 201, 202, 1, 2, 3, 3, 4, 203};
    cout<<findMax(v)<<endl;
    return 0;
}
