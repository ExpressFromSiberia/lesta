    #include <iostream>

using namespace std;

struct list
{
    int data;
    struct list* next;
};

class CircularBuffer {
private:
    list* _head;
    list* _tail;
    list* _addNode;
    list* _getNode;
    int  _numElements;
    int _size;

public:
    CircularBuffer(int size) {
        _numElements = 0;
        _size = size;
        _head = new list;
        _tail = _head;
        _head->next = _tail;
        for (int i = 1; i < size; i++) {
            list* tmp = new list;
            _tail->next = tmp;
            tmp->next = _head;
            _tail = tmp;
        }
        _getNode = _head;
        _addNode = _head;
    };

    ~CircularBuffer() {
        while (_size) {
            list* del_elem = _head;
            _head = _head->next;
            _size--;
            delete del_elem;
        }
    };

    int GetOccupiedSpace() {
        return _numElements;
    };

    void Add(int val) {
        if (_numElements >= _size) {
            cout << "Buffer is full. Data overwrited!" << endl;
            _getNode = _addNode->next;
            --_numElements;
        }
        _addNode->data = val;
        _addNode = _addNode->next;
        _numElements++;
    };

    int Get() {
        if (_numElements == 0)
            throw "Buffer is empty";

        int res = _getNode->data;
        _getNode = _getNode->next;
        _numElements--;
        return res;
    };
};

int main(int argc, char** argv)
{
    setlocale(0, "");
    CircularBuffer c(5);
    int count = 7;

    for (int i = 1; i <= count; ++i) {
        c.Add(i);
        cout << "Added element: " << i << endl;
        cout << "Number of elements: " << c.GetOccupiedSpace() << endl;
    }

    count = c.GetOccupiedSpace();
    for (int i = 0; i < count; ++i) {
        cout << "Got an element: " << c.Get() << endl;
        cout << "Number of elements: " << c.GetOccupiedSpace() << endl;
    }

    return 0;
}

