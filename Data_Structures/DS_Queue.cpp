#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* link;
};

Node* front;
Node* rear;

void enqueue(int data){
    //the enqueue or the insertion of a node will occur at the end[that's what a queue is]
    // first we create a new node in the dynamic memory[heap]
    Node* temp = new Node;
    temp->data = data;
    temp->link = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = temp;//if the queue is empty we make front and rear to point to the new node.
    }
    rear->link = temp;//if the queue is not empty, we simply make the link of the previous node 
                      //and make rear point to the new node.
    rear = temp;
    //cout<<"Front: "<<front->data<<endl;
    //cout<<"Rear: "<<rear->data<<endl;
    return;
}

void dequeue(){
    Node* temp = front;//to free up memory for the deleted Node.
    if (front == NULL)
    {
        cout<<"Error: The queue is empty"<<endl;
        return;
    }
    else if (front == rear)//did an error here [did front = rear], which broke 
                           //the dequeue function. Even now i can't understand how but 
                           //maybe i was setting the front to rear all the time? :(
    {
        cout<<"1.)The front data is: "<<front->data<<endl;
        front = rear = NULL;
    }    
    else{
        cout<<"The front data is: "<<front->data<<endl;
        front = front->link;
    }
    delete[] temp;
}

void peekFront(){
    if (front == NULL)
    {
        cout<<"Error: the queue is empty"<<endl;
        return;
    }
    else{
        cout<<"Front data: "<<front->data<<endl;
    }
}

void print(){
    Node* temp = front;
    cout<<"The Queue is: "<<endl;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->link;
    }
    cout<<endl;
}

int main(){

    front = NULL;//initially the queue is empty.
    rear = NULL;
    enqueue(2);
    enqueue(4);
    enqueue(6);
    peekFront();
    print();
    dequeue();
    print();
    return 0;
}
