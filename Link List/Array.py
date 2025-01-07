class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None


class Array:
    def __init__(self):
        self.head = None


    def Append(self, data):
        New_Node = Node(data)
        if self.head is None:
            self.head = New_Node
            return
        else:
            Last = self.head
            while Last.next:
                Last = Last.next
            Last.next = New_Node


    def Display(self):
        List = []
        current = self.head
        while current:
            List.append(current.data)
            current = current.next
        print(List)



Arr = Array()
Arr.Append(5)
Arr.Append(10)
Arr.Append(20)
Arr.Display()