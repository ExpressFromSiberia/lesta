#include <iostream>

using namespace std;

class CircularBuffer {
private:
    int* _data;
    int  _size;
    int _addIteration;
    int _getIteration;
    int  _occupiedSpace;

public:
    CircularBuffer(int size) {
        _occupiedSpace = 0;
        _getIteration = 0;
        _addIteration = 0;
        _size = size;
        _data = new int[_size];
    };

    ~CircularBuffer() {
        delete[] _data;
    };

    int GetFreeSpace() {
        return _size - _occupiedSpace;
    };

    int GetOccupiedSpace() {
        return _occupiedSpace;
    };

    void Add(int val) {
        if (_occupiedSpace >= _size) {
            cout << "Buffer is full! Data was overwrited." << endl;
            _data[_addIteration++] = val;
            _addIteration %= _size;
            _getIteration++;
        }
        else {
            _data[_addIteration++] = val;
            _addIteration %= _size;
            _occupiedSpace++;
        }
    };

    int Get() {
        if (_occupiedSpace == 0)
            throw "Буффер пуст";

        int res = _data[_getIteration++];
        _getIteration %= _size;
        --_occupiedSpace;
        return res;
    };
};

int main(int argc, char** argv)
{
    setlocale(0, "");
    int count = 7;
    CircularBuffer c(5);

    for (int i = 1; i <= count; ++i) {
        c.Add(i);
        cout << "Добавили элемент: " << i << endl;
        cout << "Всего элементов: " << c.GetOccupiedSpace() << endl;
    }

    count = c.GetOccupiedSpace();
    for (int i = 0; i < count; ++i) {
        cout << "Достали элемент: " << c.Get() << endl;
        cout << "Всего элементов: " << c.GetOccupiedSpace() << endl;
    }


    return 0;
}

