#include "MaxHeap.h"
#include <iostream>
using namespace std;

int main() {
    MaxHeap maxHeap(10);

    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(30);
    maxHeap.insert(40);
    maxHeap.insert(50);

    cout << "Heap elements: ";
    maxHeap.printHeap();

    cout << "Extracted max: " << maxHeap.extractMax() << endl;

    cout << "Heap after extraction: ";
    maxHeap.printHeap();

    int valueToSearch = 30;
    int index = maxHeap.search(valueToSearch);
    if (index != -1) {
        cout << "Value " << valueToSearch << " found at index " << index << endl;
    } else {
        cout << "Value " << valueToSearch << " not found in the heap" << endl;
    }

    maxHeap.update(20, 35);
    cout << "Heap after update: ";
    maxHeap.printHeap();

    maxHeap.deleteValue(35);
    cout << "Heap after delete: ";
    maxHeap.printHeap();

    return 0;
}
