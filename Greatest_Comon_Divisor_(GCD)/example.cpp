#include <iostream>

int main()
{
    int arr[] = {12, 11, 10, 9, 8, 7}; // Initialize array
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate number of elements

    for (int i = size - 1; i >= 0; --i) { // Loop backwards
        std::cout << arr[i] << " "; // Print each element
    }

    std::cout << std::endl; // Add a newline after the output

    return 0;
}
