#include <gtest/gtest.h>
#include "myString.h"

// Constructor Tests
TEST(MyStringTest, DefaultConstructor) {
    MyString str;
    EXPECT_EQ(str.length(), 0);
    EXPECT_EQ(str.toString(), "");
}

TEST(MyStringTest, ConstructorWithString) {
    MyString str("Hello");
    EXPECT_EQ(str.length(), 5);
    EXPECT_EQ(str.toString(), "Hello");
}

// Copy Constructor and Assignment Operator Tests
TEST(MyStringTest, CopyConstructor) {
    MyString str1("Original");
    MyString str2(str1);
    EXPECT_EQ(str2.toString(), "Original");
    
    // Verify deep copy
    str1[0] = 'M';
    EXPECT_EQ(str1.toString(), "Mriginal");
    EXPECT_EQ(str2.toString(), "Original");
}

TEST(MyStringTest, AssignmentOperator) {
    MyString str1("First");
    MyString str2("Second");
    str2 = str1;
    EXPECT_EQ(str2.toString(), "First");
    
    // Verify deep copy
    str1[0] = 'L';
    EXPECT_EQ(str1.toString(), "Lirst");
    EXPECT_EQ(str2.toString(), "First");
}

// Substring Tests
TEST(MyStringTest, SubstringBasic) {
    MyString str("Hello World");
    EXPECT_EQ(str.substr(0, 5).toString(), "Hello");
    EXPECT_EQ(str.substr(6, 5).toString(), "World");
}

TEST(MyStringTest, SubstringEdgeCases) {
    MyString str("Test");
    EXPECT_EQ(str.substr(0).toString(), "Test");
    EXPECT_EQ(str.substr(2, 10).toString(), "st");
    EXPECT_THROW(str.substr(5), std::out_of_range);
}

// Concatenation Tests
TEST(MyStringTest, Concatenation) {
    MyString str1("Hello");
    MyString str2(" World");
    MyString result = str1 + str2;
    EXPECT_EQ(result.toString(), "Hello World");
}

TEST(MyStringTest, AppendString) {
    MyString str("Hello");
    str += MyString(" World");
    EXPECT_EQ(str.toString(), "Hello World");
}

TEST(MyStringTest, AppendChar) {
    MyString str("Hello");
    str += '!';
    EXPECT_EQ(str.toString(), "Hello!");
}

// Array Access Tests
TEST(MyStringTest, ArrayAccess) {
    MyString str("Test");
    EXPECT_EQ(str[0], 'T');
    EXPECT_EQ(str[3], 't');
    EXPECT_THROW(str[4], std::out_of_range);
}

// Comparison Tests
TEST(MyStringTest, ComparisonOperators) {
    MyString str1("abc");
    MyString str2("def");
    MyString str3("abc");
    
    EXPECT_TRUE(str1 == str3);
    EXPECT_TRUE(str1 != str2);
    EXPECT_TRUE(str1 < str2);
    EXPECT_TRUE(str1 <= str2);
    EXPECT_TRUE(str2 > str1);
    EXPECT_TRUE(str2 >= str1);
}

// Stream Output Test
TEST(MyStringTest, StreamOutput) {
    MyString str("Test String");
    std::ostringstream oss;
    oss << str;
    EXPECT_EQ(oss.str(), "Test String");
}

// Edge Cases
TEST(MyStringTest, EmptyStringOperations) {
    MyString empty;
    EXPECT_EQ(empty.length(), 0);
    EXPECT_EQ(empty.toString(), "");
    EXPECT_THROW(empty[0], std::out_of_range);
    
    MyString str("Test");
    EXPECT_TRUE(empty < str);
    EXPECT_TRUE(str > empty);
}