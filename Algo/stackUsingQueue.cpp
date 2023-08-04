#include <iostream>
#include <queue>
using namespace std;

class Stack{
    private:
        queue<int> q;
    public:
        Stack(){}
        
        void push(const int val){
            q.push(val);

            const int sz = q.size();
            for(int i = 0; i < sz - 1; i++){
                q.push(q.front());
                q.pop();
            }
        }

        void pop(){
            q.pop();
        }

        int top(){
            return q.front();
        }
};

int main(){
    Stack s;
    s.push(1);
    s.push(3);
    cout<<s.top()<<endl;
    s.push(5);
    s.push(9);
    cout<<s.top()<<endl;
    return 0;
}
