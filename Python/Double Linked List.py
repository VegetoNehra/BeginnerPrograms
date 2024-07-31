class Node:
    def __init__(self, value):
        self.data = value
        self.next = None
        self.prev = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert_at_head(self, value):
        new_node = Node(value)
        if self.head is None:
            self.head = self.tail = new_node
            return
        self.head.prev = new_node
        new_node.next = self.head
        self.head = new_node

    def add_value(self, value):
        new_node = Node(value)
        if self.head is None:
            self.head = self.tail = new_node
            return
        self.tail.next = new_node
        new_node.prev = self.tail
        self.tail = new_node

    def display(self):
        temp = self.head
        while temp is not None:
            print(temp.data, end=' ')
            temp = temp.next
        print()

    def reverse_display(self):
        temp = self.tail
        while temp is not None:
            print(temp.data, end=' ')
            temp = temp.prev
        print()

if __name__ == "__main__":
    dll = DoublyLinkedList()
    dll.insert_at_head(10)
    dll.display()  # Output should be: 10 
    dll.insert_at_head(20)
    dll.display()  # Output should be: 20 10 
    dll.insert_at_head(30)
    dll.display()  # Output should be: 30 20 10 

    dll.add_value(40)
    dll.display()  # Output should be: 30 20 10 40 

    dll.insert_at_head(50)
    dll.display()  # Output should be: 50 30 20 10 40 

    dll.add_value(60)
    dll.display()  # Output should be: 50 30 20 10 40 60 

    dll.reverse_display()  # Output should be: 60 40 10 20 30 50 
