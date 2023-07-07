#include<iostream>
#include <stdexcept>
using namespace std;

class Node{
    public:
        Node* next;
        Node* prev;
        int val;
        Node(){
            this->next = this->prev = nullptr;
        }
        Node(const int val){
            this->next = this->prev = nullptr;
            this->val = val;
        }
};

class List{
    private:
        Node* head;
    public:
        List(){
            this->head = nullptr;
        }

        void insertAtHead(const int val){
            Node* temp = new Node(val);
            if(!head){
                head = temp;
                return;
            }
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        
        void insert(const int val, const int pos){
            Node* newNode = new Node(val);
            if(pos <= 1){
                insertAtHead(val);
                return;
            }
            Node *temp{head}, *temp2{head};
            for(int i = 0; i <  pos - 1; i++){
                temp2 = temp;
                temp = temp->next;
            }
            temp2->next = newNode;
            temp->prev = newNode;
            newNode->next = temp;
            newNode->prev = temp2;
        }

        void deleteAtHead(){
            Node* temp = head;
            head = head->next;
            if(head){
                head->prev = nullptr;
            }
            delete[] temp;
        }

        void printList(){
            Node* temp = head;
            while(temp){
                cout<<temp->val<<endl;
                temp = temp->next;
            }
        }

        void reverse(){
            Node* prev = nullptr;
            Node* curr = head;
            while(curr){
                Node* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }
            head = prev;
        }

        void reverseRec(Node* p){
            if(!p || !p->next){
                head = p;
                return;
            }
            reverseRec(p->next);

            Node* q = p->next;
            q->next = p;
            p->next = nullptr;
        }

        Node* getHead(){
            return head;
        }
};

int main(){
    List ls;
    ls.insertAtHead(10);
    ls.insert(1, 1);
    ls.insert(2, 2);
    ls.insert(5, 3);
    ls.deleteAtHead();
    ls.insert(2, 3);
    ls.printList();
    cout<<"Reversed"<<endl;
    ls.reverseRec(ls.getHead());
    ls.printList();
    return 0;
}
