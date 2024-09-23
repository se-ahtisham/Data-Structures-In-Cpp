#include "Node.h"

class List {
private:
    Node* head;

public:
    List();
    ~List();
    void InsertAtTail(int data);
    void InsertAtHead(int data);
    void Search(int data);
    void Update(int oldValue, int newValue);
    void PrintAll();
    void PrintReverse(Node* node);
    void PrintMiddle();
    void DeleteLast();
    void DeleteFirst();
    void DeleteAtValue(int data);
    void DeleteMiddle();
    void DeleteDuplicates();
    Node* getHead();
};