#include <iostream>
#include "List.h"

using namespace std;

int main() {
    cout << endl;
    cout << "\t\t:::::::::::::::::::::::::::::::::::::::::  " << endl;
    cout << "\t\t::::          Single Linked List       ::::  " << endl;
    cout << "\t\t:::::::::::::::::::::::::::::::::::::::::  " << endl;
    cout << endl;

    List l;
    int mainchoice = 1;
    int choice;
    int val;
    int old;
    int newn;

    while (mainchoice != 0) {
        cout << " 1. Press 1 to Insert At Tail  " << endl;
        cout << " 2. Press 2 to Insert At Head  " << endl;
        cout << " 3. Press 3 to Search  " << endl;
        cout << " 4. Press 4 to Update " << endl;
        cout << " 5. Press 5 to Print All " << endl;
        cout << " 6. Press 6 to Print Reverse All " << endl;
        cout << " 7. Press 7 to Print Middle " << endl;
        cout << " 8. Press 8 to Delete At Last " << endl;
        cout << " 9. Press 9 to Delete At First " << endl;
        cout << " 10. Press 10 to Delete By Value " << endl;
        cout << " 11. Press 11 to Delete By Middle " << endl;
        cout << " 12. Press 12 to Delete Duplicates " << endl;
        cout << endl;
        cout << "Please Enter Your Choice:  ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter Value: ";
                cin >> val;
                l.InsertAtTail(val);
                break;
            case 2:
                cout << "Enter Value: ";
                cin >> val;
                l.InsertAtHead(val);
                break;
            case 3:
                cout << "Enter Value: ";
                cin >> val;
                l.Search(val);
                break;
            case 4:
                cout << "Enter Old Value: ";
                cin >> old;
                cout << "Enter New Value: ";
                cin >> newn;
                l.Update(old, newn);
                break;
            case 5:
                l.PrintAll();
                break;
            case 6:
                cout << "Reverse Print value: ";
                l.PrintReverse(l.getHead());
                cout << endl;
                break;
            case 7:
                l.PrintMiddle();
                break;
            case 8:
                l.DeleteLast();
                break;
            case 9:
                l.DeleteFirst();
                break;
            case 10:
                cout << "Enter Value: ";
                cin >> val;
                l.DeleteAtValue(val);
                break;
            case 11:
                l.DeleteMiddle();
                break;
            case 12:
                l.DeleteDuplicates();
                break;
            default:
                cout << "Error! Invalid Input" << endl;
                break;
        }

        cout << endl;
        cout << " >>> Press 0 to Exit and Any key to Run Again  ";
        cin >> mainchoice;
        cout << endl;
    }

    return 0;
}
