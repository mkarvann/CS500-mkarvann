// memorySafe.cpp
// This file contains the fixed version of memoryLeaks.cpp, where all memory leaks have been resolved.
// Each leak has been fixed by correctly deallocating memory.

#include <iostream>
#include <string>

class LeakClass {
public:
    LeakClass() {
        data = new int[100];  // Memory allocated
        std::cout << "LeakClass object created." << std::endl;
    }
    ~LeakClass() {
        delete[] data;  // Fixed: Added delete[] to free memory
    }
private:
    int* data;
};

void causeLeak1() {
    int* ptr = new int(10);  // Memory allocated
    delete ptr;  // Fixed: Added delete to free memory
}

void causeLeak2() {
    int* ptr = new int[50];  // Memory allocated
    delete[] ptr;  // Fixed: Added delete[] to free memory
}

void causeLeak3() {
    LeakClass* lc = new LeakClass();  // Memory allocated
    delete lc;  // Fixed: Added delete to free memory
}

void causeLeak4() {
    std::string* str = new std::string("Hello World");  // Memory allocated
    delete str;  // Fixed: Added delete to free memory
}

void causeLeak5() {
    int* ptr = new int[1000];  // Memory allocated
    delete[] ptr;  // Fixed: Added delete[] to free memory
}

void causeLeak6() {
    int* ptr = nullptr;
    try {
        ptr = new int[200];  // Memory allocated
        throw std::runtime_error("Some error occurred");
    } catch (const std::exception& e) {
        // Memory will now be deleted even if exception occurs
        delete[] ptr;  // Fixed: Added delete[] in the catch block
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
    
    return 0;
}
