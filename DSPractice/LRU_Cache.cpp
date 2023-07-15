#include <iostream>
#include <regex>
#include <stack>
#include <unordered_map>
using namespace std;

class Node{
    public:
        int key, val;
        Node* next, *prev;

        Node(){
            this->next = this->prev = nullptr;
        }

        Node(const int key, const int val){
            this->next = this->prev = nullptr;
            this->key = key;
            this->val = val;
        }
};

class LRU{
    private:
        Node *head, *tail;
        unordered_map<int, Node*> m;
        int capacity;
    public:
        LRU(const int capacity){
            this->capacity = capacity;
            
            head = new Node();
            tail = new Node();

            head->next = tail;
            tail->prev = head;
        }

        void addNode(Node* node){
            Node* nextNode = head->next;

            node->prev = head;
            head->next = node;

            nextNode->prev = node;
            node->next = nextNode;
        }

        void deleteNode(Node* node){
            Node* nextNode = node->next;
            Node* prevNode = node->prev;

            prevNode->next = nextNode;
            nextNode->prev = prevNode;
        }

        void put(const int key, const int val){
            if(m.find(key) != m.end()){
                deleteNode(m[key]);
                m.erase(key);
            }
            if(this->capacity == this->m.size()){
                m.erase(tail->prev->key);
                deleteNode(tail->prev);
            }

            Node* newNode = new Node(key, val);
            m[key] = newNode;

            addNode(newNode);
        }

        int get(const int key){
            if(m.find(key) == m.end()){
                return -1;
            }
            const int res = m[key]->val;
            
            deleteNode(m[key]);
            m.erase(key);

            Node* newNode = new Node(key, res);
            addNode(newNode);
            m[key] = newNode;

            return res;
        }
};

int main(){
    LRU l(3);
    l.put(2, 3);
    l.put(3, 2);
    l.put(7, 1);
    l.put(4, 2);
    cout<<l.get(2)<<endl;
    return 0;
}
