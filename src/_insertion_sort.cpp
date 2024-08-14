// insertion_sort.cpp

#include "../include/insertion_sort.h" // Убедитесь, что путь к заголовочному файлу корректен


void insertion_sort(std::vector<int>& vec)
{
    for (size_t i = 1; i < vec.size(); ++i) // Используйте 'vec' вместо 'arr'
    {
        int key = vec[i];
        int j = i - 1;

        // Перемещаем элементы vec[0..i-1], которые больше ключа,
        // на одну позицию вперед от их текущей позиции
        while (j >= 0 && vec[j] > key)
        {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = key;
    }
}

int main() {
    std::vector<int> vec = {12, 11, 10, 9, 8, 7}; // Пример массива

    std::cout << "source vec: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    insertion_sort(vec); // Вызов функции сортировки

    std::cout << "sorted vec: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
