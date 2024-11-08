// memoryLeaks.cpp
// This file contains at least six memory leaks with a variety of causes.
// Leaks will occur in different situations like missing delete, 
// using new[] but not delete[], and ignoring exceptions.

#include <iostream>
#include <string>

class LeakClass {
public:
    LeakClass() {
        data = new int[100];  // Memory allocated
        std::cout << "LeakClass object created." << std::endl;
    }
    ~LeakClass() {
        // Destructor does not free the memory, so it causes a memory leak
        // delete[] data;   // This is missing, causing a leak
    }
private:
    int* data;
};

void causeLeak1() {
    int* ptr = new int(10);  // Memory allocated but never freed
    // Missing delete
}

void causeLeak2() {
    int* ptr = new int[50];  // Memory allocated but never freed
    // Missing delete[]
}

void causeLeak3() {
    LeakClass* lc = new LeakClass();  // Memory allocated but never freed
    // Missing delete
}

void causeLeak4() {
    std::string* str = new std::string("Hello World");  // Memory allocated
    // This will be lost when the function ends, causing a leak
}

void causeLeak5() {
    int* ptr = new int[1000];  // Memory allocated but not freed
    // Not using delete[] for cleanup
}

void causeLeak6() {
    int* ptr = nullptr;
    try {
        ptr = new int[200];  // Memory allocated
        throw std::runtime_error("Some error occurred");  // Exception thrown before cleanup
    } catch (const std::exception& e) {
        // Memory is not freed if an exception occurs
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
}

int main() {
    causeLeak1();
    causeLeak2();
    causeLeak3();
    causeLeak4();
    causeLeak5();
    causeLeak6();
    
    // No memory deallocation here, hence leaks persist.
    return 0;
}
