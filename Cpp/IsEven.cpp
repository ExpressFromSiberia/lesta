#include <iostream>

bool isEven(int value) { 
    return !(value & 1);
}

int main() {
    setlocale(0, "");
    int num = 0;

    while (true) {
        std::cout << "������� �����:" << std::endl;
        std::cin >> num;

        if (isEven(num))
            std::cout << "����� " << num << " ������" << std::endl;
        else
            std::cout << "����� " << num << " ��������" << std::endl;
    }

    return 0;
}