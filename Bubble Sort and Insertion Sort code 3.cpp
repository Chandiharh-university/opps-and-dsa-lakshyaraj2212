#include <iostream>

void bubbleSort(int arr[], int size) {
    bool swapped;
    // Perform Bubble Sort
    for (int i = 0; i < size - 1; ++i) {
        swapped = false;
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                std::swap(arr[j], arr[j + 1]);
                swapped = true;

                // Print the array after each swap
                std::cout << "After swapping " << arr[j + 1] << " and " << arr[j] << ": ";
                for (int k = 0; k < size; ++k) {
                    std::cout << arr[k] << " ";
                }
                std::cout << std::endl;
            }
        }
        // If no two elements were swapped by inner loop, then break
        if (!swapped) {
            break;
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

    // Perform Bubble Sort and show steps
    std::cout << "\nSorting the array using Bubble Sort:\n";
    bubbleSort(array, size);

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



// .................................Insertion Sort Code...........................................
#include <iostream>

void insertionSort(int arr[], int size) {
    // Perform Insertion Sort
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;

            // Print the array after each shift
            std::cout << "After shifting " << arr[j + 1] << ": ";
            for (int k = 0; k < size; ++k) {
                std::cout << arr[k] << " ";
            }
            std::cout << std::endl;
        }
        arr[j + 1] = key;

        // Print the array after inserting the key
        std::cout << "After inserting " << key << ": ";
        for (int k = 0; k < size; ++k) {
            std::cout << arr[k] << " ";
        }
        std::cout << std::endl;
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

    // Perform Insertion Sort and show steps
    std::cout << "\nSorting the array using Insertion Sort:\n";
    insertionSort(array, size);

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