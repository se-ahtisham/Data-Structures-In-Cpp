
#include <iostream>
#include <string>
#include "myarray.h"
using namespace std;



MyArray::MyArray()
{
    capacity = 0;
    size = 0;
    arr = new int[capacity];
}

void MyArray::setcapacity(int number)
{
    capacity = number;
}
int MyArray::getcapacity()
{
    return capacity;
}



// Insert Functions
void MyArray::InsertByBeg(int num)
{
    int top = size - 1;
    if (size < capacity)
    {
        if (size == 0)
        {
            arr[size] = num;
            size++;
            cout << "Number Stored Successfully :)";
            cout << endl;
        }
        else if (size > 0)
        {
            for (int i = size; i > 0; i--)
             {
                arr[i] = arr[top];
                top--;
            }
            arr[0] = num;
            size++;
            cout << "Number Stored Successfully :)";
            cout << endl;
        }
    }
    else
    {
        cout << endl;
        cout << "Capacity Full" << endl;
    }
}
void MyArray::InsertByEnd(int number)
{
    if (size < capacity)
    {
        arr[size] = number;
        size++;
        cout << "Number Stored Successfully :)";
        cout << endl;
    }
    else
    {
        cout << endl;
        cout << "Capacity Full" << endl;
    }
}


// Update Functions
void MyArray::UpdateByValue(int n)
{
    int flag = 0;
    int rem;
    int choice;
    int newnumber;
    for (int i = 0; i < size; i++)
    {

        if (arr[i] == n)
        {
            cout << "Found" << endl;
            rem = arr[i];
            cout << endl;
            cout << "Do you want to updated this? " << endl;
            cout << "Press 1 for YES and 2 for NO: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                // if yes then

                cout << endl;
                cout << "Please Enter new Number: ";
                cin >> newnumber;
                arr[i] = newnumber;
                cout << endl;
                cout << "SuccessFully Upadted:)" << endl;
                cout << "Old number was: " << rem << endl;
                cout << "New number is: " << arr[i] << endl;
            }
            break;
            case 2:
            {
                cout << endl;
                cout << "Command Cancel" << endl;
                 break;
            }
            break;

            default:
            {
                cout << endl;
                cout << "Wronge input" << endl;
            }
            break;
            }

            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {

        cout << "Not Found ";
        cout << endl;
    }
}
void MyArray::UpdateByIndex(int n)
{
    int flag = 0;
    int rem;
    int choice;
    int newnumber;
    for (int i = 0; i < capacity; i++)
    {

        if (i == n)
        {
            cout << "Found" << endl;
            rem = arr[i];
            cout << endl;
            cout << "Do you want to updated this? " << endl;
            cout << "Press 1 for YES and 2 for NO: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                // if yes then

                cout << endl;
                cout << "Please Enter new Number: ";
                cin >> newnumber;
                arr[i] = newnumber;
                cout << endl;
                cout << "SuccessFully Upadted:)" << endl;
                cout << "Old number was: " << rem << endl;
                cout << "New number is: " << arr[i] << endl;
            }
            break;
            case 2:
            {
                cout << endl;
                cout << "Command Cancel" << endl;
                break;
            }
            break;

            default:
            {
                cout << endl;
                cout << "Wronge input" << endl;
            }
            break;
            }

            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {

        cout << "Not Found ";
        cout << endl;
    }
}


// Delete Functions
void MyArray::DeleteByValue(int key)
{
    int flag = 0;
    int rem;
    int choice;
    int newnumber, position;
    for (int i = 0; i < size; i++)
    {

        if (arr[i] == key)
        {
            cout << "Found" << endl;
            rem = arr[i];
            cout << endl;
            cout << "Do you want to Delete this? " << endl;
            cout << "Press 1 for YES and 2 for NO: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                // if yes then
                position = i;
                for (int j = position; j < capacity - 1; j++)
                {
                    arr[j] = arr[j + 1];
                }
                size--;
            }
            cout << "SuccessFully Deleted:)" << endl;
            break;

            case 2:
            {
                cout << endl;
                cout << "Command Cancel" << endl;
                break;
            }

            default:
            {
                cout << endl;
                cout << "Wronge input" << endl;
                break;
            }
            }

            flag = 1;
            break;
        }
    }

    if (flag == 0)
    {

        cout << "Not Found ";
        cout << endl;
    }
}
void MyArray::DeleteByIndex(int key)
{
    int flag = 0;
    int choice;
    int newnumber, position;
    for (int i = 0; i < capacity; i++)
    {

        if (i == key)
        {
            cout << "Found" << endl;
            cout << endl;
            cout << "Do you want to Delete this? " << endl;
            cout << "Press 1 for YES and 2 for NO: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                // if yes then
                position = i;
                for (int j = position; j < size - 1; j++)
                {
                    arr[j] = arr[j + 1];
                }
                size--;
            }
            cout << "SuccessFully Deleted:)" << endl;
            break;

            case 2:
            {
                cout << endl;
                cout << "Command Cancel" << endl;
                break;
            }

            default:
            {
                cout << endl;
                cout << "Wronge input" << endl;
                break;
            }
            }

            flag = 1;
            break;
        }
    }

    if (flag == 0)
    {

        cout << "Not Found ";
        cout << endl;
    }
}




// Search Functions
void MyArray::SearchByValue(int n)
{
    int flag = 0;
    for (int i = 0; i < size; i++)
    {

        if (arr[i] == n)
        {
            cout << "Found" << endl;
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {

        cout << "Not Found ";
        cout << endl;
    }
}
void MyArray::SearchByIndex(int n)
{
    int flag = 0;
    for (int i = 0; i < capacity; i++)
    {

        if (i == n)
        {
            cout << "Found" << endl;
            cout << arr[i] << endl;
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {

        cout << "Not Found ";
        cout << endl;
    }
}



// Show Functions
void MyArray::Showall()
{

    cout << endl;
    if (size == 0)
    {
        cout << "No Value Enter By user " << endl;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {

            cout << " The " << i + 1 << " Number is: " << arr[i] << endl;
        }
    }
}
void MyArray::Showindex()
{
    cout << endl;
    cout << "The Current Capacity is: " << capacity << endl;
    cout << "The Current Size is: " << size << endl;
    if (size == 0)
    {
        cout << "The Current Index is: " << size << endl;
    }
    else
    {

        cout << "The Current Index is: " << size - 1 << endl;
    }
}


void MyArray::Back(int n)
{


    if (n == 0)
    {
        cout << "Enter Location is Equal to First location" << endl;
    }

    else if (n < 0)
    {
        cout << "Enter Location is Less than First location" << endl;
    }
    else if (n > 0)
    {

        cout << "Enter Location is greater than First location" << endl;
        cout << ">> You Can enter Data " << endl;

    }
}



void MyArray::Front(int n)
{

    if (n > capacity)
    {
        cout << "Enter Location is Beyond the size of Array" << endl;
    }
    else
    {

        cout << "Enter Location is not Beyond the size of Array" << endl;
        cout << ">> You Can enter Data " << endl;

    }

}