#include "MinHeap.h"
#include <iostream>
using namespace std;

MinHeap::MinHeap(int capacity) : capacity(capacity), size(0) {
    heap = new int[capacity];
}

MinHeap::~MinHeap() {
    delete[] heap;
}

void MinHeap::heapifyUp(int index) {
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (heap[index] < heap[parentIndex]) {
            swap(heap[index], heap[parentIndex]);
            index = parentIndex;
        } else {
            break;
        }
    }
}

void MinHeap::heapifyDown(int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallest = index;

    if (leftChild < size && heap[leftChild] < heap[smallest]) {
        smallest = leftChild;
    }
    if (rightChild < size && heap[rightChild] < heap[smallest]) {
        smallest = rightChild;
    }
    if (smallest != index) {
        swap(heap[index], heap[smallest]);
        heapifyDown(smallest);
    }
}

void MinHeap::insert(int value) {
    if (size >= capacity) {
        cout << "Heap is full" << endl;
        return;
    }
    heap[size] = value;
    size++;
    heapifyUp(size - 1);
}

int MinHeap::extractMin() {
    if (size == 0) {
        cout << "Heap is empty" << endl;
        return -1; // Return an invalid value
    }
    int min = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
    return min;
}

void MinHeap::printHeap(){
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int MinHeap::search(int value) {
    for (int i = 0; i < size; i++) {
        if (heap[i] == value) {
            return i;
        }
    }
    return -1;
}

void MinHeap::update(int oldValue, int newValue) {
    int index = search(oldValue);
    if (index == -1) {
        cout << "Value not found in the heap" << endl;
        return;
    }
    heap[index] = newValue;
    if (newValue < oldValue) {
        heapifyUp(index);
    } else {
        heapifyDown(index);
    }
}

void MinHeap::deleteValue(int value) {
    int index = search(value);
    if (index == -1) {
        cout << "Value not found in the heap" << endl;
        return;
    }
    heap[index] = heap[size - 1];
    size--;
    if (heap[index] < value) {
        heapifyUp(index);
    } else {
        heapifyDown(index);
    }
}
