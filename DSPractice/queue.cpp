#include <iostream>
#include <stdexcept>
using namespace std;

void error(string err){
    throw runtime_error(err);
}

class Node{
    public:
        int val;
        Node* next;
        Node(){
            this->next = nullptr;
        }
        Node(int val){
            this->next = nullptr;
            this->val = val;
        }
};

class Queue{
    private:
        Node *front, *rear;

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
                error("pop() on a empty queue");
            }
            if(front == rear){
                front = rear = nullptr;
            }
            front = front->next;
        }

        int peekFront(){
            if(isEmpty()){
                error("peekFront() on a empty queue");
            }
            return front->val;
        }

        int back(){
            if(isEmpty()){
                error("back() on a empty queue");
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
