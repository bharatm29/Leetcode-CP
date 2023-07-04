#include <iostream>
#include <unordered_map>
using namespace std;

class LRU{
    private: 
        class Node{
            public:
                int key, val;
                Node* next;
                Node* prev;

                Node(){
                    next = nullptr;
                    prev = nullptr;
                }
                Node(int key, int val){
                    this->key = key;
                    this->val = val;
                }
        };

        int capacity;
        unordered_map<int, Node*> m;
        Node* head = new Node();
        Node* tail = new Node();

    public:
        LRU(int cap){
            this->capacity = cap;
            head->next = tail;
            tail->prev = head;
        }

        void addNode(Node* node){
            //add just after head
            Node* temp = head->next;

            head->next = node;
            node->prev = head;

            node->next = temp;
            temp->prev = node;
        }

        void deleteNode(Node* node){
            Node* nodePrev = node->prev;
            Node* nodeNext = node->next;

            nodePrev->next = nodeNext;
            nodeNext->prev = nodePrev;
        }

        int get(int key){
            if(m.find(key) != m.end()){
                int res = m[key]->val;

                Node* newNode = new Node(key, res);

                deleteNode(m[key]);
                addNode(newNode);

                m[key] = newNode;
                return res;
            }
            
            return -1;
        }

        void put(int key, int val){
            if(m.find(key) != m.end()){
                deleteNode(m[key]);
                m.erase(key);
            }
            if(capacity == m.size()){
                m.erase(tail->prev->val);
                deleteNode(tail->prev);
            }
            
            Node* newNode = new Node(key, val);
            addNode(newNode);
            m[key] = newNode;
        }
};

int main(){
    
    return 0;
}
