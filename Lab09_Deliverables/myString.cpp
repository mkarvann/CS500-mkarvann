#include "myString.h"
#include <cstring>
#include <stdexcept>

MyString::MyString(const std::string& str) : data(nullptr), strLength(str.length()) {
    deepCopy(str.c_str());
}

MyString::~MyString() {
    delete[] data;
}

MyString::MyString(const MyString& other) : data(nullptr), strLength(other.strLength) {
    deepCopy(other.data);
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        delete[] data;
        strLength = other.strLength;
        deepCopy(other.data);
    }
    return *this;
}

void MyString::deepCopy(const char* src) {
    if (src) {
        data = new char[strLength + 1];
        std::strcpy(data, src);
    } else {
        data = new char[1];
        data[0] = '\0';
        strLength = 0;
    }
}

std::string MyString::toString() const {
    return std::string(data ? data : "");
}

size_t MyString::length() const {
    return strLength;
}

MyString MyString::substr(size_t start, size_t n) const {
    if (start > strLength) {
        throw std::out_of_range("Start index out of range");
    }
    
    size_t count = (n == std::string::npos) ? (strLength - start) : 
                   std::min(n, strLength - start);
    
    std::string temp(data + start, count);
    return MyString(temp);
}

MyString MyString::operator+(const MyString& other) const {
    std::string combined = this->toString() + other.toString();
    return MyString(combined);
}

MyString& MyString::operator+=(const MyString& other) {
    size_t newLength = strLength + other.strLength;
    char* newData = new char[newLength + 1];
    
    if (data) {
        std::strcpy(newData, data);
    }
    if (other.data) {
        std::strcpy(newData + strLength, other.data);
    }
    
    delete[] data;
    data = newData;
    strLength = newLength;
    
    return *this;
}

MyString& MyString::operator+=(char c) {
    size_t newLength = strLength + 1;
    char* newData = new char[newLength + 1];
    
    if (data) {
        std::strcpy(newData, data);
    }
    newData[strLength] = c;
    newData[newLength] = '\0';
    
    delete[] data;
    data = newData;
    strLength = newLength;
    
    return *this;
}

char& MyString::operator[](size_t index) {
    if (index >= strLength) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

const char& MyString::operator[](size_t index) const {
    if (index >= strLength) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

int MyString::compareToString(const MyString& other) const {
    return std::strcmp(data, other.data);
}

bool MyString::operator==(const MyString& other) const {
    return compareToString(other) == 0;
}

bool MyString::operator!=(const MyString& other) const {
    return compareToString(other) != 0;
}

bool MyString::operator<(const MyString& other) const {
    return compareToString(other) < 0;
}

bool MyString::operator<=(const MyString& other) const {
    return compareToString(other) <= 0;
}

bool MyString::operator>(const MyString& other) const {
    return compareToString(other) > 0;
}

bool MyString::operator>=(const MyString& other) const {
    return compareToString(other) >= 0;
}

std::ostream& operator<<(std::ostream& os, const MyString& str) {
    os << str.toString();
    return os;
}