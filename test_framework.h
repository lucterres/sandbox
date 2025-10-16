#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <sstream>

class TestFramework {
private:
    static int tests_run;
    static int tests_passed;
    static std::vector<std::string> failures;

public:
    struct TestCase {
        std::string name;
        std::function<void()> test_func;
    };

    static std::vector<TestCase> test_cases;

    // Macro helpers for assertions
    static void assert_true(bool condition, const std::string& message, const std::string& file, int line) {
        tests_run++;
        if (condition) {
            tests_passed++;
            std::cout << "  ✓ " << message << '\n';
        } else {
            std::ostringstream oss;
            oss << "  ✗ " << message << " (at " << file << ":" << line << ")";
            failures.push_back(oss.str());
            std::cout << oss.str() << '\n';
        }
    }

    static void assert_equal(int expected, int actual, const std::string& message, const std::string& file, int line) {
        tests_run++;
        if (expected == actual) {
            tests_passed++;
            std::cout << "  ✓ " << message << '\n';
        } else {
            std::ostringstream oss;
            oss << "  ✗ " << message << " - Expected: " << expected << ", Got: " << actual 
                << " (at " << file << ":" << line << ")";
            failures.push_back(oss.str());
            std::cout << oss.str() << '\n';
        }
    }

    static void assert_not_null(void* ptr, const std::string& message, const std::string& file, int line) {
        tests_run++;
        if (ptr != nullptr) {
            tests_passed++;
            std::cout << "  ✓ " << message << '\n';
        } else {
            std::ostringstream oss;
            oss << "  ✗ " << message << " - Pointer is null (at " << file << ":" << line << ")";
            failures.push_back(oss.str());
            std::cout << oss.str() << '\n';
        }
    }

    static void assert_null(void* ptr, const std::string& message, const std::string& file, int line) {
        tests_run++;
        if (ptr == nullptr) {
            tests_passed++;
            std::cout << "  ✓ " << message << '\n';
        } else {
            std::ostringstream oss;
            oss << "  ✗ " << message << " - Pointer is not null (at " << file << ":" << line << ")";
            failures.push_back(oss.str());
            std::cout << oss.str() << '\n';
        }
    }

    static void register_test(const std::string& name, std::function<void()> test_func) {
        test_cases.push_back({name, test_func});
    }

    static int run_all_tests() {
        std::cout << "Running " << test_cases.size() << " test(s)...\n\n";
        
        for (const auto& test_case : test_cases) {
            std::cout << "Running: " << test_case.name << '\n';
            try {
                test_case.test_func();
            } catch (const std::exception& e) {
                tests_run++;
                std::ostringstream oss;
                oss << "  ✗ Exception thrown: " << e.what();
                failures.push_back(oss.str());
                std::cout << oss.str() << '\n';
            }
            std::cout << '\n';
        }

        // Print summary
        std::cout << "========================================\n";
        std::cout << "Test Results:\n";
        std::cout << "  Tests run: " << tests_run << '\n';
        std::cout << "  Passed: " << tests_passed << '\n';
        std::cout << "  Failed: " << (tests_run - tests_passed) << '\n';
        std::cout << "========================================\n";

        if (!failures.empty()) {
            std::cout << "\nFailures:\n";
            for (const auto& failure : failures) {
                std::cout << failure << '\n';
            }
        }

        return tests_run - tests_passed; // Return number of failures
    }

    static void reset() {
        tests_run = 0;
        tests_passed = 0;
        failures.clear();
        test_cases.clear();
    }
};

// Static member definitions
int TestFramework::tests_run = 0;
int TestFramework::tests_passed = 0;
std::vector<std::string> TestFramework::failures;
std::vector<TestFramework::TestCase> TestFramework::test_cases;

// Convenience macros
#define ASSERT_TRUE(condition, message) \
    TestFramework::assert_true(condition, message, __FILE__, __LINE__)

#define ASSERT_EQUAL(expected, actual, message) \
    TestFramework::assert_equal(expected, actual, message, __FILE__, __LINE__)

#define ASSERT_NOT_NULL(ptr, message) \
    TestFramework::assert_not_null(ptr, message, __FILE__, __LINE__)

#define ASSERT_NULL(ptr, message) \
    TestFramework::assert_null(ptr, message, __FILE__, __LINE__)

#define TEST(test_name, test_func) \
    TestFramework::register_test(test_name, test_func)

#define RUN_ALL_TESTS() \
    TestFramework::run_all_tests()