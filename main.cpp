#include <iostream>
#include "pointer_utils.h"

// It is better to use std:: instead of "using namespace std;"
// to avoid polluting the global namespace, which can lead to name conflicts in larger projects.
int main() {
    int   number = 5;
    int*  pointerToNumber  = PointerUtils::get_address(number);   // Use descriptive variable names to improve code readability.
    int** pointerToPointer = PointerUtils::get_address(pointerToNumber);

    // Using '\n' is generally more performant than std::endl because it avoids
    // unnecessarily flushing the output buffer. A flush is forced only when needed,
    // for example, before reading from std::cin or when the program terminates.
    std::cout << "\n";
    std::cout << "Value of number: " << number << '\n';
    std::cout << "Address of number stored in pointerToNumber: " << pointerToNumber << " = " << &number << '\n';
    
    // Safe dereferencing demonstration
    int dereferenced_value;
    if (PointerUtils::safe_dereference(pointerToNumber, dereferenced_value)) {
        std::cout << "Value at the address stored in pointerToNumber: " << dereferenced_value << '\n';
    }

    std::cout << "\nDemonstrating a pointer to a pointer for clarity.\n";
    std::cout << "--------------------------------\n";

    std::cout << "Value  of pointerToPointer: " << pointerToPointer << " = " << &pointerToNumber << '\n';
    std::cout << "Value at the address stored in pointerToPointer (address of number): " << *pointerToPointer << '\n';
    
    // Safe double dereferencing demonstration
    int double_dereferenced_value;
    if (PointerUtils::safe_double_dereference(pointerToPointer, double_dereferenced_value)) {
        std::cout << "Value of number accessed through pointer to pointer: " << double_dereferenced_value << '\n';
    }

    std::cout << "--------------------------------\n";
    std::cout << "Its a good practice: check if a pointer is null before dereferencing it\n";
    std::cout << "IT prevents crashes from accessing invalid memory.\n";
    std::cout << "--------------------------------\n";
    
    // Demonstrating pointer validation
    if (!PointerUtils::is_valid_pointer(pointerToNumber)) {
        std::cout << "pointerToNumber is a null pointer." << '\n';
    } else {
        std::cout << "pointerToNumber is valid." << '\n';
    }

    // Demonstrating pointer comparison
    int* sameAddress = PointerUtils::get_address(number);
    if (PointerUtils::pointers_equal(pointerToNumber, sameAddress)) {
        std::cout << "Both pointers point to the same address." << '\n';
    }

    std::cout << "--------------------------------\n";

    return 0;
}