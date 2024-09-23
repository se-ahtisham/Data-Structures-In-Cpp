#include <iostream>
#include "Node.h"

Node::Node(int data) : data(data), next(nullptr), prev(nullptr) {}

void Node::InsertAtTail(int data) {
    Node* newNode = new Node(data);
    if (!next) {
        next = newNode;
        newNode->next = this;
        newNode->prev = this;
        return;
    }
    Node* temp = this->prev; // This will be the last node
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = this;
    this->prev = newNode; // Maintain circularity
}

void Node::InsertAtHead(int data) {
    Node* newNode = new Node(data);
    if (!next) {
        next = newNode;
        newNode->next = this;
        newNode->prev = this;
    } else {
        Node* temp = this->prev; // Last node
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = this;
        this->prev = newNode; // Maintain circularity
    }
}

void Node::Search(int data) {
    if (!next) {
        std::cout << "List is empty." << std::endl;
        return;
    }
    Node* temp = this;
    do {
        if (temp->data == data) {
            std::cout << "Value " << data << " found." << std::endl;
            return;
        }
        temp = temp->next;
    } while (temp != this);
    std::cout << "Value " << data << " not found." << std::endl;
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
        std::cout << "List is empty." << std::endl;
        return;
    }
    Node* temp = this;
    do {
        std::cout << temp->data << " ";
        temp = temp->next;
    } while (temp != this);
    std::cout << std::endl;
}

void Node::PrintReverse() {
    if (!next) {
        std::cout << "List is empty." << std::endl;
        return;
    }
    Node* temp = this->prev;
    do {
        std::cout << temp->data << " ";
        temp = temp->prev;
    } while (temp != this->prev);
    std::cout << std::endl;
}

void Node::PrintMiddle() {
    if (!next) {
        std::cout << "List is empty." << std::endl;
        return;
    }
    Node* slow = this;
    Node* fast = this;
    while (fast != this && fast->next != this) {
        slow = slow->next;
        fast = fast->next->next;
    }
    std::cout << "Middle value: " << slow->data << std::endl;
}

void Node::DeleteLast() {
    if (!next) return;
    if (next == this) {
        delete this;
        return;
    }
    Node* last = this->prev; // Get last node
    Node* secondLast = last->prev; // Get second last node
    secondLast->next = this; // Maintain circularity
    this->prev = secondLast; // Update head's prev pointer
    delete last; // Delete last node
}

void Node::DeleteFirst() {
    if (!next) return;
    if (next == this) {
        delete this;
        return;
    }
    Node* second = this->next; // Get the second node
    Node* last = this->prev; // Get the last node
    last->next = second; // Update last node's next pointer
    second->prev = last; // Update second node's prev pointer
    delete this; // Delete head
}

void Node::DeleteAtValue(int data) {
    if (!next) return;
    Node* temp = this;
    do {
        if (temp->data == data) {
            Node* toDelete = temp;
            toDelete->prev->next = toDelete->next;
            toDelete->next->prev = toDelete->prev;
            delete toDelete;
            return;
        }
        temp = temp->next;
    } while (temp != this);
}

void Node::DeleteMiddle() {
    if (!next) return;
    Node* slow = this;
    Node* fast = this;
    Node* prev = nullptr;

    while (fast != this && fast->next != this) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (prev) {
        prev->next = slow->next;
        slow->next->prev = prev;
        delete slow;
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
                runner->prev->next = runner->next;
                runner->next->prev = runner->prev;
                runner = runner->next; // Move to next node
                delete toDelete;
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    } while (current != this);
}
