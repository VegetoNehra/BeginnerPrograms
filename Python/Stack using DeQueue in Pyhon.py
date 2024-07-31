from collections import deque

class DequeStack:
    def __init__(self):
        self.stack = deque()

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
ds = DequeStack()
ds.push(1)
ds.push(2)
ds.push(3)
print(ds)        # Output: deque([1, 2, 3])
print(ds.pop())  # Output: 3
print(ds.peek()) # Output: 2
print(ds.size()) # Output: 2
print(ds.is_empty())  # Output: False
