#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node*  top = NULL;//initially the stack is empty.

bool isEmpty();

void push(int x){
    Node* temp = new Node;
    temp->data = x;
    temp->next = top;
    top = temp;
}

void pop(){
    Node* temp;
    if (isEmpty()){return;}//if stack is empty we return.
    temp = top;
    top = top->next;
    delete[] temp;
}

void peekTop(){cout<<"The top is: "<<top->data<<endl;}

void print(){
    Node* temp = top;
    cout<<"The stack is: "<<endl;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

bool isEmpty(){
    if (top == NULL)
    {
        return true;
    }
    else{
        return false;
    }
}

int main(){

    pop();
    push(2);
    push(3);
    push(7);
    print();
    pop();
    push(5);
    print();
    peekTop();
    return 0;
}
