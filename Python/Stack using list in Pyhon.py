class Stack:
    def __init__(self):
        self.stack = []

    def is_empty(self):
        return len(self.stack) == 0

    def push(self, item):
        self.stack.append(item)

    def pop(self):
        if not self.is_empty():
            return self.stack.pop()
        else:
            raise IndexError("pop from empty stack")

    def peek(self):
        if not self.is_empty():
            return self.stack[-1]
        else:
            raise IndexError("peek from empty stack")

    def size(self):
        return len(self.stack)

    def __str__(self):
        return str(self.stack)

s = Stack()
s.push(1)
s.push(2)
s.push(3)
print(s)         # Output: [1, 2, 3]
print(s.pop())   # Output: 3
print(s.peek())  # Output: 2
print(s.size())  # Output: 2
print(s.is_empty())  # Output: False
