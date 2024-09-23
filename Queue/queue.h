#pragma once
#include<iostream>
using namespace std;

class Queue
{
public:
	Queue();
	~Queue();

	bool Isfull();
	bool IsEmpty();
	void enqueue(int element);
	void dequeue();
	void printtop();

private:
	int top;
	int back;
	int capacity;
	int* arr;
	int count;

};

