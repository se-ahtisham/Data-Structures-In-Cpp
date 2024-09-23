#include <iostream>
#include "Node.h"
using namespace std;

int main() {
    Node* root = nullptr;

    // Example usage
    root = root->insert(root, 10);
    root = root->insert(root, 5);
    root = root->insert(root, 15);
    root = root->insert(root, 3);
    root = root->insert(root, 7);
    root = root->insert(root, 12);
    root = root->insert(root, 18);

    // Search for a value
    cout << "Search 7: " << (root->search(root, 7) ? "Found" : "Not Found") << endl;

    // Update a value
    root = root->update(root, 7, 9);
    cout << "Search 9 after update: " << (root->search(root, 9) ? "Found" : "Not Found") << endl;

    // Delete a value
    root = root->deleteNode(root, 5);
    cout << "Search 5 after deletion: " << (root->search(root, 5) ? "Found" : "Not Found") << endl;

    // Print all left-side values
    cout << "All Left-Side Values: ";
    root->printAllLeftValues(root);
    cout << endl;

    // Print all right-side values
    cout << "All Right-Side Values: ";
    root->printAllRightValues(root);
    cout << endl;

    // Print most highest value
    try {
        cout << "Most Highest Value: " << root->findMostHighestValue(root) << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    // Print most lowest value
    try {
        cout << "Most Lowest Value: " << root->findMostLowestValue(root) << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    // Count all nodes
    cout << "Total Nodes: " << root->countAllNodes(root) << endl;

    // Check if the tree is perfect
    cout << "Is Perfect: " << (root->isPerfect(root) ? "Yes" : "No") << endl;

    // Check if the tree is balanced
    cout << "Is Balanced: " << (root->isBalanced(root) ? "Yes" : "No") << endl;

    // Find height of the tree
    cout << "Height of tree: " << root->findHeight(root) << endl;

    // Pre-order traversal
    cout << "Pre-order traversal: ";
    root->preOrder(root);
    cout << endl;

    // Post-order traversal
    cout << "Post-order traversal: ";
    root->postOrder(root);
    cout << endl;

    // In-order traversal
    cout << "In-order traversal: ";
    root->inOrder(root);
    cout << endl;

    return 0;
}
