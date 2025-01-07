class Node:
    def __init__(self, data=None):
        self.data = data
        self.prev = None
        self.next = None

class DoubleList:
    def __init__(self):
        self.head = None
        self.end = None
        self.size = 0



    def InsertAtBegin(self, data):
        New_Node = Node(data)
        if self.head is None:
            self.head = self.end = New_Node
        else:
            New_Node.next = self.head
            self.head.prev = New_Node
            self.head = New_Node
        if self.size is None:
            self.size = 1
        else:
            self.size += 1
    

    def InsertAtEnd(self, data):
        New_Node = Node(data)
        if self.end is None:
            self.end = self.head = New_Node
        else:
            self.end.next = New_Node
            New_Node.prev = self.end
            self.end = New_Node
        if self.size is None:
            self.size = 1
        else:
            self.size += 1


    def InsertAtIndex(self, data, Index):
        if Index < 0 or Index > self.size:
            print("Invalid Index")
        New_Node = Node(data)
        if Index == 0:
            self.InsertAtBegin(data)
        elif Index == self.size:
            self.InsertAtEnd(data)
        else:
            current = self.head
            for Ind in range(Index):
                current = current.next
            New_Node.next = current
            New_Node.prev = current.prev
            current.prev.next = New_Node
            current.prev = New_Node
            if self.size is None:
                self.size = 1
            else:
                self.size += 1
            
        

    
    def UpdateNode(self, data, Index):
        if self.size is None or Index < 0 or Index > self.size:
            print("Invalid Index")
            return
        current = self.head
        for Ind in range(Index):
            current = current.next
        current.data = data
        print("Node in Index" , Index ,  "Updated:")



    def RemoveNodeAtBegin(self):
        if self.head is None:
            return None
        data = self.head.data
        if self.head.next is None:
            self.head = self.end = None
        else:
            self.head = self.head.next
            self.head.prev = None
        self.size -= 1


    def RemoveNodeAtEnd(self):
        if self.end is None:
            return None
        data = self.end.data
        if self.end.prev is None:
            self.head = self.end = None
        else:
            self.end = self.end.prev
            self.end.next = None
        self.size -= 1
        return data


    def RemoveNodeAtIndex(self, Index):
        if Index < 0 or Index >= self.size or self.size is None:
            print("Invalid Index!")
            return
        if Index == 0:
            self.RemoveNodeAtBegin()
            return
        elif Index == self.size-1:
            self.RemoveNodeAtEnd()
        else:
            current = self.head
            for Ind in range(Index):
                current = current.next
            current.prev.next = current.next
            current.next.prev = current.prev
            self.size -= 1
            return current.data
    

    def SizeOfList(self):
        print(self.size)
        return
    

    def Concatenate(self, LinkedList):
        if self.head is None:
            self.head = LinkedList.head
            self.end = LinkedList.end
        elif LinkedList.head is not None:
            self.end.next = LinkedList.head
            self.end = LinkedList.end
        if self.size is None:
            self.size = LinkedList.size
        else:
            self.size += LinkedList.size


    def Invert(self):
        if self.head is None:
            return
        else:        
            current = self.head
            self.end = current
            while current is not None:
                Temp = current.prev
                current.prev = current.next
                current.next = Temp
                if current.prev is None:
                    self.head = current
                current = current.prev
            
            

    def Display(self):
        List = []
        current = self.head
        while current is not None:
            List.append(current.data)
            current = current.next
        print(List)



DL1 = DoubleList()
DL1.InsertAtBegin(7)
DL1.InsertAtIndex(12,1)
DL1.InsertAtEnd(20)
print("List1 is: ")
DL1.Display()
print("Inverted List is: ")
DL1.Invert()
DL1.Display()

print("List2 is: ")
DL2 = DoubleList()
DL2.InsertAtBegin(90)
DL2.InsertAtIndex(25 , 1)
DL2.Display()

print("Concatenated List is: ")
DL1.Concatenate(DL2)
DL1.RemoveNodeAtBegin()
DL1.RemoveNodeAtEnd()
DL1.RemoveNodeAtIndex(1)
DL1.Display()
DL1.UpdateNode(50 , 1)
DL1.Display()
