#include <iostream>
#include <cmath>
#include "Node.h"
using namespace std;

Node::Node(int value) {
    data = value;
    left = right = nullptr;
}

// Insert function
Node* Node::insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

// Search function
bool Node::search(Node* root, int value) {
    if (root == nullptr) {
        return false;
    }
    if (root->data == value) {
        return true;
    }
    return value < root->data ? search(root->left, value) : search(root->right, value);
}

// Update function
Node* Node::update(Node* root, int oldValue, int newValue) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->data == oldValue) {
        root->data = newValue;
    } else if (oldValue < root->data) {
        root->left = update(root->left, oldValue, newValue);
    } else {
        root->right = update(root->right, oldValue, newValue);
    }
    return root;
}

// Delete function
Node* Node::deleteNode(Node* root, int value) {
    if (root == nullptr) return nullptr;
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == nullptr) return root->right;
        else if (root->right == nullptr) return root->left;
        Node* temp = new Node(findMostLowestValue(root->right));
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
        delete temp;
    }
    return root;
}

// Print all left values
void Node::printAllLeftValues(Node* root) {
    if (root == nullptr) return;
    if (root->left != nullptr) {
        cout << root->left->data << " ";
        printAllLeftValues(root->left);
    }
}

// Print all right values
void Node::printAllRightValues(Node* root) {
    if (root == nullptr) return;
    if (root->right != nullptr) {
        cout << root->right->data << " ";
        printAllRightValues(root->right);
    }
}

// Find most highest value
int Node::findMostHighestValue(Node* root) {
    if (root == nullptr) throw runtime_error("Tree is empty");
    return root->right ? findMostHighestValue(root->right) : root->data;
}

// Find most lowest value
int Node::findMostLowestValue(Node* root) {
    if (root == nullptr) throw runtime_error("Tree is empty");
    return root->left ? findMostLowestValue(root->left) : root->data;
}

// Count all nodes
int Node::countAllNodes(Node* root) {
    if (root == nullptr) return 0;
    return 1 + countAllNodes(root->left) + countAllNodes(root->right);
}

// Check if the tree is perfect
bool Node::isPerfect(Node* root) {
    int depth = findHeight(root);
    return isPerfectUtil(root, depth, 0);
}

bool Node::isPerfectUtil(Node* node, int depth, int level) {
    if (node == nullptr) return true;
    if (node->left == nullptr && node->right == nullptr) return (depth == level + 1);
    if (node->left == nullptr || node->right == nullptr) return false;
    return isPerfectUtil(node->left, depth, level + 1) && isPerfectUtil(node->right, depth, level + 1);
}

// Check if the tree is balanced
bool Node::isBalanced(Node* root) {
    return isBalancedUtil(root) != -1;
}

int Node::isBalancedUtil(Node* root) {
    if (root == nullptr) return 0;
    int leftHeight = isBalancedUtil(root->left);
    if (leftHeight == -1) return -1;
    int rightHeight = isBalancedUtil(root->right);
    if (rightHeight == -1) return -1;
    if (abs(leftHeight - rightHeight) > 1) return -1;
    return max(leftHeight, rightHeight) + 1;
}

// Find height of the tree
int Node::findHeight(Node* root) {
    if (root == nullptr) return -1;
    return 1 + max(findHeight(root->left), findHeight(root->right));
}

// Pre-order traversal
void Node::preOrder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// Post-order traversal
void Node::postOrder(Node* root) {
    if (root == nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// In-order traversal
void Node::inOrder(Node* root) {
    if (root == nullptr) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
