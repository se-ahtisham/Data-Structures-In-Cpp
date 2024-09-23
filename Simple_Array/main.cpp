
#include <iostream>
#include "myarray.h"


using namespace std;

int main()
{

    cout << endl;
    int capacity;
    cout << "Please Enter Array Capacity: ";
    cin >> capacity;
    MyArray* a;

    cout << endl;
    cout << ">>>> Welcome to Menu <<<<" << endl;
    cout << endl;
    a->setcapacity(capacity);
    a->getcapacity();

    int main_Choice = 1;
    while (main_Choice != 0)
    {

        int choice, number, key;

        cout << "<<< For insertion >>>" << endl;
        cout << "Press 1 to Insert by END (Simple) " << endl;
        cout << "Press 2 to Insert by Beginning (Shifting) " << endl;
        cout << endl;

        cout << "<<< For Search >>>" << endl;
        cout << "Press 3 to Linear Search By Value" << endl;
        cout << "Press 4 to Linear Search By Index" << endl;
        cout << endl;

        cout << "<<< For Update >>>" << endl;
        cout << "Press 5 to Update By Value" << endl;
        cout << "Press 6 to Update By Index" << endl;
        cout << endl;

        cout << "<<< For Delete >>>" << endl;
        cout << "Press 7 to Delete by Number" << endl;
        cout << "Press 8 to Delete by Index" << endl;
        cout << endl;

        cout << "<<< For Show data >>>" << endl;
        cout << "Press 9 to show current size,index and capacity" << endl;
        cout << "Press 10 to show All data" << endl;
        cout << endl;

        cout << "<<< For Back and Fornt >>>" << endl;
        cout << "Press 11 to Check Front:" << endl;
        cout << "Press 12 to Check Back:" << endl;
        cout << endl;

        cout << "Enter Your choice >>>>  ";
        cin >> choice;
        switch (choice)
        {


        case 1: // Insert by end (Simple)
        {

            cout << endl;
            cout << "Enter Number ";
            cin >> number;
            a->InsertByEnd(number);
            break;
        }
        case 2: // Insert by Begining (Shifting)
        {
            cout << endl;
            cout << "Enter Number ";
            cin >> number;
            a->InsertByBeg(number);
            break;
        }


        case 3: // Linear Search by value
        {

            cout << endl;
            cout << "Enter Number ";
            cin >> number;
            a->SearchByValue(number);

            break;
        }
        case 4: // Linear Search by Index
        {
            cout << endl;
            cout << "Enter Index ";
            cin >> number;
            a->SearchByIndex(number);
            break;
        }


        case 5: //  Update by value
        {

            cout << endl;
            cout << "Enter Number you want to Update: ";
            cin >> number;
            a->UpdateByValue(number);
            break;
        }
        case 6: //  Update by index
        {

            cout << endl;
            cout << "Enter Index you want to Update: ";
            cin >> number;
            a->UpdateByIndex(number);
            break;
        }


        case 7: // Delete by value
        {
            cout << endl;
            cout << "Enter Number You want to Delete: ";
            cin >> key;
            a->DeleteByValue(key);
            break;
        }
        case 8: //  Delete by Index
        {
            cout << endl;
            cout << "Enter Index You want to Delete: ";
            cin >> key;
            a->DeleteByIndex(key);

            break;
        }


        case 9: // Show current size,index and capacity
        {

            a->Showindex();
            break;
        }

        case 10: //  show All data
        {
            a->Showall();
            break;
        }


        case 11:
        {
            cout << endl;
            cout << "Enter Location: ";
            cin >> number;
            a->Front(number);
            break;
        }


        case 12:
        {
            cout << endl;
            cout << "Enter Location: ";
            cin >> number;
            a->Back(number);
            break;

            break;
        }




        default:
        {

            cout << endl;
            cout << "Wronge input" << endl;
            break;
        }
        }

        cout << endl;
        cout << "Press Any Key to Continous Or 0 to exit >>";
        cin >> main_Choice;
    }

    return 0;
}
