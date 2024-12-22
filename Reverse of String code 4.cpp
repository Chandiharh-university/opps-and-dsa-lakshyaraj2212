#include <iostream>
#include <string>

int main() {
    // Declare a string variable to hold user input
    std::string input;

    // Prompt the user for input
    std::cout << "Enter a string: ";
    std::getline(std::cin, input); // Use getline to include spaces

    // Reverse the string
    std::string reversedInput(input.rbegin(), input.rend());

    // Display the reversed string
    std::cout << "Reversed string: " << reversedInput << std::endl;

    return 0;
}