class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None

class CList:
    def __init__(self):
        self.head = None


    
    def Append(self, data):
        New_Node = Node(data)
        if not self.head:
            self.head = New_Node
            self.head.next = self.head
            return
        else:
            Temp =self.head
            while Temp != self.head:
                Temp = Temp.next
            Temp = New_Node
        


    def Display(self):
        current_node = self.head
        if self.head:
            while True:
                print(current_node.data)
                current_node = current_node.next
                if current_node == self.head:
                    break


CL = CList()
CL.Append(10)
CL.Append(20)
CL.Append(60)
CL.Display()
