#include <iostream>
#include "Node.h"

using namespace std;

Node::Node(int data) : data(data), next(nullptr), prev(nullptr) {}

void Node::InsertAtTail(int data) {
    Node* newNode = new Node(data);
    if (!next) {
        next = newNode;
        prev = newNode;
        newNode->next = this; // Make it circular
        newNode->prev = this; // Make it circular
        return;
    }
    Node* temp = this->prev;
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = this;
    this->prev = newNode; // Maintain circularity
}

void Node::InsertAtHead(int data) {
    Node* newNode = new Node(data);
    if (!next) {
        next = newNode;
        prev = newNode;
        newNode->next = this; // Make it circular
        newNode->prev = this; // Make it circular
    } else {
        Node* temp = this->prev;
        newNode->next = this;
        newNode->prev = temp;
        temp->next = newNode;
        this->prev = newNode; // Maintain circularity
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
    Node* temp = this->prev;
    temp->prev->next = this; // Update the next pointer of the second to last node
    this->prev = temp->prev; // Update the last node's previous pointer
    delete temp; // Free the last node
}

void Node::DeleteFirst() {
    if (!next) return;
    if (next == this) {
        delete this;
        return;
    }
    Node* temp = this->next;
    this->next = temp->next; // Bypass the first node
    temp->next->prev = this; // Update the new first node's previous pointer
    delete temp; // Free the old first node
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
            toDelete->next->prev = temp; // Update the previous pointer
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
        Node* runner = current->next;
        while (runner != this) {
            if (runner->data == current->data) {
                Node* toDelete = runner;
                runner->prev->next = runner->next; // Bypass the duplicate
                if (runner->next != this) {
                    runner->next->prev = runner->prev; // Update previous pointer
                }
                runner = runner->next;
                delete toDelete;
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    } while (current != this);
}
