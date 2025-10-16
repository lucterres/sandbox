#include "test_framework.h"
#include "pointer_utils.h"
#include <iostream>

// Test fixture for pointer operations
void test_safe_dereference() {
    // Test with valid pointer
    int value = 42;
    int* ptr = &value;
    int result;
    
    ASSERT_TRUE(PointerUtils::safe_dereference(ptr, result), "Safe dereference should succeed with valid pointer");
    ASSERT_EQUAL(42, result, "Dereferenced value should match original value");
    
    // Test with null pointer
    int* null_ptr = nullptr;
    ASSERT_TRUE(!PointerUtils::safe_dereference(null_ptr, result), "Safe dereference should fail with null pointer");
}

void test_is_valid_pointer() {
    int value = 10;
    int* valid_ptr = &value;
    int* null_ptr = nullptr;
    
    ASSERT_TRUE(PointerUtils::is_valid_pointer(valid_ptr), "Valid pointer should be recognized as valid");
    ASSERT_TRUE(!PointerUtils::is_valid_pointer(null_ptr), "Null pointer should be recognized as invalid");
}

void test_safe_double_dereference() {
    // Test with valid pointer to pointer
    int value = 100;
    int* ptr = &value;
    int** ptr_to_ptr = &ptr;
    int result;
    
    ASSERT_TRUE(PointerUtils::safe_double_dereference(ptr_to_ptr, result), "Safe double dereference should succeed");
    ASSERT_EQUAL(100, result, "Double dereferenced value should match original");
    
    // Test with null pointer to pointer
    int** null_ptr_to_ptr = nullptr;
    ASSERT_TRUE(!PointerUtils::safe_double_dereference(null_ptr_to_ptr, result), "Should fail with null pointer to pointer");
    
    // Test with pointer to null pointer
    int* null_ptr = nullptr;
    int** ptr_to_null = &null_ptr;
    ASSERT_TRUE(!PointerUtils::safe_double_dereference(ptr_to_null, result), "Should fail with pointer to null pointer");
}

void test_get_address() {
    int value = 25;
    int* ptr = PointerUtils::get_address(value);
    
    ASSERT_NOT_NULL(ptr, "get_address should return non-null pointer");
    ASSERT_EQUAL(25, *ptr, "Address should point to correct value");
    ASSERT_TRUE(ptr == &value, "Returned address should match direct address-of operator");
}

void test_next_address() {
    int array[3] = {1, 2, 3};
    int* first_ptr = &array[0];
    int* second_ptr = &array[1];
    
    int* calculated_next = PointerUtils::next_address(first_ptr);
    
    ASSERT_NOT_NULL(calculated_next, "next_address should return non-null for valid pointer");
    ASSERT_TRUE(calculated_next == second_ptr, "next_address should point to next element");
    
    // Test with null pointer
    int* null_result = PointerUtils::next_address<int>(nullptr);
    ASSERT_NULL(null_result, "next_address should return null for null input");
}

void test_pointers_equal() {
    int value = 50;
    int* ptr1 = &value;
    int* ptr2 = &value;
    int* ptr3 = PointerUtils::get_address(value);
    
    ASSERT_TRUE(PointerUtils::pointers_equal(ptr1, ptr2), "Pointers to same address should be equal");
    ASSERT_TRUE(PointerUtils::pointers_equal(ptr1, ptr3), "Pointers from different sources to same address should be equal");
    
    int other_value = 60;
    int* other_ptr = &other_value;
    ASSERT_TRUE(!PointerUtils::pointers_equal(ptr1, other_ptr), "Pointers to different addresses should not be equal");
    
    // Test with null pointers
    int* null_ptr = nullptr;
    ASSERT_TRUE(PointerUtils::pointers_equal<int>(nullptr, nullptr), "Two null pointers should be equal");
    ASSERT_TRUE(!PointerUtils::pointers_equal(ptr1, null_ptr), "Valid pointer and null should not be equal");
}

void test_pointer_offset() {
    int array[5] = {10, 20, 30, 40, 50};
    int* ptr1 = &array[0];
    int* ptr2 = &array[2];
    int* ptr3 = &array[4];
    
    ASSERT_EQUAL(2, PointerUtils::pointer_offset(ptr1, ptr2), "Offset should be 2 elements");
    ASSERT_EQUAL(-2, PointerUtils::pointer_offset(ptr2, ptr1), "Reverse offset should be negative");
    ASSERT_EQUAL(4, PointerUtils::pointer_offset(ptr1, ptr3), "Offset to end should be 4");
    ASSERT_EQUAL(0, PointerUtils::pointer_offset(ptr1, ptr1), "Offset to same pointer should be 0");
    
    // Test with null pointers
    ASSERT_EQUAL(0, PointerUtils::pointer_offset<int>(nullptr, ptr1), "Offset with null pointer should be 0");
    ASSERT_EQUAL(0, PointerUtils::pointer_offset<int>(ptr1, nullptr), "Offset to null pointer should be 0");
}

void test_edge_cases() {
    // Test with different data types
    double double_value = 3.14;
    double* double_ptr = PointerUtils::get_address(double_value);
    double double_result;
    
    ASSERT_TRUE(PointerUtils::safe_dereference(double_ptr, double_result), "Should work with double pointers");
    ASSERT_TRUE(double_result == 3.14, "Double value should be preserved");
    
    // Test with char
    char char_value = 'A';
    char* char_ptr = PointerUtils::get_address(char_value);
    
    ASSERT_TRUE(PointerUtils::is_valid_pointer(char_ptr), "Should work with char pointers");
    ASSERT_TRUE(*char_ptr == 'A', "Char value should be preserved");
}

int main() {
    std::cout << "Starting Pointer Utils Unit Tests\n";
    std::cout << "==================================\n\n";
    
    // Register all test cases
    TEST("Safe Dereference Tests", test_safe_dereference);
    TEST("Pointer Validation Tests", test_is_valid_pointer);
    TEST("Safe Double Dereference Tests", test_safe_double_dereference);
    TEST("Get Address Tests", test_get_address);
    TEST("Next Address Tests", test_next_address);
    TEST("Pointer Equality Tests", test_pointers_equal);
    TEST("Pointer Offset Tests", test_pointer_offset);
    TEST("Edge Cases Tests", test_edge_cases);
    
    // Run all tests
    int failures = RUN_ALL_TESTS();
    
    if (failures == 0) {
        std::cout << "\n🎉 All tests passed! The pointer utilities are working correctly.\n";
    } else {
        std::cout << "\n❌ " << failures << " test(s) failed. Please review the code.\n";
    }
    
    return failures;
}