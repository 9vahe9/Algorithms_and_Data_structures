#include "../include/binary_search.h"

// Функция бинарного поиска
int binarySearch(const std::vector<int>& vec, int target)
{
    int start = 0;
    int end = vec.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (vec[mid] > target)
        {
            end = mid - 1;
        }
        else if (vec[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

// Рекурсивный бинарный поиск
int binarySearchRecursive(const std::vector<int>& vec, int target, int start, int end)
{
    if (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (vec[mid] > target)
        {
            return binarySearchRecursive(vec, target, start, mid - 1);
        }
        else if (vec[mid] < target)
        {
            return binarySearchRecursive(vec, target, mid + 1, end);
        }
        else
        {
            return mid;
        }
    }
    
    return -1;
}

// Функция для нахождения нижней границы
int lower_bound(const std::vector<int>& vec, int target)
{
    int start = 0;
    int end = vec.size();

    while (start < end)
    {
        int mid = start + (end - start) / 2;

        if (vec[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }

    return start;
}

// Функция для нахождения верхней границы
int upper_bound(const std::vector<int>& vec, int target)
{
    int start = 0;
    int end = vec.size();

    while (start < end)
    {
        int mid = start + (end - start) / 2;

        if (vec[mid] <= target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }

    return start;
}

// Функция для нахождения диапазона равенства
std::pair<int, int> equal_range(const std::vector<int>& vec, int target)
{
    return {lower_bound(vec, target), upper_bound(vec, target)};
}

int main()
{
    // Пример отсортированного вектора
    std::vector<int> vec = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    // Тестирование функции binarySearch
    std::cout << "Testing binarySearch:\n";
    std::vector<int> targets = {7, 15, 2, 19, 1, 11};
    for (int target : targets)
    {
        int result = binarySearch(vec, target);
        if (result != -1)
        {
            std::cout << "Element " << target << " found at index: " << result << std::endl;
        }
        else
        {
            std::cout << "Element " << target << " not found" << std::endl;
        }
    }
    std::cout << std::endl;

    // Тестирование функции binarySearchRecursive
    std::cout << "Testing binarySearchRecursive:\n";
    for (int target : targets)
    {
        int result = binarySearchRecursive(vec, target, 0, vec.size() - 1);
        if (result != -1)
        {
            std::cout << "Element " << target << " found at index: " << result << std::endl;
        }
        else
        {
            std::cout << "Element " << target << " not found" << std::endl;
        }
    }
    std::cout << std::endl;

    // Тестирование функции lower_bound
    std::cout << "Testing lower_bound:\n";
    for (int target : targets)
    {
        int result = lower_bound(vec, target);
        if (result < vec.size())
        {
            std::cout << "Lower bound for " << target << " is " << vec[result] << " at index " << result << std::endl;
        }
        else
        {
            std::cout << "No lower bound found for " << target << std::endl;
        }
    }
    std::cout << std::endl;

    // Тестирование функции upper_bound
    std::cout << "Testing upper_bound:\n";
    for (int target : targets)
    {
        int result = upper_bound(vec, target);
        if (result < vec.size())
        {
            std::cout << "Upper bound for " << target << " is " << vec[result] << " at index " << result << std::endl;
        }
        else
        {
            std::cout << "No upper bound found for " << target << std::endl;
        }
    }
    std::cout << std::endl;

    // Тестирование функции equal_range
    std::cout << "Testing equal_range:\n";
    for (int target : targets)
    {
        auto range = equal_range(vec, target);
        std::cout << "Equal range for " << target << " is from index " << range.first << " to " << range.second << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
