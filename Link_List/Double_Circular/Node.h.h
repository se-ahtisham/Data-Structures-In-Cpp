class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data);
    void InsertAtTail(int data);
    void InsertAtHead(int data);
    void Search(int data);
    void Update(int oldValue, int newValue);
    void PrintAll();
    void PrintReverse();
    void PrintMiddle();
    void DeleteLast();
    void DeleteFirst();
    void DeleteAtValue(int data);
    void DeleteMiddle();
    void DeleteDuplicates();
};