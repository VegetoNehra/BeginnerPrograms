#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
    Node*prev;
    Node(int value):data(value),next(nullptr),prev(nullptr){}
};

class DoublyLinkedList{
    private:
    Node* head;
    Node* tail;
    public:
    DoublyLinkedList():head(nullptr),tail(nullptr){}

    void insertAtHead(int value) {
        Node* newnode = new Node(value);
        if (head == nullptr) {
            head = tail = newnode;
            return;
        }
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
    void addvalue(int value){
        Node*newnode=new Node(value);
        if(head==nullptr){
            head=tail=newnode;
        }
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void reversedisplay(){
        Node* temp=tail;
        while (temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->prev;
        }  
    }  
};

int main() {
    DoublyLinkedList list;
    list.insertAtHead(10);
    list.display();
    list.insertAtHead(20);
    list.display();
    list.insertAtHead(30);

    list.display(); // Output should be: 30 20 10

    list.addvalue(40);
    list.display();

    list.insertAtHead(50);
    list.display();

    list.addvalue(60);
    list.display();

    list.reversedisplay();



    return 0;
}
    
