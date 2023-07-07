#include <iostream>
#include <conio.h>
#include <queue>
using namespace std;

struct BSTNode
{
    int data;
    BSTNode* left;
    BSTNode* right;
};

//For creating a node:
BSTNode* createNode(int data){
    BSTNode* newNode = new BSTNode;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//For inserting a node
BSTNode* insert(BSTNode* root, int data){
    // if the tree is empty we simple call the createNod() and assign the address to the root node.
    if (root == NULL)
    {
        root = createNode(data);
        return root;
    }
    //when the tree is not empty, we first comare the data to be added to the data of the root, if the root->data>=data then
    // we simply add that to the left by recursively calling the insert function for the left of root.
    //this insert function will return an address of a new node and this left of root will point to it.
    else if (root->data >= data)
    {
        root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }
    return root;
}

//For searching a value in the tree:
bool search(BSTNode* root, int data){
    //first see if the root is the data we are searching for.
    if (root == NULL)
    {//if we reached the end level or the leaf then we simply reaturns false since we will not be able to find the data at any other location.
        return false;
    }
    
    else if (root->data == data)
    {
        return true;
    }
    //if root doesn't have the data, we simply compare it with the root's data and go left and right for searching according to it.
    // this is when property of Binary Search Tree come in handy, since we know the data less than root's data will be put on left and greater on right we can define our domain.

    //if the data is less than root's data we go to the left subtree for searching. To do this we simply call the search() for root->left
    //which is the root of the left subtree. Now, we go into the left subtree for searching and then the process continues till we reach the number we are searching.
    else if (root->data >= data)
    {
        return search(root->left, data);
    }
    //if the data is greater than the root's data, we do as same as the above case but for right.
    else{
        return search(root->right, data);
    }
    return false;
}

//iterative solution: Returns address
BSTNode* findMin(BSTNode* root){
    //in this method we will simple traverse the tree as far left as possible, at the end we will be at the node with minimum value.
    if (root == NULL)
    {
        cout<<"Error: Tree is empty"<<endl;
        return NULL;// we have to return int that's why -1 which  means the process is failed.
    }
    while (root != NULL)
    {
        root = root->left;
    }
    return root;
}

//Recursive Method:
int FindMin(BSTNode* root){
    if (!root)
    {
        cout<<"Error:Tree is empty"<<endl;
        return -1;
    }
    else if (root->left == NULL)//base condition for the recursion: We will continue searching till we reach a leaf or parent without left child since then it will be the minimum value in the tree.
    {
        return root->data;
    }
    //If the left subtree is not empty, we can reduce the searching, looking in the left subtree only.
    return FindMin(root->left);//passing root->left[root of the left subtree will be the child of the root] so that we search only in the left subtree
}

int FindMax(BSTNode* root){
    if (!root)
    {
        cout<<"Error: Tree is Empty"<<endl;
        return -1;
    }
    else if (root->right == NULL)
    {
        return root->data;//if we reach a state where there is no right child of the current root, then we can say that the current root holds the max value.
    }
    return FindMax(root->right);//if we didn't reach the parent without right child, we will continue going down right the tree.
}

//The logic is that for any node, if we can somehow calculate the height of the left and right subtree, then the height of that height of that node will be greater of 
// left or right subtree + 1.
int findHeight(BSTNode* root){
    if (root == NULL)
    {//if the tree is empty[height of an empty tree is -1] or we have reached a leaf node.[base or termination condition]
        return -1;
    }
    
    //for tracking
    int track = max(findHeight(root->left), findHeight(root->right));
    // cout<<"current height for "<<root->data<<" is: "<<track+1<<endl;
    return (track + 1);
}

//Traversal Functions
//Breadth-First Traversal of Binary Tree:
void LevelOrderTraversal(BSTNode* root){
//we are referring to a discovered node as: a node in a queue is a discovered node, we only know about it's address and we have yet to read it.
    if (!root)
    {//if the root is empty we simple return.
        return;
    }
    queue<BSTNode*> q;//a queue to store the address of the discovered node and it's child
    q.push(root);//initially the root will be the discovered node.

//The logic behind this is that while there is atleast one discovered node in the Queue, we are reading it,storing the address
//of it's children in the queue and dequeuing it and then continue doing so till we reach a leaf.
//by doing so we will get the desired effect of reading the node in one depth at once.[a fabulous use of property of Queue]
    cout<<"The tree in Level-Order Traversal is: "<<endl;
    while (!q.empty())//till the queue is not empty or till there is alteast one discovered node.
    {
        BSTNode* current = q.front();
        cout<<current->data<<" ";
        if (current->left)
        {
            q.push(current->left);
        }
        if (current->right)
        {
            q.push(current->right);
        }
        q.pop();//removing the element at the front.
    }
    cout<<endl;
}
//Depth-First Traversal of Binary Tree:
void preOrder(BSTNode* root){
    if (!root)
    {
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(BSTNode* root){
    if (!root)
    {
        return;
    }
    preOrder(root->left);
    cout<<root->data<<" ";
    preOrder(root->right);
}
void postOrder(BSTNode* root){
    if (!root)
    {
        return;
    }
    preOrder(root->left);
    preOrder(root->right);
    cout<<root->data<<" ";
}

bool bstUtil(BSTNode* root, int max, int min){
    if (root == NULL)
    {
        return true;
    }
    else if (root->data > min && root->data < max && bstUtil(root->left, min, root->data)
             && bstUtil(root->right, root->data, max))
    {
        return true;
    }
    else{
        return false;
    }
}

bool isBST(BSTNode* root){
    return bstUtil(root, INT64_MIN, INT64_MAX);
}

//Deleting a Node:
// BSTNode* Delete(BSTNode* root, int value){
//     //The link of the parent will be corrected when the recursion call is unfolding or the function call corresponding to the parent is resuming.
//     if (!root)
//     {
//         return root;
//     }
//     //in the following two else if(), the new links will be set
//     else if (root->data > value)
//     {
//         root->left = Delete(root->left, value);//the links will be set here.
//     }
//     else if (root->data < value)
//     {
//         root->right = Delete(root->right, value);//the links will be set here.
//     }
//     else{//In this the node will be deleting only and the link will be set when the function calls returns.
//         //case 1: Node has no child.
//         if (root->left == NULL && root->right == NULL)
//         {
//             delete[] root;
//             root = NULL;//even tough the address pointed by root is deleted, the root still has some address, so we will set it as NULL to return.
//         }
        
//         //case 2: Node has one child.
//         else if (root->left == NULL)
//         {
//             BSTNode* temp = root;
//             root = root->right;
//             delete[] temp;
//         }
//         else if (root->right == NULL)
//         {
//             BSTNode* temp = root;
//             root = root->left;
//             delete[] temp;
//         }
        
//         //case 3: Node has two children.
//         else{
//             BSTNode* temp = FindMin(root->right);
//             root->data = temp->data;
//             root->right = Delete(root->right, temp->data);
//         }
//     }
//     return root;
// }

// BSTNode* find(BSTNode* root, int data);
/*Finding In-Order Successor of a Node in a BST:[Logic: For a Node,1). if there is a right subtree, then the in-order successor would be the left-most Node in it's right subtree.
In a BST it will the minimum value Node in the right-subtree.
2). If these is no right-subtree, then to find it's successor we have to go to it's nearest ancestor for which the given node would be in it's left-subtree.]*/
// BSTNode* findSuccessor(BSTNode* root, int data){//Time complexity will be O(h).
//     //First we search the node in the tree and set the current as the address of that Node.
    
//     BSTNode* current = find(root, data);//Time complexity will be O(h).
//     if (current == NULL)
//     {
//         return NULL;// we didn't find the value.
//     }
//     if (current->right != NULL)//Case 1: Node has a right 
//     {
//        return findMin(current->right);//Time complexity will be O(h).
//     }

//     else{//case 2: Node doesn't have a right sub-tree.
//         BSTNode* successor = NULL;
//         BSTNode* ancestor = root;
//         while (ancestor != current)
//         {
//             if (current->data < ancestor->data)
//             {
//                 successor = ancestor;//if the data in current is less than ancestor than it will lie in the left subtree so it can be
//                 //the successor of the current.We keep going deep into the left subtree, and if find another node with the same property then 
//                 // we will update the successor.
//                 ancestor = ancestor->left;
//             }
//             else{//if the node is on the right, we will move to it's right.
//                 ancestor = ancestor->right;
//             }
//         }
//         //when we come out of the while loop, successor will either be NULL or have some address of the Node.
//         //not every node will have a successor, the node with maximum value will not have a successor.
//         return successor;
//     }    
// }

int main(){
    system("cls");
    BSTNode* root = NULL;//to store the address of the root node. Initially, the tree is empty since root = NULL.
    
//Insert Function Calls:
    root = insert(root, 7);
    root = insert(root, 3);
    root = insert(root, 5);
    root = insert(root, 9);
    root = insert(root, 10);
    root = insert(root, 8);
    root = insert(root, 6);

//Search Calls:
    if (search(root, 11))
    {
        cout<<"Number Found"<<endl;
    }
    else{
        cout<<"Number not found"<<endl;
    }

//Max and Min Function Calls:
    int min = FindMin(root);
    cout<<"The minimum value in the Tree is: "<<min<<endl;
    
    int max = FindMax(root);
    cout<<"The minimum value in the Tree is: "<<max<<endl;

//Height Function Calls:
    int height = findHeight(root);
    cout<<"The height of the Tree is: "<<height<<endl;


//Traversal function calls:
    LevelOrderTraversal(root);

    cout<<"The Pre-Order Sequence is: "<<endl;
    preOrder(root);
    
    cout<<endl;
    cout<<"The In-Order Sequence is: "<<endl;
    inOrder(root);

    cout<<endl;
    cout<<"The Post-Order Sequence is: "<<endl;
    postOrder(root);
    
//BST check Function calls:
    // if (isBST(root))
    // {
    //     cout<<"The Tree is BST"<<endl;
    //     return 0;
    // }
    // else{
    //     cout<<"The Tree is not a BST"<<endl;
    // }
    return 0;
}