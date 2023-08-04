#include <iostream>
#include <stdexcept>
using namespace std;

void error(const string s){
    throw runtime_error(s);
}

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

class Queue{
    private:
        Node *front, *rear;
    public:
        bool isEmpty(){
            return !front && !rear;
        }

        void push(const int val){
            Node* node = new Node(val);
            if(isEmpty()){
                front = rear = node;
                return;
            }
            
            rear->next = node;
            rear = node;
        }

        void pop(){
            Node* node = front;

            if(front == rear){
                front = rear = nullptr;
                delete[] node;
                return;
            }

            front = front->next;
            delete[] node;
        }

        int peekFront(){
            return front->val;
        }

        int back(){
            return rear->val;
        }
};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    cout<<q.peekFront()<<endl;
    q.pop();
    cout<<q.peekFront()<<endl;
    q.push(5);
    q.push(4);
    q.pop();
    q.pop();
    q.push(9);
    cout<<q.peekFront()<<endl;
    cout<<q.back()<<endl;
    return 0;
}
