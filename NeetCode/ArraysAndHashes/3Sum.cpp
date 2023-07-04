#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> findSum(vector<int>& v){
    int n = v.size();
    vector<vector<int>> ans;
    
    sort(v.begin(), v.end());

    for(int i = 0; i < n - 2; i++){
        if(i == 0 || (i > 0 && v[i] != v[i - 1])){
            
            int low{i + 1}, hi{n - 1};
            int sum = 0 - v[i];

            while(low < hi){
                if(v[low] + v[hi] == sum){
                    vector<int> temp = {v[i], v[low], v[hi]};
                    ans.push_back(temp);
                    
                    while(low < hi && v[low] == v[low + 1]){
                        low++;
                    }
                    while(low < hi && v[hi] == v[hi - 1]){
                        hi--;
                    }
                    low++;
                    hi--;
                }

                else if (v[low] + v[hi] > sum) {
                    hi--;
                }
                else {
                    low++;
                }
            }
        }
    }

    return ans;
}

int main(){
    
    vector<int> v = {-1,0,1,2,-1,-4};
    vector<vector<int>> ans = findSum(v);
    for(const auto vec : ans){
        cout<<"[ ";
        for(const auto x : vec){
            cout<<x<<" ";
        }
        
        cout<<" ]"<<endl;
    }
    return 0;
}
