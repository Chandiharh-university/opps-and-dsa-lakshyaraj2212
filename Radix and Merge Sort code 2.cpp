//.....................................Radix Sort.......................
#include <iostream>
#include <vector>
#include <algorithm>
// Function to perform counting sort based on the digit represented by exp
void countingSort(std::vector<int>& arr, int size, int exp) {
    std::vector<int> output(size); // Output array
    int count[10] = {0}; // Count array for digits (0-9)
    // Store count of occurrences of each digit
    for (int i = 0; i < size; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    // Change count[i] so that it contains the actual position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    // Build the output array
    for (int i = size - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    // Copy the output array to arr[], so that arr[] now contains sorted numbers
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
    // Print the array after sorting by the current digit
    std::cout << "After sorting by digit with exp = " << exp << ": ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
// Function to get the maximum value in the array
int getMax(const std::vector<int>& arr, int size) {
    return *std::max_element(arr.begin(), arr.end());
}
// Main function to implement Radix Sort
void radixSort(std::vector<int>& arr, int size) {
    // Get the maximum number to know the number of digits
    int maxVal = getMax(arr, size);
    // Do counting sort for every digit
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, size, exp);
    }
}
int main() {
    int size;
    // Ask the user for the size of the array
    std::cout << "Enter the size of the array: ";
    std::cin >> size;
    // Create a vector to hold the array elements
    std::vector<int> array(size);
    // Input elements into the array
    std::cout << "Enter " << size << " numbers:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << "Element " << i + 1 << ": ";
        std::cin >> array[i];
    }
    // Perform Radix Sort and show steps
    std::cout << "\nSorting the array using Radix Sort:\n";
    radixSort(array, size);
    // Print the sorted array
    std::cout << "\nSorted array: ";
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}






//..................................Merge Sort....................
#include <iostream>
#include <vector>

// Function to merge two halves of the array
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of the left subarray
    int n2 = right - mid;    // Size of the right subarray
    // Create temporary arrays
    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);
    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];
    // Merge the temporary arrays back into arr[left..right]
    int i = 0; // Initial index of the first subarray
    int j = 0; // Initial index of the second subarray
    int k = left; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of leftArr, if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    // Copy the remaining elements of rightArr, if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
    // Print the array after merging
    std::cout << "After merging: ";
    for (int m = left; m <= right; m++) {
        std::cout << arr[m] << " ";
    }
    std::cout << std::endl;
}
// Function to implement Merge Sort
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Find the middle point
        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}
int main() {
    int size;
    // Ask the user for the size of the array
    std::cout << "Enter the size of the array: ";
    std::cin >> size;
    // Create a vector to hold the array elements
    std::vector<int> array(size);
    // Input elements into the array
    std::cout << "Enter " << size << " numbers:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << "Element " << i + 1 << ": ";
        std::cin >> array[i];
    }
    // Perform Merge Sort and show steps
    std::cout << "\nSorting the array using Merge Sort:\n";
    mergeSort(array, 0, size - 1);

    // Print the sorted array
    std::cout << "\nSorted array: ";
    for (const auto& num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}