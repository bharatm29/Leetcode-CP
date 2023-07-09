#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr){
    const int n = arr.size();
    for(int i = 1; i < n; i++){
        int j = i;
        while(arr[j - 1] > arr[j]){
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
}

int main(){
    vector<int> arr;
    for(int i; cin>>i;){
        arr.push_back(i);
    }
    insertionSort(arr);
    for(const auto x : arr){
        cout<<x<<", ";
    }
    cout<<endl;
    return 0;
}
