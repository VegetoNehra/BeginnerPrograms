#include <iostream>
using namespace std;
//Basic programs using class  to form a linked list
//Program to calculate number of nodes.


class Node {
public:
    int data;
    Node* next; // Pointer to the next node
    Node(int adata) : data(adata), next(nullptr) {} 

    
};
int countnodes(Node* Head){
        int count=0;
        Node* current= Head;
        while (current!=nullptr) {
            current=current->next; //always use this [->] instead of [.] when ujsing poinmters
            count++;
            }
        return count;
        };


int main() {
    Node Head (5);
    Node node2(4);
    Node node3(3);
    Node node4(2);
    Node node5(1);

    Head.next = &node2; 
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;

    cout<< countnodes(&Head);
    return 0;
}
