#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& v, const int low, const int mid, const int high){
    int i = low;
    int j = mid + 1;

    vector<int> temp;
    while(i <= mid && j <= high){
        if(v[i] <= v[j]){
            temp.push_back(v[i]);
            i++;
        }
        else{
            temp.push_back(v[j]);
            j++;
        }
    }

    while(i <= mid){
            temp.push_back(v[i]);
            i++;
    }

    while(j <= high){
            temp.push_back(v[j]);
            j++;
    }

    for(int k = low; k <= high; k++){
        v[k] = temp[k - low];
    }
}

void mergeSort(vector<int>& arr, const int low, const int high){
    if(low >= high){
        return;
    }
    const int mid = (low + high) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main(){
    vector<int> arr;
    for(int i; cin>>i;){
        arr.push_back(i);
    }
    mergeSort(arr, 0, arr.size() - 1);
    for(const auto x : arr){
        cout<<x<<", ";
    }
    cout<<endl;
    return 0;
}

