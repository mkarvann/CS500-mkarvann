#include "h3_library.h"
#include <iostream>

int main() {
    // HW3_01: Common Permutations
    std::cout << "HW3_01: Common Permutations" << std::endl;
    std::string a1 = "pretty", b1 = "women";
    std::cout << HW3_01(a1, b1) << std::endl;  // Expected: e

    std::string a2 = "walking", b2 = "down";
    std::cout << HW3_01(a2, b2) << std::endl;  // Expected: nw

    std::string a3 = "the", b3 = "street";
    std::cout << HW3_01(a3, b3) << std::endl;  // Expected: et

    // HW3_02: Vito's Family
    std::cout << "\nHW3_02: Vito's Family" << std::endl;
    std::vector<int> street1 = {2, 5};
    std::cout << HW3_02(2, street1) << std::endl;  // Expected: 3

    std::vector<int> street2 = {2, 4, 6};
    std::cout << HW3_02(3, street2) << std::endl;  // Expected: 4

    std::vector<int> street3 = {5, 9, 13};
    std::cout << HW3_02(3, street3) << std::endl;  // Expected: 8

    // HW3_03: Stacks of Flapjacks
    std::cout << "\nHW3_03: Stacks of Flapjacks" << std::endl;
    std::vector<std::vector<int>> test_cases = {
        {1, 2, 3, 4, 5},
        {5, 4, 3, 2, 1},
        {5, 1, 2, 3, 4}
    };

    for (auto stack : test_cases) {
        // Print initial stack
        for (int num : stack) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
        
        // Get and print the flips
        std::vector<int> flips = HW3_03(stack);
        for (int flip : flips) {
            std::cout << flip << " ";
        }
        std::cout << std::endl;
    }

    // HW3_04: Primary Arithmetic
    std::cout << "\nHW3_04: Primary Arithmetic" << std::endl;
    std::cout << HW3_04(123, 456) << std::endl;  // Expected: No carry operation.
    std::cout << HW3_04(555, 555) << std::endl;  // Expected: 3 carry operations.
    std::cout << HW3_04(123, 594) << std::endl;  // Expected: 1 carry operation.

    return 0;
}