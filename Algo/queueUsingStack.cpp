#include <iostream>
#include <stack>
using namespace std;

class Queue{
    private:
        stack<int> s1, s2;
    public:
        void push(const int val){
            s1.push(val);
        }

        void pop(){
            if(!s2.empty()){
                s2.pop();
                return;
            }
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }

            s2.pop();
        }

        int front(){
            if(!s2.empty()){
                return s2.top();
            }
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }

            return s2.top();
        }
};

int main(){
    Queue q;
    q.push(1);
    q.push(5);
    q.pop();
    cout<<q.front()<<endl;
    q.pop();
    q.push(7);
    q.push(2);
    cout<<q.front()<<endl;
    return 0;
}
