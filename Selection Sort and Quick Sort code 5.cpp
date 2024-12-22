//.............................Selection Sort...............................
#include <iostream>

void selectionSort(int arr[], int size) {
    // Perform Selection Sort
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i; // Assume the minimum is the first element in the unsorted part

        // Find the index of the minimum element in the unsorted part
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // Update minIndex if a smaller element is found
            }
        }

        // Swap the found minimum element with the first element of the unsorted part
        if (minIndex != i) {
            std::swap(arr[i], arr[minIndex]);

            // Print the array after each swap
            std::cout << "After swapping " << arr[minIndex] << " and " << arr[i] << ": ";
            for (int k = 0; k < size; ++k) {
                std::cout << arr[k] << " ";
            }
            std::cout << std::endl;
        }
    }
}

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

    // Perform Selection Sort and show steps
    std::cout << "\nSorting the array using Selection Sort:\n";
    selectionSort(array, size);

    // Print the sorted array
    std::cout << "\nSorted array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    // Free the dynamically allocated memory
    delete[] array;

    return 0;
}





//........................................Quick Sort.............................
#include <iostream>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choosing the last element as the pivot
    int i = low - 1; // Index of the smaller element

    for (int j = low; j < high; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(arr[i], arr[j]); // Swap
            std::cout << "After swapping " << arr[i] << " and " << arr[j] << ": ";
            for (int k = 0; k <= high; ++k) {
                std::cout << arr[k] << " ";
            }
            std::cout << std::endl;
        }
    }
    swap(arr[i + 1], arr[high]); // Swap the pivot element with the element at i + 1
    std::cout << "After moving pivot " << arr[i + 1] << " to correct position: ";
    for (int k = 0; k <= high; ++k) {
        std::cout << arr[k] << " ";
    }
    std::cout << std::endl;

    return i + 1; // Return the partitioning index
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

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

    // Perform Quick Sort and show steps
    std::cout << "\nSorting the array using Quick Sort:\n";
    quickSort(array, 0, size - 1);

    // Print the sorted array
    std::cout << "\nSorted array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    // Free the dynamically allocated memory
    delete[] array;

    return 0;
}