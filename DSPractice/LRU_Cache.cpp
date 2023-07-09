#include <iostream>
#include <regex>
#include <stack>
#include <unordered_map>
using namespace std;

class Node{
    public:
        Node* next, *prev;
        int key, val;

        Node(){
            this->next = nullptr;
            this->prev = nullptr;
        }

        Node(const int key, const int val){
            this->key = key;
            this->val = val;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class LRU{
    private:
        unordered_map<int, Node*> m;
        Node* head, *tail;
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

            head->next = node;
            node->prev = head;

            node->next = nextNode;
            nextNode->prev = node;
        }

        void deleteNode(Node* node){
            Node* nextNode = node->next;
            Node* prevNode = node->prev;

            nextNode->prev = prevNode;
            prevNode->next = nextNode;
        }

        void put(const int key, const int val){
            if(m.find(key) != m.end()){
                deleteNode(m[key]);
                m.erase(key);
            }
            if(capacity == m.size()){
                m.erase(tail->prev->key);
                deleteNode(tail->prev);
            }

            Node* newNode = new Node(key, val);
            addNode(newNode);
            m[key] = newNode;
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
