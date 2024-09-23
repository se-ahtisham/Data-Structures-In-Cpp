class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value);
    Node* insert(Node* root, int value);
    bool search(Node* root, int value);
    Node* update(Node* root, int oldValue, int newValue);
    Node* deleteNode(Node* root, int value);
    void printAllLeftValues(Node* root);
    void printAllRightValues(Node* root);
    int findMostHighestValue(Node* root);
    int findMostLowestValue(Node* root);
    int countAllNodes(Node* root);
    bool isPerfect(Node* root);
    bool isBalanced(Node* root);
    int findHeight(Node* root);
    void preOrder(Node* root);
    void postOrder(Node* root);
    void inOrder(Node* root);
};