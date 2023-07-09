#include <iostream>
#include <vector>
using namespace std;

int pivot(vector<int>& v, const int low, const int high){
    const int pivotVal = v[low];
    int i = low;
    int j = high;
    while(i < j){
        while(i < high && v[i] <= pivotVal){
            i++;
        }
        while(j > 0 && v[j] > pivotVal){
            j--;
        }
        if(i < j){
            swap(v[i], v[j]);
        }
    }
    swap(v[j], v[low]);
    return j;
}

void quickSort(vector<int>& v, const int low, const int high){
    if(low >= high){
        return;
    }
    const int pivotIndex = pivot(v, low, high);
    quickSort(v, low, pivotIndex - 1);
    quickSort(v, pivotIndex + 1, high);
}

int main(){
    vector<int> arr;
    for(int i; cin>>i;){
        arr.push_back(i);
    }
    quickSort(arr, 0, arr.size() - 1);
    for(const auto x : arr){
        cout<<x<<", ";
    }
    cout<<endl;
    return 0;
}
