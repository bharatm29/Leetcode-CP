#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

Node* head;

//we wrote a different function to avoid duplication of the same code inside other function body.
Node* makeNewNode(int x){
    Node* newNodePtr = new Node;
    newNodePtr->data = x;
    newNodePtr->prev = NULL;
    newNodePtr->next = NULL;
    return newNodePtr;
}

void print(){
    Node* temp = head;
    cout<<"The LinkedList is: "<<endl;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }    
    cout<<endl;
}

void reversePrint(){
    Node* temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
    }
    cout<<"The reverse LinkedList is: "<<endl;
    while (temp != NULL)
    {
        cout<<temp->data;
        temp  = temp->prev;
    }
    cout<<endl;
}

void insertHead(int x){
    Node* newNode = makeNewNode(x);
    if (head == NULL)
    {
        head == newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;    
}

int main(){

    head = NULL;//initially the list is empty.
    insertHead(2);
    reversePrint();
    insertHead(3);
    print();
    insertHead(7);
    print();
    return 0;
}