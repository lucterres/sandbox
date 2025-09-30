#include <iostream>

// It is better to use std:: instead of "using namespace std;"
// to avoid polluting the global namespace, which can lead to name conflicts in larger projects.
int main() {
    int   number = 5;
    int*  pointerToNumber  = &number;   // Use descriptive variable names to improve code readability.
    int* * pointerToPointer = &pointerToNumber;

    // Using '\n' is generally more performant than std::endl because it avoids
    // unnecessarily flushing the output buffer. A flush is forced only when needed,
    // for example, before reading from std::cin or when the program terminates.
    std::cout << "\n";
    std::cout << "Value of number: " << number << '\n';
    std::cout << "Address of number stored in pointerToNumber: " << pointerToNumber << " = " << &number << '\n';
    std::cout << "Value at the address stored in pointerToNumber: " << *pointerToNumber << '\n';

    std::cout << "\nDemonstrating a pointer to a pointer for clarity.\n";
    std::cout << "--------------------------------\n";

    std::cout << "Value  of pointerToPointer: " << pointerToPointer << " = " << &pointerToNumber << '\n';
    std::cout << "Value at the address stored in pointerToPointer (address of number): " << *pointerToPointer << '\n';
    std::cout << "Value of number accessed through pointer to pointer: " << **pointerToPointer << '\n';

    std::cout << "--------------------------------\n";
    std::cout << "Its a good practice: check if a pointer is null before dereferencing it\n";
    std::cout << "IT prevents crashes from accessing invalid memory.\n";
    std::cout << "--------------------------------\n";
    
    if (pointerToNumber == nullptr) {
        std::cout << "a null pointer." << '\n';
    }
    std::cout << "--------------------------------\n";

    return 0;
}