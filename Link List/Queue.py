class Node:
    def __init__(self, data):
        self.data = data
        self.next = None



class Queue:
    def __init__(self , Max_Size):
        self.Front = None
        self.Rear = None
        self.Max_Size = Max_Size
        self.current_Max_Size = 0

    
    def IsEmpty(self):
        if self.Rear is None:
            print("Queue Is Empty!")
            return
        else:
            return


    def IsFull(self):
        if self.Max_Size == self.current_Max_Size:
            print("Queue is Full!")
            return
        


    def Enqueue(self, data):
        New_Node = Node(data)
        if self.Rear is None:
            self.Rear = self.Front = New_Node
            return
        else:
             self.Rear.next = New_Node
             self.Rear = New_Node
             ("Data Added!")
             return
        

    def Dequeue(self):
        if self.Front is None:
            print("Queue is Empty!")
            return
        else:
            print(self.Front.data , "Dequeued!")
            self.Front = self.Front.next
            return
        

    def Peek(self):
        if self.Front is None:
            print("Queue is Empty!")
            return
        else:
            print(self.Front.data)
            return
    

    def Display(self):
        if self.Rear is None:
            print("Queue Is Empty!")
            return
        else:
            List = []
            current = self.Front
            while current:
                List.append(current.data)
                current = current.next
            print(List)
            print("Front -> Rear")
            return
        

Qu = Queue(5)
Qu.IsEmpty()
Qu.Enqueue(15)
Qu.Enqueue(35)
Qu.Display()
Qu.Dequeue()
Qu.Display()
Qu.Enqueue(20)
Qu.Peek()
Qu.Display()
Qu.IsFull()