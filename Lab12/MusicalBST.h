// MusicalBST.h
#ifndef MUSICAL_BST_H
#define MUSICAL_BST_H

#include <vector>
#include "Node.h"

class MusicalBST {
private:
    Node* root;

    // Private helper methods
    Node* _insert_(Node* node, int noteIndex);
    void preOrderHelper(Node* node, std::vector<int>& result);
    void inOrderHelper(Node* node, std::vector<int>& result);
    void postOrderHelper(Node* node, std::vector<int>& result);

public:
    // Constructor
    MusicalBST() : root(nullptr) {}

    // Public methods
    void insert(int noteIndex);
    std::vector<int> preOrder();
    std::vector<int> inOrder();
    std::vector<int> postOrder();
};

#endif // MUSICAL_BST_H