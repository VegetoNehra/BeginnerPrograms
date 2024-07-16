#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;
    
    Node* insertNode(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        
        if (value < node->data) {
            node->left = insertNode(node->left, value);
        } else {
            node->right = insertNode(node->right, value);
        }
        return node;
    }
    
    void inOrderTraversal(Node* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }

    Node* searchtree(Node* root, int value) {
        if (root == nullptr) {
            cout << "Value " << value << " doesn't exist in Tree" << endl;
            return nullptr;
        } else if (root->data == value) {
            cout << "Value " << value << " entered is Tree's Root" << endl;
            return root;
        } else if (value < root->data) {
            return searchtree(root->left, value);
        } else {
            return searchtree(root->right, value);
        }
    }
    Node* findmin(Node*root){ // using loops and itiration
        Node* current=root;
        while(current && current->left != nullptr){
            current=current->left;
        }
        return current;
    }

    Node* findmin2(Node*root){
        if(root->left==nullptr){
            return root;
        }
        return findmin2(root->left);

    }

    Node*findmax(Node*root){
        if (root->right==nullptr){
            return root;
        }
        return findmax(root->right);
    }

    int findheight(Node* root){
        if (root==nullptr){
            return -1;
        }
        return max(findheight(root->right),findheight(root->left)) +1;//+1 for the edge of root to next parent node
    }
        
    
    
public:
    BinarySearchTree() : root(nullptr) {}
    
    void insertNode(int value) {
        root = insertNode(root, value);
    }
    
    void inOrderTraversal() {
        inOrderTraversal(root);
    }

    void searchtree(int value) {
        searchtree(root, value);
    }

    void findmin(){
        if(root==nullptr){
            cout<<"Error: Tree is Empty"<<endl;
            }
        else{
            Node* MinNum= findmin(root);
            cout<<"Smallest node value is "<< MinNum->data <<endl;            
        }
    }

    void findmin2(){
        if(root==nullptr){
            cerr<<"Error Tree is empty"<<endl;
        }
        else{
            Node*minnum=findmin2(root);
            cerr<<"Smallest node using recursion is "<<minnum->data<<endl;
        }
    }
    
    void findmax(){
        if(root==nullptr){
            cout<<"Error: Tree is Empty"<<endl;
        }
        else{
            Node* Maxnum=findmax(root);
            cout<<"Largest node using recursion is "<<Maxnum->data<<endl;
        }
        
    }

    void findheight(){
        if(root==nullptr){
            cerr<<"Height of Tree is : -1"<<endl;
        }
        int height=findheight(root);
        cerr<<"Height of Tree is : "<<height<<endl;
    }
    
};

int main() {
    BinarySearchTree B;
    B.insertNode(15);
    B.insertNode(10);
    B.insertNode(20);
    B.insertNode(8);
    B.insertNode(12);
    B.insertNode(17);
    B.insertNode(25);
    B.insertNode(90);
    B.insertNode(6);
    B.insertNode(57);

    B.findmin();
    B.findmin2();

    B.findmax();

    B.findheight();

    cout << "In-order traversal of the BST: ";
    B.inOrderTraversal();
    cout << endl;
    int data;

    cout<<"Enter number to be searched"<<endl;
    cin>>data;

    B.searchtree(data);
    

    return 0;
}
