#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>


void Merge(std::vector<int>& A, std::vector<int>& result, int left, int mid, int right) {
    int i = 0;
    int j = 0;

    while (left + i < mid && mid + j < right) {
        if (A[left + i] < A[mid + j]) {
            result[i + j] = A[left + i];
            i++;
        }
        else {
            result[i + j] = A[mid + j];
            j++;
        }
    }

    while (left + i < mid) {
        result[i + j] = A[left + i];
        i++;
    }

    while (mid + j < right) {
        result[i + j] = A[mid + j];
        j++;
    }

    for (int step = 0; step < i + j; step++)
        A[left + step] = result[step];
}

void Sort(std::vector<int>& A) {
    int size = A.size();
    std::vector<int> result(size);
    for (int i = 1; i < size; i *= 2) {
        for (int j = 0; j < size - i; j += 2 * i) {
            Merge(A, result,  j, j + i, std::min(j + 2 * i, size));
        }
    }
}

int main() {
    setlocale(0, "");
    int size = 0;

    std::cout << "”кажите размер массива." << std::endl;
    std::cin >> size;
    std::vector<int> A(size);

    std::cout << "¬ведите элементы массива через пробел." << std::endl;
    for (int i = 0; i < size; i++)
        std::cin >> A[i];

    std::cout << "»сходный массив размера " << size << std::endl;
    for (int i = 0; i < size - 1; i++)
        std::cout << A[i] << " ";
    std::cout << A[size - 1] << std::endl;

    Sort(A);

    std::cout << "–езультат сортировки:" << std::endl;
    for (int i = 0; i < size; i++)
        std::cout << A[i] << " ";

    return 0;
}