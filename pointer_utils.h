#pragma once

// Pointer utilities for demonstrating pointer operations
namespace PointerUtils {
    
    // Function to safely dereference a pointer
    template<typename T>
    bool safe_dereference(T* ptr, T& result) {
        if (ptr != nullptr) {
            result = *ptr;
            return true;
        }
        return false;
    }

    // Function to check if a pointer is valid (not null)
    template<typename T>
    bool is_valid_pointer(T* ptr) {
        return ptr != nullptr;
    }

    // Function to safely dereference a pointer to pointer
    template<typename T>
    bool safe_double_dereference(T** ptr, T& result) {
        if (ptr != nullptr && *ptr != nullptr) {
            result = **ptr;
            return true;
        }
        return false;
    }

    // Function to get address of a variable
    template<typename T>
    T* get_address(T& variable) {
        return &variable;
    }

    // Function to demonstrate pointer arithmetic (returns the next memory location)
    template<typename T>
    T* next_address(T* ptr) {
        return (ptr != nullptr) ? ptr + 1 : nullptr;
    }

    // Function to compare two pointers
    template<typename T>
    bool pointers_equal(T* ptr1, T* ptr2) {
        return ptr1 == ptr2;
    }

    // Function to calculate offset between two pointers
    template<typename T>
    long pointer_offset(T* ptr1, T* ptr2) {
        if (ptr1 != nullptr && ptr2 != nullptr) {
            return ptr2 - ptr1;
        }
        return 0;
    }
}