class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node* insertRecursive(Node* node, int data);
    int calculateNodeHeight(Node* node);
    int balanceFactor(Node* node);
    Node* rotateRight(Node* y);
    Node* rotateLeft(Node* x);
    void inOrderTraversal(Node* node);

    Node(); // Constructor declaration
};