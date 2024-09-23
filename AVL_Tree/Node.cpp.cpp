#include "Node.h"
#include <iostream>
using namespace std;

Node::Node() : data(0), left(nullptr), right(nullptr), height(1) {}

int Node::calculateNodeHeight(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    int leftHeight = calculateNodeHeight(node->left);
    int rightHeight = calculateNodeHeight(node->right);
    return 1 + max(leftHeight, rightHeight);
}

int Node::balanceFactor(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    int leftHeight = calculateNodeHeight(node->left);
    int rightHeight = calculateNodeHeight(node->right);
    return leftHeight - rightHeight;
}

Node* Node::rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    return x;
}

Node* Node::rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    return y;
}

Node* Node::insertRecursive(Node* node, int data) {
    if (node == nullptr) {
        Node* newNode = new Node();
        newNode->data = data;
        return newNode;
    }

    if (data < node->data) {
        node->left = insertRecursive(node->left, data);
    } else if (data > node->data) {
        node->right = insertRecursive(node->right, data);
    } else {
        return node;
    }

    node->height = 1 + max(calculateNodeHeight(node->left), calculateNodeHeight(node->right));
    int balance = balanceFactor(node);

    if (balance > 1 && data < node->left->data) {
        return rotateRight(node);
    }
    if (balance < -1 && data > node->right->data) {
        return rotateLeft(node);
    }
    if (balance > 1 && data > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && data < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void Node::inOrderTraversal(Node* node) {
    if (node != nullptr) {
        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }
}

#include"Queue.h"


Queue::Queue() :top(-1), back(-1), capacity(5),count(0)
{
	arr = new int[capacity];
}

Queue::~Queue()

{
	delete[] arr;
}


bool Queue::Isfull()
{
	return(count == capacity) ? true : false;
}

bool Queue::IsEmpty()
{
	return (count == 0) ? true : false;
}

void Queue::enqueue(int element)
{
	if (IsEmpty())
	{
		top = 0;
		back = 0;
		arr[back] = element;
		count++;	
	}
	else if(!Isfull())
	{
		back++;
		arr[back] = element;
		count ++;
	}
	else
	{
		cout << "Queue is Full" << endl;
	}

}
void Queue::dequeue()
{
	if (!IsEmpty())
	{
		cout << arr[top];
		top++;
		count--;
	}

	else
	{
		cout << "Queue is Empty" << endl;
	}


}


void Queue::printtop()
{
	if (!IsEmpty())
	{
		cout << arr[top];
	}
	else
	{
		cout << "Queue is empty" << endl;
	}
}
