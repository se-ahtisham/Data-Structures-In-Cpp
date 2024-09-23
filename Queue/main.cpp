#include"Queue.h"

int main()
{
	Queue q;
	q.enqueue(10);
	q.enqueue(20);
	q.dequeue();
	cout << endl;
	q.dequeue();


	return 0;
}