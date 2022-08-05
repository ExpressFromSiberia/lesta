#include <iostream>

bool isEven(int value) { 
    return !(value & 1);
}

int main() {
    setlocale(0, "");
    int num = 0;

    while (true) {
        std::cout << "¬ведите число:" << std::endl;
        std::cin >> num;

        if (isEven(num))
            std::cout << "„исло " << num << " чЄтное" << std::endl;
        else
            std::cout << "„исло " << num << " нечЄтное" << std::endl;
    }

    return 0;
}