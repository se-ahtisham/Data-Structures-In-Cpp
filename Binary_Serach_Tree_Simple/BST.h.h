#include "Node.h"
using namespace std;

class BST {
public:
    Node* root;

    BST();
    void insert(int val);
    void search(int val);
    int findMin();
    int findMax();
    void preOrder(Node* node);
    void inOrder(Node* node);
    void postOrder(Node* node);
    void deleteNode(int val);
    int countNodes(Node* node);
    bool isPerfect(Node* node, int depth, int level);
    bool isBalanced(Node* node);
    int height(Node* node);
};