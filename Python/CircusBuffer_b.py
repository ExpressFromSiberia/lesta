class List:

    def __init__(self, data):
        self.data = data
        self.next = None


class CircusBuffer:

    def __init__(self, size):
        self.size = size
        self.numElements = 0
        self.head = List(0)
        self.tail = self.head
        self.head.next = self.tail
        for i in range(1, size):
            tmp = List(0)
            self.tail.next = tmp
            tmp.next = self.head
            self.tail = tmp
        self.getNode = self.head
        self.addNode = self.head


    def GetOccupiedSpace(self):
        return self.numElements

    def Add(self, val):
        if self.numElements >= self.size:
            print("Buffer is full! Data was overwrited.")
            self.getNode = self.addNode.next
            self.numElements -= 1
        self.addNode.data = val
        self.addNode = self.addNode.next
        self.numElements += 1

    def Get(self):
        if self.numElements == 0:
            print("Buffer is empty")
            return
        res = self.getNode.data
        self.getNode = self.getNode.nextц
        self.numElements -= 1
        return res

size = 5
count = 7
buffer = CircusBuffer(size)

for i in range (0, count):
    buffer.Add(i);
    print("Добавили элемент: ", i ,"; Занято памяти: ", buffer.GetOccupiedSpace())

for i in range (0, size):
    print("Достали элемент: ", buffer.Get() ,"; Занято памяти: ", buffer.GetOccupiedSpace())
