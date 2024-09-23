#include "BST.h"

BST::BST() {
    root = NULL;
}

void BST::insert(int val) {
    Node* newNode = new Node(val);
    if (root == NULL) {
        root = newNode;
        return;
    }
    Node* temp = root;
    while (true) {
        if (val < temp->data) {
            if (temp->left == NULL) {
                temp->left = newNode;
                return;
            }
            temp = temp->left;
        } else {
            if (temp->right == NULL) {
                temp->right = newNode;
                return;
            }
            temp = temp->right;
        }
    }
}

void BST::search(int val) {
    Node* temp = root;
    while (temp != NULL) {
        if (val < temp->data) {
            temp = temp->left;
        } else if (val > temp->data) {
            temp = temp->right;
        } else {
            cout << "Data found: " << val << endl;
            return;
        }
    }
    cout << "Data not found: " << val << endl;
}

int BST::findMin() {
    Node* temp = root;
    while (temp && temp->left != NULL) {
        temp = temp->left;
    }
    return (temp ? temp->data : -1);
}

int BST::findMax() {
    Node* temp = root;
    while (temp && temp->right != NULL) {
        temp = temp->right;
    }
    return (temp ? temp->data : -1);
}

void BST::preOrder(Node* node) {
    if (node == NULL) return;
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

void BST::inOrder(Node* node) {
    if (node == NULL) return;
    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}

void BST::postOrder(Node* node) {
    if (node == NULL) return;
    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << " ";
}

void BST::deleteNode(int val) {
    Node* curr = root;
    Node* parent = NULL;
    while (curr != NULL && curr->data != val) {
        parent = curr;
        curr = (val < curr->data) ? curr->left : curr->right;
    }
    if (curr == NULL) return;

    if (curr->left == NULL && curr->right == NULL) {
        if (curr == root) {
            root = NULL;
        } else if (parent->left == curr) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
    } else if (curr->left == NULL || curr->right == NULL) {
        Node* child = (curr->left) ? curr->left : curr->right;
        if (curr == root) {
            root = child;
        } else if (parent->left == curr) {
            parent->left = child;
        } else {
            parent->right = child;
        }
    } else {
        Node* successor = curr->right;
        Node* successorParent = curr;
        while (successor->left != NULL) {
            successorParent = successor;
            successor = successor->left;
        }
        curr->data = successor->data;
        if (successorParent->left == successor) {
            successorParent->left = successor->right;
        } else {
            successorParent->right = successor->right;
        }
        curr = successor;
    }
    delete curr;
}

int BST::countNodes(Node* node) {
    if (node == NULL) return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}

bool BST::isPerfect(Node* node, int depth, int level) {
    if (node == NULL) return true;
    if (node->left == NULL && node->right == NULL) return (depth == level + 1);
    if (node->left == NULL || node->right == NULL) return false;
    return isPerfect(node->left, depth, level + 1) && isPerfect(node->right, depth, level + 1);
}

bool BST::isBalanced(Node* node) {
    if (node == NULL) return true;
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return abs(leftHeight - rightHeight) <= 1 && isBalanced(node->left) && isBalanced(node->right);
}

int BST::height(Node* node) {
    if (node == NULL) return 0;
    return 1 + max(height(node->left), height(node->right));
}
