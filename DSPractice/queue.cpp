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
        Node* front, *rear;

    public:
        Queue(){
            front = rear = nullptr;
        }

        bool isEmpty(){
            return !front && !rear;
        }

        void push(const int val){
            Node* temp = new Node(val);

            if(isEmpty()){
                front = rear = temp;
                return;
            }
            
            rear->next = temp;
            rear = temp;
        }

        void pop(){
            if(isEmpty()){
                error("pop() on an empty queue");
            }

            Node* temp = front;
            front = front->next;

            delete temp;
        }

        int peekFront(){
            if(isEmpty()){
                error("peekFront() on an empty queue");
            }

            return front->val;
        }

        int back(){
            if(isEmpty()){
                error("back() on an empty queue");
            }

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
    cout<<q.back()<<endl;
    return 0;
}
