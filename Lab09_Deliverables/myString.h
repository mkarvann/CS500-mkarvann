#ifndef MYSTRING_H
#define MYSTRING_H

#include <string>
#include <iostream>

class MyString {
private:
    char* data;
    size_t strLength;

public:
    // Constructor
    MyString(const std::string& str = "");
    
    // Destructor
    ~MyString();
    
    // Copy constructor
    MyString(const MyString& other);
    
    // Assignment operator
    MyString& operator=(const MyString& other);
    
    // Conversion to std::string
    std::string toString() const;
    
    // Length getter
    size_t length() const;
    
    // Substring
    MyString substr(size_t start, size_t n = std::string::npos) const;
    
    // Concatenation operators
    MyString operator+(const MyString& other) const;
    MyString& operator+=(const MyString& other);
    MyString& operator+=(char c);
    
    // Array subscript operator
    char& operator[](size_t index);
    const char& operator[](size_t index) const;
    
    // Comparison operators
    bool operator==(const MyString& other) const;
    bool operator!=(const MyString& other) const;
    bool operator<(const MyString& other) const;
    bool operator<=(const MyString& other) const;
    bool operator>(const MyString& other) const;
    bool operator>=(const MyString& other) const;
    
    // Stream insertion operator
    friend std::ostream& operator<<(std::ostream& os, const MyString& str);

private:
    void deepCopy(const char* src);
    int compareToString(const MyString& other) const;
};

#endif // MYSTRING_H