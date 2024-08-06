class Node:
    def __init__(self, value):
        self.data = value
        self.left = None
        self.right = None

class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert_node(self, value):
        if self.root is None:
            self.root = Node(value)
        else:
            self._insert_node(self.root, value)

    def _insert_node(self, node, value):
        if value < node.data:
            if node.left is None:
                node.left = Node(value)
            else:
                self._insert_node(node.left, value)
        else:
            if node.right is None:
                node.right = Node(value)
            else:
                self._insert_node(node.right, value)

    def in_order_traversal(self):
        self._in_order_traversal(self.root)
        print()

    def _in_order_traversal(self, node):
        if node:
            self._in_order_traversal(node.left)
            print(node.data, end=' ')
            self._in_order_traversal(node.right)

    def pre_order_traversal(self):
        self._pre_order_traversal(self.root)
        print()

    def _pre_order_traversal(self, node):
        if node:
            print(node.data, end=' ')
            self._pre_order_traversal(node.left)
            self._pre_order_traversal(node.right)

    def post_order_traversal(self):
        self._post_order_traversal(self.root)
        print()

    def _post_order_traversal(self, node):
        if node:
            self._post_order_traversal(node.left)
            self._post_order_traversal(node.right)
            print(node.data, end=' ')

    def level_order_traversal(self):
        if not self.root:
            return
        queue = [self.root]
        while queue:
            current = queue.pop(0)
            print(current.data, end=' ')
            if current.left:
                queue.append(current.left)
            if current.right:
                queue.append(current.right)
        print()

    def search(self, value):
        node = self._search_tree(self.root, value)
        if node:
            print(f"Value: {node.data} is in the Search Tree")
        else:
            print("Value is not in Tree")

    def _search_tree(self, node, value):
        if not node or node.data == value:
            return node
        if value < node.data:
            return self._search_tree(node.left, value)
        return self._search_tree(node.right, value)

    def find_min(self):
        min_node = self._find_min(self.root)
        if min_node:
            print(f"Smallest node value is {min_node.data}")
        else:
            print("Error: Tree is Empty")

    def _find_min(self, node):
        current = node
        while current and current.left:
            current = current.left
        return current

    def find_min_recursive(self):
        if self.root:
            min_node = self._find_min_recursive(self.root)
            print(f"Smallest node using recursion is {min_node.data}")
        else:
            print("Error: Tree is empty")

    def _find_min_recursive(self, node):
        if not node.left:
            return node
        return self._find_min_recursive(node.left)

    def find_max(self):
        max_node = self._find_max(self.root)
        if max_node:
            print(f"Largest node value is {max_node.data}")
        else:
            print("Error: Tree is Empty")

    def _find_max(self, node):
        if not node.right:
            return node
        return self._find_max(node.right)

    def find_height(self):
        height = self._find_height(self.root)
        print(f"Height of Tree is: {height}")

    def _find_height(self, node):
        if not node:
            return -1
        return max(self._find_height(node.left), self._find_height(node.right)) + 1

    def delete_node(self, value):
        self.root = self._delete_node(self.root, value)

    def _delete_node(self, node, value):
        if not node:
            return node
        if value < node.data:
            node.left = self._delete_node(node.left, value)
        elif value > node.data:
            node.right = self._delete_node(node.right, value)
        else:
            if not node.left and not node.right:
                node = None
            elif not node.left:
                node = node.right
            elif not node.right:
                node = node.left
            else:
                temp = self._find_min(node.right)
                node.data = temp.data
                node.right = self._delete_node(node.right, temp.data)
        return node

    def get_successor(self, data):
        current = self._search_tree(self.root, data)
        if current:
            if current.right:
                return self._find_min(current.right)
            else:
                successor = None
                ancestor = self.root
                while ancestor != current:
                    if current.data < ancestor.data:
                        successor = ancestor
                        ancestor = ancestor.left
                    else:
                        ancestor = ancestor.right
                return successor
        return None

    def successor(self, data):
        successor_node = self.get_successor(data)
        if successor_node:
            print(f"In-Order Successor to {data} is {successor_node.data}")
        else:
            print(f"No Successor to {data}")

if __name__ == "__main__":
    bst = BinarySearchTree()
    bst.insert_node(20)
    bst.insert_node(15)
    bst.insert_node(25)
    bst.insert_node(10)
    bst.insert_node(17)
    bst.insert_node(23)
    bst.insert_node(27)

    bst.find_min()
    bst.find_min_recursive()
    bst.find_max()
    bst.find_height()

    print("In-order traversal of the BST: ", end='')
    bst.in_order_traversal()

    bst.successor(20)
    bst.successor(8)

    print("Pre-order traversal of the BST: ", end='')
    bst.pre_order_traversal()

    print("Post-order traversal of the BST: ", end='')
    bst.post_order_traversal()

    print("Level-order traversal of the BST: ", end='')
    bst.level_order_traversal()

    bst.delete_node(20)

    print("Level-order traversal of the BST after deletion: ", end='')
    bst.level_order_traversal()

    data = int(input("Enter number to be searched: "))
    bst.search(data)
