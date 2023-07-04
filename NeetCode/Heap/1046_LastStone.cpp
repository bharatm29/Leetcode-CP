#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int weight(vector<int>& v){
    priority_queue<int> q;
    for(const auto x : v){
        q.push(x);
    }

    while(q.size() != 1){
        int first = q.top();
        q.pop();
        int second = q.top();
        q.pop();

        q.push(abs(first - second));
    }

    return q.top();
}

int main(){
    vector<int> v = {2,7,4,1,8,1};
    cout<<weight(v)<<endl;

    return 0;
}
