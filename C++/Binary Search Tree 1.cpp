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
    
    void inOrderTraversal(Node* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }

    void preOrderTraversal(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preOrderTraversal(node->left);
            preOrderTraversal(node->right);
        }
    }

    void postOrderTraversal(Node* node) {
        if (node != nullptr) {
            postOrderTraversal(node->left);
            postOrderTraversal(node->right);
            cout << node->data << " ";
        }
    }

    void levelOrderTraversal(Node* root) {
        if (root == nullptr) {
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            cout << current->data << " ";

            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
    }

    Node* searchTree(Node* root, int value) {
        if (root == nullptr) {
            return nullptr;
        } else if (root->data == value) {
            return root;
        } else if (value < root->data) {
            return searchTree(root->left, value);
        } else {
            return searchTree(root->right, value);
        }
    }

    Node* findMin(Node* root) {
        Node* current = root;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    Node* findMinRecursive(Node* root) {
        if (root->left == nullptr) {
            return root;
        }
        return findMinRecursive(root->left);
    }

    Node* findMax(Node* root) {
        if (root->right == nullptr) {
            return root;
        }
        return findMax(root->right);
    }

    int findHeight(Node* root) {
        if (root == nullptr) {
            return -1;
        }
        return max(findHeight(root->left), findHeight(root->right)) + 1;
    }


    Node* deleteNode(Node* root , int data){
        if(root==nullptr){
            return root;
        }
        else if(root->data < data){
            root->right=deleteNode(root->right ,data);
        }
        else if(root->data>data){
            root->left=deleteNode(root->left ,data);
        }else {
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                root = nullptr;
            } else if (root->left == nullptr) {
                Node* temp = root;
                root = root->right;
                delete temp;
            } else if (root->right == nullptr) {
                Node* temp = root;
                root = root->left;
                delete temp;
            } else {
                Node* temp = findMin(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }
        return root;
    }

    Node* getSuccessor(Node* root, int data){ // getting an in-order successor
        Node* current=searchTree(root ,data);
        if(current==nullptr){
            return nullptr;
        }
        else if(current->right!=nullptr){ //Case:1 Right subtree present
            return findMin(current->right);
        }
        else{
            Node* successor =nullptr;
            Node* ancestor= root;
            while(ancestor!=current){
                if(current->data < ancestor->data){
                    successor=ancestor;
                    ancestor=ancestor->left;
                }
                else{
                    ancestor=ancestor->right;
                }
            }
            return successor;
        }
    }
    
public:
    BinarySearchTree() : root(nullptr) {}
    
    void insertNode(int value) {
        root = insertNode(root, value);
    }
    
    void inOrderTraversal() {
        inOrderTraversal(root);
    }

    void preOrderTraversal() {
        preOrderTraversal(root);
    }

    void postOrderTraversal() {
        postOrderTraversal(root);
    }

    void levelOrderTraversal() {
        levelOrderTraversal(root);
    }

    void search(int value) {
        Node* ptr=searchTree(root, value);
        if(ptr==nullptr){
            cout<<"Value is not in Tree"<<endl;
        }
        else{
            cout<<"Value : "<<ptr->data<<" is in Search Tree"<<endl;
        }
    }

    void findMin() {
        if (root == nullptr) {
            cout << "Error: Tree is Empty" << endl;
        } else {
            Node* minNode = findMin(root);
            cout << "Smallest node value is " << minNode->data << endl;
        }
    }

    void findMinRecursive() {
        if (root == nullptr) {
            cerr << "Error: Tree is empty" << endl;
        } else {
            Node* minNode = findMinRecursive(root);
            cerr << "Smallest node using recursion is " << minNode->data << endl;
        }
    }
    
    void findMax() {
        if (root == nullptr) {
            cout << "Error: Tree is Empty" << endl;
        } else {
            Node* maxNode = findMax(root);
            cout << "Largest node value is " << maxNode->data << endl;
        }
    }

    void findHeight() {
        if (root == nullptr) {
            cerr << "Height of Tree is : -1" << endl;
        } else {
            int height = findHeight(root);
            cerr << "Height of Tree is : " << height << endl;
        }
    }

    void deleteNode(int value) {
        root = deleteNode(root, value);
    }

    void successor(int data){
        Node* temp=getSuccessor(root,data);
        if(temp==nullptr){
            cout<<"No Successor to "<<data<<endl;
        }else{
            cout<<"In-Order Successor to "<<data <<" is "<< temp->data<<endl;
            }
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

    bst.findMin();
    bst.findMinRecursive();
    bst.findMax();
    bst.findHeight();

    cout << "In-order traversal of the BST: ";
    bst.inOrderTraversal();
    cout << endl;

    bst.successor(20);
    bst.successor(8);

    cout << "Pre-order traversal of the BST: ";
    bst.preOrderTraversal();
    cout << endl;

    cout << "Post-order traversal of the BST: ";
    bst.postOrderTraversal();
    cout << endl;

    cout << "Level-order traversal of the BST: ";
    bst.levelOrderTraversal();
    cout << endl;

    bst.deleteNode(20);

    cout << "Level-order traversal of the BST: ";
    bst.levelOrderTraversal();
    cout << endl;

    int data;
    cout << "Enter number to be searched: ";
    cin >> data;
    bst.search(data);
    
    return 0;
}
