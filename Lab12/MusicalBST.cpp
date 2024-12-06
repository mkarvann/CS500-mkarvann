// MusicalBST.cpp
#include "MusicalBST.h"

// Private recursive insert method
Node* MusicalBST::_insert_(Node* node, int noteIndex) {
    // If tree is empty, create new node
    if (node == nullptr) {
        return new Node(noteIndex);
    }

    // Compare note index to determine insertion path
    if (noteIndex < node->noteIndex) {
        node->left = _insert_(node->left, noteIndex);
    } else if (noteIndex > node->noteIndex) {
        node->right = _insert_(node->right, noteIndex);
    }
    // If note is equal, we won't insert duplicates

    return node;
}

// Public insert method
void MusicalBST::insert(int noteIndex) {
    root = _insert_(root, noteIndex);
}

// Pre-order traversal (Root, Left, Right)
void MusicalBST::preOrderHelper(Node* node, std::vector<int>& result) {
    if (node == nullptr) return;

    result.push_back(node->noteIndex);  // Root
    preOrderHelper(node->left, result);   // Left
    preOrderHelper(node->right, result);  // Right
}

std::vector<int> MusicalBST::preOrder() {
    std::vector<int> result;
    preOrderHelper(root, result);
    return result;
}

// In-order traversal (Left, Root, Right)
void MusicalBST::inOrderHelper(Node* node, std::vector<int>& result) {
    if (node == nullptr) return;

    inOrderHelper(node->left, result);   // Left
    result.push_back(node->noteIndex);  // Root
    inOrderHelper(node->right, result);  // Right
}

std::vector<int> MusicalBST::inOrder() {
    std::vector<int> result;
    inOrderHelper(root, result);
    return result;
}

// Post-order traversal (Left, Right, Root)
void MusicalBST::postOrderHelper(Node* node, std::vector<int>& result) {
    if (node == nullptr) return;

    postOrderHelper(node->left, result);   // Left
    postOrderHelper(node->right, result);  // Right
    result.push_back(node->noteIndex);  // Root
}

std::vector<int> MusicalBST::postOrder() {
    std::vector<int> result;
    postOrderHelper(root, result);
    return result;
}