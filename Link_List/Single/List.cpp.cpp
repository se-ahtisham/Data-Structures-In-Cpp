#include "List.h"
#include <iostream>
using namespace std;

List::List() : head(nullptr) {}

List::~List() {
    while (head) {
        DeleteFirst();
    }
}

void List::InsertAtTail(int data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void List::InsertAtHead(int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void List::Search(int data) {
    Node* temp = head;
    while (temp) {
        if (temp->data == data) {
            cout << "Value " << data << " found." << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Value " << data << " not found." << endl;
}

void List::Update(int oldValue, int newValue) {
    Node* temp = head;
    while (temp) {
        if (temp->data == oldValue) {
            temp->data = newValue;
            return;
        }
        temp = temp->next;
    }
}

void List::PrintAll() {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void List::PrintReverse(Node* node) {
    if (!node) return;
    PrintReverse(node->next);
    cout << node->data << " ";
}

void List::PrintMiddle() {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (slow) {
        cout << "Middle value: " << slow->data << endl;
    }
}

void List::DeleteLast() {
    if (!head) return;
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

void List::DeleteFirst() {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void List::DeleteAtValue(int data) {
    if (!head) return;
    if (head->data == data) {
        DeleteFirst();
        return;
    }
    Node* temp = head;
    while (temp->next) {
        if (temp->next->data == data) {
            Node* toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
            return;
        }
        temp = temp->next;
    }
}

void List::DeleteMiddle() {
    if (!head) return;
    Node* slow = head;
    Node* fast = head;
    Node* prev = nullptr;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (prev) {
        prev->next = slow->next;
        delete slow;
    }
}

void List::DeleteDuplicates() {
    Node* temp = head;
    while (temp && temp->next) {
        if (temp->data == temp->next->data) {
            Node* toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
        } else {
            temp = temp->next;
        }
    }
}

Node* List::getHead() {
    return head;
}
