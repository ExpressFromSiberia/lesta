#include <iostream>

bool isEven(int value) { 
    return !(value & 1);
}

int main() {
    setlocale(0, "");
    int num = 0;

    while (true) {
        std::cout << "Enter the number:" << std::endl;
        std::cin >> num;

        if (isEven(num))
            std::cout << "Number " << num << " is even" << std::endl;
        else
            std::cout << "Number " << num << " is odd" << std::endl;
    }

    return 0;
}
