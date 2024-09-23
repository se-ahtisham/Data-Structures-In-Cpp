#include "MaxHeap.h"
#include <iostream>
using namespace std;

MaxHeap::MaxHeap(int capacity) : capacity(capacity), size(0) {
    heap = new int[capacity];
}

MaxHeap::~MaxHeap() {
    delete[] heap;
}

void MaxHeap::heapifyUp(int index) {
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (heap[index] > heap[parentIndex]) {
            swap(heap[index], heap[parentIndex]);
            index = parentIndex;
        } else {
            break;
        }
    }
}

void MaxHeap::heapifyDown(int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int largest = index;

    if (leftChild < size && heap[leftChild] > heap[largest]) {
        largest = leftChild;
    }
    if (rightChild < size && heap[rightChild] > heap[largest]) {
        largest = rightChild;
    }
    if (largest != index) {
        swap(heap[index], heap[largest]);
        heapifyDown(largest);
    }
}

void MaxHeap::insert(int value) {
    if (size >= capacity) {
        cout << "Heap is full" << endl;
        return;
    }
    heap[size] = value;
    size++;
    heapifyUp(size - 1);
}

int MaxHeap::extractMax() {
    if (size == 0) {
        cout << "Heap is empty" << endl;
        return -1; // Return an invalid value
    }
    int max = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
    return max;
}

void MaxHeap::printHeap(){
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int MaxHeap::search(int value) {
    for (int i = 0; i < size; i++) {
        if (heap[i] == value) {
            return i;
        }
    }
    return -1;
}

void MaxHeap::update(int oldValue, int newValue) {
    int index = search(oldValue);
    if (index == -1) {
        cout << "Value not found in the heap" << endl;
        return;
    }
    heap[index] = newValue;
    if (newValue > oldValue) {
        heapifyUp(index);
    } else {
        heapifyDown(index);
    }
}

void MaxHeap::deleteValue(int value) {
    int index = search(value);
    if (index == -1) {
        cout << "Value not found in the heap" << endl;
        return;
    }
    heap[index] = heap[size - 1];
    size--;
    if (heap[index] > value) {
        heapifyUp(index);
    } else {
        heapifyDown(index);
    }
}
