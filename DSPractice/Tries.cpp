#include <iostream>
using namespace std;

class Node{
    public:
        Node* links[26];
        bool flag;

        bool containsKey(const char c){
            return links[c - 'a'];
        }

        void put(const char c, Node* node){
            links[c - 'a'] = node;
        }

        Node* get(const char c){
            return links[c - 'a'];
        }

        void setEnd(){
            this->flag = true;
        }

        bool isEnd(){
            return this->flag;
        }
};

class Trie{
    private:
        Node* root;
    public:
        Trie(){
            root = new Node();
        }

        void insert(const string s){
            Node* node = root;

            for(const auto c : s){
                if(!node->containsKey(c)){
                    node->put(c, new Node());       
                }
                node = node->get(c);
            }

            node->setEnd();
        }

        bool search(const string s){
            Node* node = root;

            for(const auto c : s){
                if(!node->containsKey(c)){
                    return false;
                }
                node = node->get(c);
            }

            return node->isEnd();
        }

        bool startsWith(const string s){
            Node* node = root;

            for(const auto c : s){
                if(!node->containsKey(c)){
                    return false;   
                }
                node = node->get(c);
            }

            return true;
        }
};

int main(){
    Trie t;
    t.insert("something");
    t.insert("asda");
    if(t.search("asda")){
        cout<<"TRUE"<<endl;
    }
    else{
        cout<<"FALSE"<<endl;
    }
    return 0;
}
