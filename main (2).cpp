//Kaleigha Hayes
//1313037
//11/02/2023
//Proejct 4 
#include <iostream>
#include <ctime>
#include <cstdlib>

class Node {
public:
    int data;
    Node* leftNext;
    Node* rightNext;

    Node(int value) : data(value), leftNext(nullptr), rightNext(nullptr) {}
};

class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() : root(nullptr) {}

    // Insert a new node with value into the BST
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // Helper function to insert a new node recursively
    Node* insertRecursive(Node* current, int value) {
        if (current == nullptr) {
            return new Node(value);
        }

        if (value < current->data) {
            current->leftNext = insertRecursive(current->leftNext, value);
        } else if (value > current->data) {
            current->rightNext = insertRecursive(current->rightNext, value);
        }

        return current;
    }

    // Traverse the tree in pre-order and print the values
    void preOrderTraversal(Node* current) {
        if (current == nullptr) return;

        std::cout << current->data << " ";
        preOrderTraversal(current->leftNext);
        preOrderTraversal(current->rightNext);
    }

    // Traverse the tree in in-order and print the values
    void inOrderTraversal(Node* current) {
        if (current == nullptr) return;

        inOrderTraversal(current->leftNext);
        std::cout << current->data << " ";
        inOrderTraversal(current->rightNext);
    }

    // Traverse the tree in post-order and print the values
    void postOrderTraversal(Node* current) {
        if (current == nullptr) return;

        postOrderTraversal(current->leftNext);
        postOrderTraversal(current->rightNext);
        std::cout << current->data << " ";
    }
};

int main() {
    srand(time(0));
    BinarySearchTree bst;

    // Create 35 random natural numbers and insert them into the BST
    for (int i = 0; i < 35; ++i) {
        int value = rand() % 100;
        std::cout << "Inserting: " << value << std::endl;
        bst.insert(value);
    }

    std::cout << "Pre-order traversal: ";
    bst.preOrderTraversal(bst.root);
    std::cout << std::endl;

    std::cout << "In-order traversal: ";
    bst.inOrderTraversal(bst.root);
    std::cout << std::endl;

    std::cout << "Post-order traversal: ";
    bst.postOrderTraversal(bst.root);
    std::cout << std::endl;

    return 0;
}
