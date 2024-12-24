#include <iostream>

// Function to add two numbers using pass by value
void addByValue(float a, float b, float &result) {
    result = a + b; // Calculate the sum and store it in result
}

// Function to add two numbers using pass by reference
void addByReference(float *a, float *b, float *result) {
    *result = *a + *b; // Dereference pointers to calculate the sum
}

int main() {
    float num1, num2, sumByValue, sumByReference;
    std::cout << "Enter the first number (float): ";
    std::cin >> num1;
    std::cout << "Enter the second number (float): ";
    std::cin >> num2;
    addByValue(num1, num2, sumByValue);
    std::cout << "Sum using pass by value: " << sumByValue << std::endl;
    addByReference(&num1, &num2, &sumByReference);
    std::cout << "Sum using pass by reference: " << sumByReference << std::endl;
    return 0;
}