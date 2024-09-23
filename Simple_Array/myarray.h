
#pragma once

using namespace std;

class MyArray
{

private:
    int size;
    int capacity;
    int* arr;

public:
    MyArray();
    void setcapacity(int number);
    int getcapacity();




    void InsertByBeg(int number);
    void InsertByEnd(int number);


    void UpdateByValue(int number);
    void UpdateByIndex(int number);


    void DeleteByValue(int key);
    void DeleteByIndex(int key);


    void SearchByValue(int n);
    void SearchByIndex(int n);

    void Back(int n);
    void Front(int n);

    void Showall();
    void Showindex();


};


