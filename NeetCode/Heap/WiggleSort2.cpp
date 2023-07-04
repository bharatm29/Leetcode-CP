#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void wiggleSort(vector<int>& v){
    priority_queue<int, vector<int>, greater<>> minHeap;
    priority_queue<int> maxHeap;
    int k = v.size()/2;
    for(const auto x : v){
        minHeap.push(x);
        maxHeap.push(x);

        if(minHeap.size() > k){
            minHeap.pop();
        }
        if(maxHeap.size() > k){
            maxHeap.pop();
        }
    }
    
    v.clear();

    while(!maxHeap.empty() || !minHeap.empty()){
        v.push_back(minHeap.top());
        v.push_back(maxHeap.top());
        minHeap.pop();
        maxHeap.pop();
    }
}

int main(){
    vector<int> v = {1,5,1,1,6,4};
    wiggleSort(v);
    for (const auto x : v){
        cout<<x<<", ";
    }
    return 0;
}
