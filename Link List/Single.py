class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None

class SingleList:
    def __init__(self):
        self.head = None


    
    def Append(self, data):
        New_Node = Node(data)
        if not self.head:
            self.head = New_Node
            return
        else:
            last = self.head
            while last.next:
                last = last.next
            last.next = New_Node
        


    def Display(self):
        current_node = self.head
        while current_node:
            print(current_node.data , " ")
            current_node = current_node.next



SL = SingleList()
SL.Append(10)
SL.Append(20)
SL.Append(60)
SL.Display()
