

class CircusBuffer:

    def __init__(self, size):
        self.data = [0 for i in range(size)]
        self.size = size
        self.addIteration = 0
        self.getIteration = 0
        self.occupiedSpace = 0

    def GetFreeSpace(self):
        return self.size - self.occupiedSpace

    def GetOccupiedSpace(self):
        return self.occupiedSpace

    def Add(self, val):
        if self.occupiedSpace >= self.size:
            print("Buffer is full! Data was overwrited.")
            self.data[self.addIteration] = val
            self.addIteration += 1
            self.addIteration %= self.size
            self.getIteration += 1
        else:
            self.data[self.addIteration] = val
            self.addIteration += 1
            self.addIteration %= self.size
            self.occupiedSpace += 1

    def Get(self):
        if self.occupiedSpace == 0:
            print("Buffer is empty")
            return
        res = self.data[self.getIteration]
        self.getIteration += 1
        self.getIteration %= self.size
        self.occupiedSpace -= 1
        return res

size = 5
count = 7
buffer = CircusBuffer(size)

for i in range (0, count):
    buffer.Add(i);
    print("Добавили элемент: ", i ,"; Свободно памяти: ", buffer.GetFreeSpace())

for i in range (0, size):
    print("Достали элемент: ", buffer.Get() ,"; Свободно памяти: ", buffer.GetFreeSpace())
