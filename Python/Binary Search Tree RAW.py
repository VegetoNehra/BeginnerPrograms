from collections import deque #or use import queue ; which used put() , get(), functions 
class Node:
    def __init__(self,value):
        self.data=value
        self.right=None
        self.left=None

class BinarySearchTree:
    def __init__(self):
        self.root= None

    def insertNode(self,node,value):
        if node==None:
            return Node(value)
        if value>node.data:
            node.right=self.insertNode(node.right,value)
        else :
            node.left=self.insertNode(node.left,value)
        return node
    def insert(self,value):
        self.root=self.insertNode(self.root,value)


    def _inordertraversal(self,node):
        if node is not None:
            self._inordertraversal(node.left)
            print(node.data,end=" ")
            self._inordertraversal(node.right)
    def inOrderTraversal(self):
        print("In-Order Traversal of BST is :",end=' ')
        self._inordertraversal(self.root)
        print()
    

    def _preordertraversal(self,node):
        if node is not None:
            print(node.data, end=" ")
            self._preordertraversal(node.left)
            self._preordertraversal(node.right)
    def preOrderTraversal(self):
        print("Pre-Order Traversal of BST is :",end=' ')
        self._preordertraversal(self.root)
        print()
    

    def _postordertraversal(self,node):
        if node is not None:
            self._postordertraversal(node.left)
            self._postordertraversal(node.right)
            print(node.data,end=" ")
    def postOrderTraversal(self):
        print("Post-Order Traversal of BST is :",end=' ')
        self._postordertraversal(self.root)
        print()

    
    def _levelordertraversal(self,node):
        if node is None:
            return
        queue=deque([node])
        
        while queue :
            current=queue.popleft()
            print(current.data,end=" ")

            if current.left is not None:
                queue.append(current.left)
            if current.right is not None:
                queue.append(current.right)
    def levelOrderTraversal(self):
        print("Level-Order Traversal of BST is : ",end=' ')
        self._levelordertraversal(self.root)
        print()
    

    def findmin(self,root):
        if root is None:
            print("ERROR : The BST is empty")
            return None
        current=root
        while current and current.left is not None:
            current=current.left
        return current
    
#main functions call

bst=BinarySearchTree()

bst.insert(20)
bst.insert(25)
bst.insert(15)
bst.insert(10)
bst.insert(17)
bst.insert(23)
bst.insert(27)

bst.inOrderTraversal()

bst.preOrderTraversal()

bst.postOrderTraversal()

bst.levelOrderTraversal()

min=bst.findmin(bst.root)
print("Minimum value of BST is :", min.data)