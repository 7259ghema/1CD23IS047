                         𝓢𝓣𝓐𝓒𝓚𝓢 𝓤𝓢𝓘𝓝𝓖 𝓛𝓘𝓝𝓚𝓔𝓓 𝓛𝓘𝓢𝓣
                                 𝑷𝑹𝑶𝑮𝑹𝑨𝑴:-
 
class Node:
    def __init__(self, value):
        self.value = value  # The value of the node
        self.next = None    # Pointer to the next node

class Stack:
    def __init__(self, capacity):
        self.top = None      # The stack is initially empty
        self.capacity = capacity  # Maximum size of the stack
        self.size = 0        # Keeps track of the current size of the stack

    def push(self, value):
        # Check for overflow
        if self.size >= self.capacity:
            raise OverflowError("Stack Overflow: Cannot push, stack is full.")
        
        # Create a new node and push it onto the stack
        new_node = Node(value)
        new_node.next = self.top  # Point the new node to the current top
        self.top = new_node       # Update top to the new node
        self.size += 1            # Increase stack size

    def pop(self):
        # Check for underflow
        if self.is_empty():
            raise IndexError("Stack Underflow: Cannot pop, stack is empty.")
        
        # Pop the top element
        popped_value = self.top.value
        self.top = self.top.next  # Move top to the next node
        self.size -= 1            # Decrease stack size
        return popped_value

    def peek(self):
        # Check for underflow
        if self.is_empty():
            raise IndexError("Stack Underflow: Cannot peek, stack is empty.")
        
        return self.top.value

    def is_empty(self):
        # Return True if the stack is empty
        return self.top is None

    def get_size(self):
        # Return the current size of the stack
        return self.size

    def __str__(self):
        # Helper method to print the stack
        current = self.top
        values = []
        while current:
            values.append(str(current.value))
            current = current.next
        return " -> ".join(values) if values else "Stack is empty"

# Example usage
if __name__ == "__main__":
    # Create a stack with capacity of 3
    stack = Stack(3)

    # Push elements onto the stack
    stack.push(10)
    stack.push(20)
    stack.push(30)

    print("Stack after pushes:")
    print(stack)  

    # Trying to push beyond capacity (overflow)
    try:
        stack.push(40)  
    except OverflowError as e:
        print(e)  

    # Pop an element from the stack
    print("Popped element:", stack.pop())  
    print("Stack after pop:")
    print(stack)  

    # Peek at the top element
    print("Top element:", stack.peek())  

    # Trying to pop from an empty stack (underflow)
    stack.pop()  
    stack.pop()  

    try:
        stack.pop()  
    except IndexError as e:
        print(e)  

    print("Is stack empty?", stack.is_empty()) 
       


𝙊𝙐𝙏𝙋𝙐𝙏 𝙊𝙁 𝙏𝙃𝙀 𝙋𝙍𝙊𝙂𝙍𝘼𝙈:-

Stack after pushes:
30 -> 20 -> 10
Stack Overflow: Cannot push, stack is full.
Popped element: 30
Stack after pop:
20 -> 10
Top element: 20
Stack Underflow: Cannot pop, stack is empty.
Is stack empty? True


                         𝓠𝓤𝓔𝓤𝓔𝓢 𝓤𝓢𝓘𝓝𝓖 𝓛𝓘𝓝𝓚𝓔𝓓 𝓛𝓘𝓢𝓣
                                 𝙋𝙍𝙊𝙂𝙍𝘼𝙈:-

class Node:
    def __init__(self, value):
        self.value = value  # The value of the node
        self.next = None    # Pointer to the next node

class Queue:
    def __init__(self, capacity):
        self.front = None     # The front pointer of the queue
        self.rear = None      # The rear pointer of the queue
        self.capacity = capacity  # Maximum size of the queue
        self.size = 0         # Number of elements in the queue

    def enqueue(self, value):
        # Check for overflow
        if self.size >= self.capacity:
            raise OverflowError("Queue Overflow: Cannot enqueue, queue is full.")
        
        # Create a new node
        new_node = Node(value)
        
        # If the queue is empty, both front and rear point to the new node
        if self.is_empty():
            self.front = self.rear = new_node
        else:
            # Add the new node to the rear of the queue
            self.rear.next = new_node
            # Update the rear pointer to the new node
            self.rear = new_node
        
        # Increase the size of the queue
        self.size += 1

    def dequeue(self):
        # Check for underflow
        if self.is_empty():
            raise IndexError("Queue Underflow: Cannot dequeue, queue is empty.")
        
        # Remove the front node and move the front pointer to the next node
        dequeued_value = self.front.value
        self.front = self.front.next
        
        # If the queue becomes empty after dequeue, reset rear to None
        if self.front is None:
            self.rear = None
        
        # Decrease the size of the queue
        self.size -= 1
        return dequeued_value

    def peek(self):
        # Check for underflow
        if self.is_empty():
            raise IndexError("Queue Underflow: Cannot peek, queue is empty.")
        return self.front.value

    def is_empty(self):
        # Return True if the queue is empty
        return self.front is None

    def get_size(self):
        # Return the current size of the queue
        return self.size

    def __str__(self):
        # Helper method to print the queue
        current = self.front
        values = []
        while current:
            values.append(str(current.value))
            current = current.next
        return " -> ".join(values) if values else "Queue is empty"

# Example usage
if __name__ == "__main__":
    # Create a queue with a capacity of 3
    queue = Queue(3)

    # Enqueue elements onto the queue
    queue.enqueue(10)
    queue.enqueue(20)
    queue.enqueue(30)

    print("Queue after enqueues:")
    print(queue)  

    # Trying to enqueue beyond capacity (overflow)
    try:
        queue.enqueue(40)  # This will raise OverflowError
    except OverflowError as e:
        print(e)  

    # Dequeue an element from the queue
    print("Dequeued element:", queue.dequeue())  
    print("Queue after dequeue:")
    print(queue)  

    # Peek at the front element
    print("Front element:", queue.peek())  

    # Trying to dequeue from an empty queue (underflow)
    queue.dequeue()  
    queue.dequeue() 

    try:
        queue.dequeue()  
    except IndexError as e:
        print(e)  

    print("Is queue empty?", queue.is_empty()) 
    


𝙊𝙐𝙏𝙋𝙐𝙏 𝙊𝙁 𝙏𝙃𝙀 𝙋𝙍𝙊𝙂𝙍𝘼𝙈:-

Queue after enqueues:
10 -> 20 -> 30
Queue Overflow: Cannot enqueue, queue is full.
Dequeued element: 10
Queue after dequeue:
20 -> 30
Front element: 20
Queue Underflow: Cannot dequeue, queue is empty.
Is queue empty? True

 
