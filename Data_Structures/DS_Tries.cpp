#include <iostream>
using namespace std;

class Node{
    private:
        Node* links[26];
        bool flag;
    public:
        Node(){
            flag = false;
        }
        
        Node* get(const char c){
            return links[c - 'a'];
        }

        bool containsKey(const char c){
            return links[c - 'a'] != nullptr;
        }

        void put(const char c, Node* node){
            links[c - 'a'] = node;
        }

        void setEnd(){
            flag = true;
        }

        bool isEnd(){
            return flag;
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

            const int n = s.length();
            for(int i = 0; i < n; i++){
                if(!node->containsKey(s[i])){
                    node->put(s[i], new Node());
                }
                node = node->get(s[i]);
            }
            node->setEnd();
        }

        bool searchWord(const string s){
            Node* node = root;

            const int n = s.length();
            for(int i = 0; i < n; i++){
                if(!node->containsKey(s[i])){
                    return false;
                }
                node = node->get(s[i]);
            }
            return node->isEnd();
        }

        bool startsWith(const string s){
            Node* node = root;

            const int n = s.length();
            for(int i = 0; i < n; i++){
                if(!node->containsKey(s[i])){
                    return false;
                }
                node = node->get(s[i]);
            }

            return true;
        }
};

int main(){
    Trie t;
    t.insert("bharat");
    t.insert("something");
    if(t.startsWith("aasdada")){
        cout<<"TRUE"<<endl;
    }
    else{
        cout<<"FALSE"<<endl;
    }    
    return 0;
}
