

#include"stack.h"


MyStack::MyStack(int capacity) : top(-1), cap(capacity)
{
	arr = new int[cap];
}

MyStack::~MyStack()
{
	delete[] arr;
}
void MyStack::Push(int element) {
	if (!isFull()) {
		arr[++top] = element;
	}
	else {
		cout << "Stack is Full" << endl;
	}
}

void MyStack::Pop() {
	if (!isEmpty()) {
		cout << arr[top--] << endl;
	}
	else {
		cout << "Stack is Empty";
	}
}

void MyStack::Peak() {
	if (!isEmpty()) {
		cout << arr[top] << endl;
	}
	else {
		cout << "Stack is Empty";
	}
}

bool MyStack::isEmpty() {
	if (top == -1) {
		return true;
	}
	else {
		return false;
	}
}
bool MyStack::isFull() {
	if (top >= cap) {
		return true;
	}
	else
		return false;
}

int main() {
	MyStack s1(5);
	s1.Push(10);
	s1.Push(20);
	s1.Push(30);
	s1.Push(40);
	s1.Push(50);
	cout << "Peak Elemnt" << endl;
	s1.Peak();
	cout << "Poped element" << endl;
	s1.Pop();
	s1.Pop();
	system("pause");
	return 0;
}