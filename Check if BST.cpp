#include <iostream>
#include <queue>
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

    bool isSubTreeLesser(Node* root ,int value){
        if(root==nullptr){
            return true;
        }
        if(root->data <= value && isSubTreeLesser(root->left,value) && isSubTreeLesser(root->right,value) ){
            return true;
        }
        else{
            return false;
        }
    }

    bool isSubTreeGreater(Node* root ,int value){
        if(root==nullptr){
            return true;
        }
        if(root->data >= value && isSubTreeGreater(root->left,value) && isSubTreeGreater(root->right,value) ){
            return true;
        }
        else{
            return false;
        }
    }

    bool isBSTstill(Node*  root){
        if (root==nullptr){
            return true;
        }
        else if(isSubTreeLesser(root->left,root->data) && isSubTreeGreater(root->right,root->data) && isBSTstill(root->left) && isBSTstill(root->right)){
            return true;
        }
        else{
            return false;
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}
    
    void insertNode(int value) {
        root = insertNode(root, value);
    }

    bool isBST(){
        return isBSTstill(root);
    }

    void setRoot(int value) {
        root = new Node(value);
    }

    // Getter for the root of the BST
    Node* getRoot() const {
        return root;
    }

    
};

int main() {
    BinarySearchTree bst;
    bst.insertNode(15);
    bst.insertNode(10);
    bst.insertNode(20);
    bst.insertNode(8);
    bst.insertNode(12);
    bst.insertNode(17);
    bst.insertNode(25);

    if(bst.isBST()){
        cout<<"It is a BINARY SEARCH TREE!!"<<endl;
    }
    else{
        cout<<"It is not a BST!!"<<endl;
    }


     // Directly setting nodes for bst2
    BinarySearchTree bst2;
    bst2.setRoot(20);
    bst2.getRoot()->left = new Node(15);
    bst2.getRoot()->right = new Node(25);

    // Adding four more nodes to bst2
    bst2.getRoot()->left->left = new Node(10);
    bst2.getRoot()->left->right = new Node(18);
    bst2.getRoot()->right->left = new Node(22);
    bst2.getRoot()->right->right = new Node(30);

    if (bst2.isBST()) {
        cout << "It is a BINARY SEARCH TREE!!" << endl;
    } else {
        cout << "It is not a BST!!" << endl;
    }

    
    return 0;
}
