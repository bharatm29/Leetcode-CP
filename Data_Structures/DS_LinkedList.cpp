//LinkedList program from the mycodeschool Data Structure Playlist.[video: 3-12]

#include <iostream>
#include <conio.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

//the head node is only a pointer to the head node or the first node in the Linked List not the node itself.
Node* head;//defining a Global variable which will hold the address of the first node of the LinkedList.

//INSERTING AT THE BEGINNING NAIVELY: 
void insertHead(Node* pointerHead, int x){//the first argument is a pointer to pointer since we want to modify the global head pointer[pass by reference].
    Node* temp = new Node;//Here, the temp is a pointer variable and we are dereferencing the 
    //pointer variable to modify the value of a particular node.
    temp->data = x;
    //if we are inserting at the beginning of the non-empty list.
    temp->next = pointerHead;//the local head reference of the global head.//sets the next of the newly created Node to the Node which head is pointing.
    pointerHead = temp;
}

void insert(int data, int n){//insert the node at nth  position
//We use the new operator[memory from heap] since we want to make it so that the Node will exist even after the function is executed.
    Node* temp1 = new Node;
    temp1->data = data;
    temp1->next = NULL;
    if (n == 1)
    {
        temp1->next = head;
        head = temp1;
        return;
    }
    Node* temp2 = head;
    for (int i = 0; i < n-2; i++)
    {//we will run the loop till temp2 reaches (n-2), then simply make temp2 = temp2->next for the last time, which means that temp2 will be pointing to (n-1) node.
        temp2 = temp2->next;
    }

    // if (temp2)
    // {//for understanding that temp2 is pointing to (n-1)
    //     cout<<temp2->data<<endl;
    // }
    //Now since temp2 is pointing to (n-1) we will set the next of the n-1 node to point to n 
    //and Meanwhile also set the next of the newly created node to the next of n-1 node;
    temp1->next = temp2->next;//sets the next of the newly created node equal to the next of n-    
    temp2->next = temp1;//sets the next of the (n-1)th node to point to the newly created node.    
}

void Delete(int n){//Delete the node at nth  position

    Node* temp1 =  head;
    if (n == 1)//in case we are deleting the first node.
    {
        head = temp1->next;//points the head to the second node.
        delete[] temp1;//free up temp1 since we have no use of it anymore.
        return;//since we don't want to execute the code below it.        
    }    

    for (int i = 0; i < n-2; i++)
    {
        temp1 = temp1->next;//temp1 points to the (n-1)th node.
    }
    Node* temp2 = temp1->next;//temp2 points to nth node.

    temp1->next = temp2->next;//sets the next of the (n-1)th node to points to the (n+1)th node.

    delete[] temp2;//free up memory for the nth node since we have no use for it anymore.
}

//reversing normally - iterative, traversing through each node thereby changing the link to previous.
void reverse(){
    //to reverse the link we just traverse through the list and sets the next of all the nodes to the previous.
    //the following implementation will work in the case of empty list or when we have only one node in our list.[no changes required]

    Node* current, *prev, *nextNode;
    current = head;
    prev = NULL;

    /*to keep track of current and previous node we have defines two pointers.
    But we have a problem becasue if we adjust the next of the node to the previous then we wouldn't
    be able to access the next node by simply doing current.next so we have to make another pointer 
    next to keep the information of the next of the current node*/
    
    while (current != NULL)//loop to traverse to the end of the Linked List.
    {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    head = prev;//making head point to the last node.Since when current is NULL, prev will be pointing the last node.
}

//reversing recursively
void reverseRec(Node* p){
    if (p->next == NULL)
    {
        head = p;
        return;
    }
//when we are travelling the backward direction we will be change the next(s) of the nodes.
    reverseRec(p->next);
//we won't reverse the Linked List at once, but will make sure that as the Recusive call of the
//function ends the list is reversed till that node.
    Node* q = p->next;
    q->next = p;
    //the above two line can also be stated as: 
    // p->next->next = p;
    p->next = NULL;    
}

//Simple Printing.
// void print(Node* head){//print the data of all the nodes in the Linked List.
//     // Node* temp = head;//we use another pointer to Node, temp to transverse the list because
//     // //we do not want to modify the head pointer.
//     cout<<"The Linked List is: "<<endl;
//     while(head != NULL){//loop to traverse to the end of the loop.
//         cout<<head->data<<" ";
//         head = head->next;
//     }
//     cout<<endl;
// }

//Printing using Recusions: 
void print(Node* p){
    if (p == NULL)//termination condition or base condition.
    {
        return;        
    }    
    cout<<p->data<<" ";//print the value of the current node.
    print(p->next);//Recusive calls itself by passing the address of the next node.
}

void printRev(Node* p){
    if (p == NULL)
    {
        return;
    }
    //We will just change the order of the last two lines in the print()[recusive one].
    //now, first the recursion happens then the value is printed thus printing in the reverse order.
    printRev(p->next);
    cout<<p->data<<" ";
    //a recursive function in some way gives us a way to first travel forward and then travel backward.
}

int main(){
    system("cls");
//we can either define the head as a local var in the main function and pass as a reference in the functions 
//defined by passing the argument as pointer to pointer.
    head = NULL;//initially the list is empty.
    insert(2, 1);
    insert(6, 2);
    insert(4, 3);
    insert(7, 4);

    // print(head);//traverse print
    print(head);//recursive print
    cout<<endl;
    // printRev(head);//Recursive reverse print.

    cout<<"Reversing by Recursion"<<endl;
    reverseRec(head);//Reversing by Recursion.
    print(head);

//for reverse lesson
    // reverse();
    // print(head);
    
    // Delete(3);
    // print(head);
    return 0;
}