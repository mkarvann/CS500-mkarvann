#include <gtest/gtest.h>
#include "hamming.h"
#include <vector>
#include <string>

class HammingCodeTest : public ::testing::Test {
protected:
    HammingCode hammingCode;
};

// Test constructor and matrix initialization
TEST_F(HammingCodeTest, ConstructorInitialization) {
    // This test could check the internal matrix configurations
    // You might need to add getter methods to verify matrix contents
}

// Test single-bit error correction
TEST_F(HammingCodeTest, SingleBitErrorCorrection) {
    std::vector<int> code = {1, 0, 1, 1, 0, 1, 0}; // Original code
    std::vector<int> errorCode = code;
    errorCode[2] ^= 1; // Introduce error at position 3

    auto decoded = hammingCode.decodeWord(errorCode);
    EXPECT_EQ(decoded, std::vector<int>({1, 1, 0, 0})); // Corrected data bits
}

// Test multiple error detection
TEST_F(HammingCodeTest, MultipleErrorDetection) {
    std::vector<int> code = {1, 0, 1, 1, 0, 1, 0};
    std::vector<int> errorCode = code;
    errorCode[2] ^= 1; // First error
    errorCode[5] ^= 1; // Second error

    // Expect an exception or error message
    EXPECT_THROW(hammingCode.decodeWord(errorCode), std::runtime_error);
}

// Test matrix multiplication mod 2
TEST_F(HammingCodeTest, MatrixMultiplicationMod2) {
    Eigen::Matrix<int, 3, 7> testMatrix;
    testMatrix << 1, 0, 1, 0, 1, 0, 1,
                  0, 1, 1, 0, 0, 1, 1,
                  0, 0, 0, 1, 1, 1, 1;
    
    std::vector<int> testVector = {1, 1, 0, 1, 1, 0, 0};
    
    // Implement and test matrix multiplication
    std::vector<int> result = hammingCode.matrixMultiplyMod2(testMatrix, testVector);
    EXPECT_EQ(result.size(), 3);
}

// Additional tests for edge cases
TEST_F(HammingCodeTest, InvalidCodeLength) {
    std::vector<int> shortCode = {1, 0, 1}; // Too short
    EXPECT_THROW(hammingCode.decodeWord(shortCode), std::runtime_error);
}

// More tests can be added to cover various scenarios

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}