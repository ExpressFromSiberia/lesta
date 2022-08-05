

def Merge(array, res_array, left, mid, right):
    i = 0
    j = 0
    while (left + i < mid and mid + j < right):
        if (array[left + i] < array[mid + j]):
            res_array[i + j] = array[left + i]
            i += 1
        else:
            res_array[i + j] = array[mid + j]
            j += 1

    while (left + i < mid):
        res_array[i + j] = array[left + i]
        i += 1

    while (mid + j < right):
        res_array[i + j] = array[mid + j]
        j += 1

    for step in range(0, i + j):
        array[left + step] = res_array[step];

def Sort(array):
    size = len(array)
    result = [0 for i in range(size)]
    i = 1
    while i < size:
        j = 0
        while j < size - i:
            Merge(array, result,  j, j + i, min(j + 2 * i, size))
            j += 2 * i
        i *= 2


size = int(input("Укажите размер массива: "));
A = [0 for i in range(size)]

array = list(map(int, input("Введите элементы массива через пробел: ").split()))

print("Исходный массив размера ", size)
print(array)

Sort(array)

print("Результат сортировки:")
print(array)

