#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr){
    const int n = arr.size();
   for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < i; j++){
            if(arr[j + 1] < arr[j]){
                swap(arr[j + 1], arr[j]);
            }
        }
    }
}

int main(){
    vector<int> arr;
    for(int i; cin>>i;){
        arr.push_back(i);
    }
    bubbleSort(arr);
    for(const auto x : arr){
        cout<<x<<", ";
    }
    cout<<endl;
    return 0;
}
