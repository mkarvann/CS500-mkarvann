#ifndef H3_LIBRARY_H
#define H3_LIBRARY_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

// Helper functions
namespace {
    int min(int a, int b) {
        return (a < b) ? a : b;
    }

    void flip(std::vector<int>& stack, int position) {
        for (int i = 0; i < position / 2; i++) {
            std::swap(stack[i], stack[position - 1 - i]);
        }
    }

    int findMaxIndex(const std::vector<int>& stack, int end) {
        int maxIdx = 0;
        for (int i = 1; i <= end; i++) {
            if (stack[i] > stack[maxIdx]) {
                maxIdx = i;
            }
        }
        return maxIdx;
    }

    bool isSorted(const std::vector<int>& stack) {
        for (size_t i = 0; i < stack.size() - 1; i++) {
            if (stack[i] > stack[i + 1]) return false;
        }
        return true;
    }

    void sortVector(std::vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
}

// HW3_01: Common Permutations
std::string HW3_01(const std::string& s1, const std::string& s2) {
    std::vector<int> freq_a(26, 0), freq_b(26, 0);
    
    for (char c : s1) {
        freq_a[c - 'a']++;
    }
    
    for (char c : s2) {
        freq_b[c - 'a']++;
    }

    std::string result;
    for (int i = 0; i < 26; ++i) {
        int count = min(freq_a[i], freq_b[i]);
        result.append(count, static_cast<char>('a' + i));
    }

    return result;
}

// HW3_02: Vito's Family
int HW3_02(int r, const std::vector<int>& s) {
    std::vector<int> sorted_streets = s;
    sortVector(sorted_streets);

    int median = sorted_streets[r / 2];
    int total_distance = 0;

    for (int street : sorted_streets) {
        total_distance += std::abs(street - median);
    }

    return total_distance;
}

// HW3_03: Stacks of Flapjacks
std::vector<int> HW3_03(std::vector<int>& pancakes) {
    std::vector<int> flips;
    int n = pancakes.size();
    
    if (isSorted(pancakes)) {
        flips.push_back(0);
        return flips;
    }

    for (int curr_size = n; curr_size > 1; curr_size--) {
        int maxIdx = findMaxIndex(pancakes, curr_size - 1);

        if (maxIdx != curr_size - 1) {
            if (maxIdx != 0) {
                flip(pancakes, maxIdx + 1);
                flips.push_back(n - maxIdx);
            }
            flip(pancakes, curr_size);
            flips.push_back(n - curr_size + 1);
        }
    }
    
    flips.push_back(0);
    return flips;
}

// HW3_04: Primary Arithmetic
std::string HW3_04(int a, int b) {
    int carry_count = 0, carry = 0;
    
    while (a > 0 || b > 0 || carry > 0) {
        int sum = (a % 10) + (b % 10) + carry;
        if (sum >= 10) {
            carry = 1;
            carry_count++;
        } else {
            carry = 0;
        }
        a /= 10;
        b /= 10;
    }

    if (carry_count == 0) {
        return "No carry operation.";
    } else if (carry_count == 1) {
        return "1 carry operation.";
    } else {
        return std::to_string(carry_count) + " carry operations.";
    }
}

#endif // HW3_LIBRARY_H