#include <iostream>

int main() {
    int size;

    // Ask the user for the size of the array
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    // Dynamically allocate an array of the given size
    int* array = new int[size];

    // Input elements into the array
    std::cout << "Enter " << size << " numbers:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << "Element " << i + 1 << ": ";
        std::cin >> array[i];
    }

    // Print the elements and their addresses
    std::cout << "\nYou entered the following numbers and their addresses:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << "Value: " << array[i] << ", Address: " << &array[i] << std::endl;
    }

    // Free the dynamically allocated memory
    delete[] array;

    return 0;
}