#include <SFML/Audio.hpp>
#include <cmath>
#include <vector>
#include <iostream>

const int SAMPLE_RATE = 44100;  // 44.1 kHz sample rate
const int DURATION = 1;  // Duration of each note in seconds

// Frequencies of the notes in Hz (assuming A4 = 440 Hz)
const float NOTE_FREQUENCIES[] = {
    440.0f, // A
    466.16f, // B
    523.25f, // C
    554.37f, // D
    587.33f, // E
    622.25f, // F
    659.26f  // G
};

// Node class for Binary Search Tree
class Node {
public:
    int noteIndex;
    Node* left;
    Node* right;

    Node(int index) : 
        noteIndex(index), 
        left(nullptr), 
        right(nullptr) {}
};

// Musical Binary Search Tree Class
class MusicalBST {
private:
    Node* root;

    // Private recursive insert method
    Node* _insert_(Node* node, int noteIndex) {
        // If tree is empty -> create new node
        if (node == nullptr) {
            return new Node(noteIndex);
        }

        // Compare note index to determine insertion path
        if (noteIndex < node->noteIndex) {
            node->left = _insert_(node->left, noteIndex);
        } else if (noteIndex > node->noteIndex) {
            node->right = _insert_(node->right, noteIndex);
        }
        // If note is equal -> won't insert duplicates

        return node;
    }

    // Pre-order traversal helper (Root, Left, Right)
    void preOrderHelper(Node* node, std::vector<int>& result) {
        if (node == nullptr) return;

        result.push_back(node->noteIndex);  // Root
        preOrderHelper(node->left, result);   // Left
        preOrderHelper(node->right, result);  // Right
    }

    // In-order traversal helper (Left, Root, Right)
    void inOrderHelper(Node* node, std::vector<int>& result) {
        if (node == nullptr) return;

        inOrderHelper(node->left, result);   // Left
        result.push_back(node->noteIndex);  // Root
        inOrderHelper(node->right, result);  // Right
    }

    // Post-order traversal helper (Left, Right, Root)
    void postOrderHelper(Node* node, std::vector<int>& result) {
        if (node == nullptr) return;

        postOrderHelper(node->left, result);   // Left
        postOrderHelper(node->right, result);  // Right
        result.push_back(node->noteIndex);  // Root
    }

public:
    // Constructor
    MusicalBST() : root(nullptr) {}

    // Public insert method
    void insert(int noteIndex) {
        root = _insert_(root, noteIndex);
    }

    // Public traversal methods
    std::vector<int> preOrder() {
        std::vector<int> result;
        preOrderHelper(root, result);
        return result;
    }

    std::vector<int> inOrder() {
        std::vector<int> result;
        inOrderHelper(root, result);
        return result;
    }

    std::vector<int> postOrder() {
        std::vector<int> result;
        postOrderHelper(root, result);
        return result;
    }
};

// Function to generate a sine wave for a given frequency and duration
std::vector<sf::Int16> generateSineWave(float frequency, int duration) {
    std::vector<sf::Int16> samples(duration * SAMPLE_RATE);

    for (size_t i = 0; i < samples.size(); ++i) {
        float time = static_cast<float>(i) / SAMPLE_RATE;
        samples[i] = static_cast<sf::Int16>(32767 * std::sin(2 * M_PI * frequency * time));  // 16-bit PCM data
    }

    return samples;
}

int main() {
    MusicalBST bst;

    // Insert notes into the tree (using note indices)
    bst.insert(0);  // A
    bst.insert(3);  // D
    bst.insert(5);  // F
    bst.insert(2);  // C
    bst.insert(6);  // G
    bst.insert(1);  // B
    bst.insert(4);  // E

    // Create a sound buffer and sound object
    sf::SoundBuffer buffer;
    sf::Sound sound;

    // Play traversals
    std::cout << "Pre-order Traversal: \n";
    std::vector<int> preOrder = bst.preOrder();
    for (int noteIndex : preOrder) {
        std::cout << "Note index: " << noteIndex << std::endl;

        // Generate the sine wave for the current note
        std::vector<sf::Int16> samples = generateSineWave(NOTE_FREQUENCIES[noteIndex], DURATION);

        // Load the generated samples into the buffer
        if (!buffer.loadFromSamples(samples.data(), samples.size(), 1, SAMPLE_RATE)) {
            std::cerr << "Error loading sound buffer!" << std::endl;
            return -1;
        }

        // Set the buffer for the sound and play it
        sound.setBuffer(buffer);
        sound.play();

        // Wait for the note to finish playing
        sf::sleep(sf::seconds(DURATION));
    }

    std::cout << "\nIn-order Traversal: \n";
    std::vector<int> inOrder = bst.inOrder();
    for (int noteIndex : inOrder) {
        std::cout << "Note index: " << noteIndex << std::endl;

        // Generate the sine wave for the current note
        std::vector<sf::Int16> samples = generateSineWave(NOTE_FREQUENCIES[noteIndex], DURATION);

        // Load the generated samples into the buffer
        if (!buffer.loadFromSamples(samples.data(), samples.size(), 1, SAMPLE_RATE)) {
            std::cerr << "Error loading sound buffer!" << std::endl;
            return -1;
        }

        // Set the buffer for the sound and play it
        sound.setBuffer(buffer);
        sound.play();

        // Wait for the note to finish playing
        sf::sleep(sf::seconds(DURATION));
    }

    std::cout << "\nPost-order Traversal: \n";
    std::vector<int> postOrder = bst.postOrder();
    for (int noteIndex : postOrder) {
        std::cout << "Note index: " << noteIndex << std::endl;

        // Generate the sine wave for the current note
        std::vector<sf::Int16> samples = generateSineWave(NOTE_FREQUENCIES[noteIndex], DURATION);

        // Load the generated samples into the buffer
        if (!buffer.loadFromSamples(samples.data(), samples.size(), 1, SAMPLE_RATE)) {
            std::cerr << "Error loading sound buffer!" << std::endl;
            return -1;
        }

        // Set the buffer for the sound and play it
        sound.setBuffer(buffer);
        sound.play();

        // Wait for the note to finish playing
        sf::sleep(sf::seconds(DURATION));
    }

    return 0;
}