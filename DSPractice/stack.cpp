#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

#define max_sz 101

void error(string err){
    throw runtime_error(err);
}

class StackArr{
    private:
        vector<int> v;
        int top{-1};
    public:
        StackArr(){
            v.resize(max_sz);
        }
        
        void push(const int val){
            if(top == max_sz){
                error("Max Size reached");
            }

            v[++top] = val;
        }
        
        void pop(){
            if(top == -1){
                error("Stack is empty");
            }
            --top;
        }

        int getTop(){
            if(top == -1){
                error("Stack is empty");
            }

            return v[top];
        }
};

class Node{
    public:
        Node* next;
        int val;

        Node(){
            this->next = nullptr;
        }

        Node(const int val){
            this->val = val;
            this->next = nullptr;
        }
};

class StackList{
    private:
        Node* topPtr;
    public:
        StackList(){
            topPtr = nullptr;
        }

        bool isEmpty(){
            return !topPtr;
        }

        void push(const int val){
            Node* temp = new Node(val);

            temp->next = topPtr;

            topPtr = temp;
        }

        void pop(){
            if(isEmpty()){
                error("pop() on a empty stack");
            }
            Node* temp = topPtr;
            topPtr = topPtr->next;

            delete[] temp;
        }

        int top(){
            if(isEmpty()){
                error("top() on a empty stack");
            }
            return topPtr->val;
        }
};
int main(){
    StackList s;
    s.push(1);
    s.push(3);
    s.pop();
    cout<<s.top()<<endl;
    s.push(6);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    return 0;
}
