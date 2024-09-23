
#include"Queue.h"


Queue::Queue() :top(-1), back(-1), capacity(5),count(0)
{
	arr = new int[capacity];
}

Queue::~Queue()

{
	delete[] arr;
}


bool Queue::Isfull()
{
	return(count == capacity) ? true : false;
}

bool Queue::IsEmpty()
{
	return (count == 0) ? true : false;
}

void Queue::enqueue(int element)
{
	if (IsEmpty())
	{
		top = 0;
		back = 0;
		arr[back] = element;
		count++;	
	}
	else if(!Isfull())
	{
		back++;
		arr[back] = element;
		count ++;
	}
	else
	{
		cout << "Queue is Full" << endl;
	}

}
void Queue::dequeue()
{
	if (!IsEmpty())
	{
		cout << arr[top];
		top++;
		count--;
	}

	else
	{
		cout << "Queue is Empty" << endl;
	}


}


void Queue::printtop()
{
	if (!IsEmpty())
	{
		cout << arr[top];
	}
	else
	{
		cout << "Queue is empty" << endl;
	}
}
