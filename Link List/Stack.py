class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Stack:
    def __init__(self):
        self.top = None

    
    def Is_Empty(self):
        if self.top is None:
            print("Stack is Empty!")
            return
        else:
            print("Stack isn't Empty!")


    def Push(self, data):
        New_Node = Node(data)
        New_Node.next = self.top
        self.top = New_Node
        print("Added!")


    def Pop(self):
        if self.top is None:
            print("Stack is Empty!")
            return
        else:
            Popped = self.top.data
            self.top = self.top.next
            print("Popped num is: " , Popped)
            return
        
    
    def Peek(self):
        if self.top is None:
            print("Stack is Empty!")
        else:
            print("The top Number is: " , self.top.data)
            return
            
            
            
    def Display(self):
        if self.top is None:
            print("Stack is Empty!")
        else:
            current = self.top
            List = []
            while current:
                List.append(current.data)
                current = current.next
            print(List)
            return
        
        
st = Stack()
st.Is_Empty()
st.Push(12)
st.Push(24)
st.Push(16)
st.Display()
st.Pop()
st.Display()
st.Peek()
st.Is_Empty()
