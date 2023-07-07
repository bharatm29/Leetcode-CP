#include <iostream>
using namespace std;

#define max_size 101
int A[max_size];
int top{-1};//the stack is empty if top == -1;

void push(int x){
    if (top == max_size - 1)
    {
        cout<<"error:stack overflow"<<endl;
        return;
    }    
    A[++top] = x;
}

void pop(){
    if (top == -1)
    {
        cout<<"error pop(): empty stack"<<endl;
    }
    top--;
}

int peekTop(){return A[top];}

void print(){
    cout<<"The stack is: "<<endl;
    for (int i = 0; i <= top; i++)
    {
        cout<<A[i]<<endl;
    }
}

int main(){

    push(2);
    push(4);
    push(8);
    print();
    pop();
    push(7);
    print();
    return 0;
}
