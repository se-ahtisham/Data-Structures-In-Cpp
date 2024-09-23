#include <iostream>
#include "BST.h"
using namespace std;

int main() {
    BST tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    cout << "In-order traversal: ";
    tree.inOrder(tree.root);
    cout << endl;

    cout << "Pre-order traversal: ";
    tree.preOrder(tree.root);
    cout << endl;

    cout << "Post-order traversal: ";
    tree.postOrder(tree.root);
    cout << endl;

    cout << "Minimum value: " << tree.findMin() << endl;
    cout << "Maximum value: " << tree.findMax() << endl;

    tree.search(7);
    tree.search(20);

    cout << "Number of nodes: " << tree.countNodes(tree.root) << endl;

    tree.deleteNode(5);
    cout << "In-order after deletion: ";
    tree.inOrder(tree.root);
    cout << endl;

    cout << "Is tree balanced? " << (tree.isBalanced(tree.root) ? "Yes" : "No") << endl;

    return 0;
}
