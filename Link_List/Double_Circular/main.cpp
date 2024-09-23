#include <iostream>
#include "Node.h"

using namespace std;

int main() {
    Node* head = nullptr;
    int choice, val;

    cout << endl;
    cout << "\t\t:::::::::::::::::::::::::::::::::::::::::  " << endl;
    cout << "\t\t::::          Circular Doubly Linked List  ::::  " << endl;
    cout << "\t\t:::::::::::::::::::::::::::::::::::::::::  " << endl;
    cout << endl;

    while (true) {
        cout << "1. Insert At Tail\n";
        cout << "2. Insert At Head\n";
        cout << "3. Search\n";
        cout << "4. Update\n";
        cout << "5. Print All\n";
        cout << "6. Print Reverse\n";
        cout << "7. Print Middle\n";
        cout << "8. Delete Last\n";
        cout << "9. Delete First\n";
        cout << "10. Delete By Value\n";
        cout << "11. Delete Middle\n";
        cout << "12. Delete Duplicates\n";
        cout << "0. Exit\n";
        cout << "Please Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Value: ";
                cin >> val;
                if (!head) {
                    head = new Node(val);
                    head->next = head;
                    head->prev = head;
                } else {
                    head->InsertAtTail(val);
                }
                break;
            case 2:
                cout << "Enter Value: ";
                cin >> val;
                if (!head) {
                    head = new Node(val);
                    head->next = head;
                    head->prev = head;
                } else {
                    head->InsertAtHead(val);
                }
                break;
            case 3:
                cout << "Enter Value: ";
                cin >> val;
                if (head) head->Search(val);
                break;
            case 4:
                int oldVal, newVal;
                cout << "Enter Old Value: ";
                cin >> oldVal;
                cout << "Enter New Value: ";
                cin >> newVal;
                if (head) head->Update(oldVal, newVal);
                break;
            case 5:
                if (head) head->PrintAll();
                break;
            case 6:
                if (head) {
                    cout << "Reverse Print: ";
                    head->PrintReverse();
                }
                break;
            case 7:
                if (head) head->PrintMiddle();
                break;
            case 8:
                if (head) head->DeleteLast();
                break;
            case 9:
                if (head) head->DeleteFirst();
                break;
            case 10:
                cout << "Enter Value: ";
                cin >> val;
                if (head) head->DeleteAtValue(val);
                break;
            case 11:
                if (head) head->DeleteMiddle();
                break;
            case 12:
                if (head) head->DeleteDuplicates();
                break;
            case 0:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
