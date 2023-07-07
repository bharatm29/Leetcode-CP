#include <algorithm>
#include <iostream>
using namespace std;

class Node{
    public:
        Node* left, *right;
        int val;
        Node(){
            this->left = this->right = nullptr;
        }
        Node(int val){
            this->left = this->right = nullptr;
            this->val = val;
        }
};

Node* root;

Node* insert(Node* root, const int val){
    if(root == nullptr){
        root = new Node(val);
        return root;
    }
    if(root->val < val){
        root->right = insert(root->right, val);
    }
    else if(root->val >= val){
        root->left = insert(root->left, val);
    }

    return root;
}

bool search(Node* root, const int val){
    if(!root){
        return false;
    }
    if(root->val == val){
        return true;
    }
    if(root->val < val){
        return search(root->right, val);
    }
    return search(root->left, val);
}

int findMaxHeight(Node* root){
    if(!root){
        return 0;
    }
    return 1 + max(findMaxHeight(root->left), findMaxHeight(root->right));
}

void inorder(Node* root){
    if(!root){
        return;
    }
    inorder(root->left);
    cout<<root->val<<endl;
    inorder(root->right);
}

int main(){
    root = nullptr;

    root = insert(root, 10);
    root = insert(root, 2);
    root = insert(root, 11);
    root = insert(root, 1);
    inorder(root);
    cout<<"Max height is: "<<findMaxHeight(root)<<endl;
    return 0;
}
