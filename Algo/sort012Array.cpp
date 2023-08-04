#include <iostream>
#include <vector>
using namespace std;

//using Dutch National Flag algorithm
void sortArr(vector<int>& v){
    const int n = v.size();
    int low{0}, mid{0}, high{n - 1};

    while(mid <= high){
        if(!v[mid]){
            swap(v[low], v[mid]);
            mid++;
            low++;
        }
        else if(v[mid] == 1){
            mid++;
        }
        else{
            swap(v[high], v[mid]);
            high--;
        }
    }
}

int main(){
    vector<int> v = {1, 0, 2, 2, 0, 1, 2, 2, 1, 0};
    sortArr(v);
    for(const auto x : v){
        cout<<x<<", ";
    }
    cout<<endl;
    return 0;
}
