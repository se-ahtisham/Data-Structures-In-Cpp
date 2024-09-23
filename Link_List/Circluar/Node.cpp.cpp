#include <iostream>
#include "Node.h"

using namespace std;

Node::Node(int data) : data(data), next(nullptr) {}

void Node::InsertAtTail(int data) {
    Node* newNode = new Node(data);
    if (!next) {
        next = newNode;
        newNode->next = this; // Make it circular
        return;
    }
    Node* temp = this;
    while (temp->next != this) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = this; // Maintain circularity
}

void Node::InsertAtHead(int data) {
    Node* newNode = new Node(data);
    if (!next) {
        next = newNode;
        newNode->next = this; // Make it circular
    } else {
        Node* temp = this;
        while (temp->next != this) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = this; // Maintain circularity
    }
}

void Node::Search(int data) {
    if (!next) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = this;
    do {
        if (temp->data == data) {
            cout << "Value " << data << " found." << endl;
            return;
        }
        temp = temp->next;
    } while (temp != this);
    cout << "Value " << data << " not found." << endl;
}

void Node::Update(int oldValue, int newValue) {
    if (!next) return;
    Node* temp = this;
    do {
        if (temp->data == oldValue) {
            temp->data = newValue;
            return;
        }
        temp = temp->next;
    } while (temp != this);
}

void Node::PrintAll() {
    if (!next) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = this;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != this);
    cout << endl;
}

void Node::PrintMiddle() {
    if (!next) {
        cout << "List is empty." << endl;
        return;
    }
    Node* slow = this;
    Node* fast = this;
    while (fast != this && fast->next != this) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "Middle value: " << slow->data << endl;
}

void Node::DeleteLast() {
    if (!next) return;
    if (next == this) {
        delete this;
        return;
    }
    Node* temp = this;
    while (temp->next->next != this) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = this; // Maintain circularity
}

void Node::DeleteFirst() {
    if (!next) return;
    if (next == this) {
        delete this;
        return;
    }
    Node* temp = this;
    while (temp->next != this) {
        temp = temp->next;
    }
    Node* toDelete = this;
    this->data = this->next->data; // Update data to next node's data
    this->next = this->next->next; // Bypass the next node
    temp->next = this; // Maintain circularity
    delete toDelete; // Free the old node
}

void Node::DeleteAtValue(int data) {
    if (!next) return;
    if (this->data == data) {
        DeleteFirst();
        return;
    }
    Node* temp = this;
    while (temp->next != this) {
        if (temp->next->data == data) {
            Node* toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
            return;
        }
        temp = temp->next;
    }
}

void Node::DeleteDuplicates() {
    if (!next) return;
    Node* current = this;
    do {
        Node* runner = current;
        while (runner->next != this) {
            if (runner->next->data == current->data) {
                Node* toDelete = runner->next;
                runner->next = toDelete->next;
                delete toDelete;
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    } while (current != this);
}
