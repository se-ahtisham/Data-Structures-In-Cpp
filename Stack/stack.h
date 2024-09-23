#pragma once
#include <iostream>
using namespace std;
class MyStack
{
public:
	MyStack(int capacity);
	~MyStack();

	void Push(int element);
	void Pop();
	void Peak();
	bool isEmpty();
	bool isFull();
private:
	int top;
	int cap;
	int* arr;
};

