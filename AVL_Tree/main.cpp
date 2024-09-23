#include "Node.h"
#include <iostream>
using namespace std;

int main() {
    Node* root = nullptr;
    Node bst;

    root = bst.insertRecursive(root, 10);
    root = bst.insertRecursive(root, 20);
    root = bst.insertRecursive(root, 30);
    root = bst.insertRecursive(root, 40);
    root = bst.insertRecursive(root, 50);
    root = bst.insertRecursive(root, 25);

    cout << "In-order traversal of the AVL tree: ";
    bst.inOrderTraversal(root);
    cout << endl;

    return 0;
}
