// Node.h
#ifndef NODE_H
#define __NODE_H

#include <string>

class Node {
public:
    int noteIndex;  // Index corresponding to NOTE_FREQUENCIES
    Node* left;
    Node* right;

    // Constructor
    Node(int index) : 
        noteIndex(index), 
        left(nullptr), 
        right(nullptr) {}
};

#endif // NODE_H