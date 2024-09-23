#include "MinHeap.h"
#include <iostream>
using namespace std;

int main() {
    MinHeap minHeap(10);

    minHeap.insert(10);
    minHeap.insert(20);
    minHeap.insert(30);
    minHeap.insert(40);
    minHeap.insert(50);

    cout << "Heap elements: ";
    minHeap.printHeap();

    cout << "Extracted min: " << minHeap.extractMin() << endl;

    cout << "Heap after extraction: ";
    minHeap.printHeap();

    int valueToSearch = 30;
    int index = minHeap.search(valueToSearch);
    if (index != -1) {
        cout << "Value " << valueToSearch << " found at index " << index << endl;
    } else {
        cout << "Value " << valueToSearch << " not found in the heap" << endl;
    }

    minHeap.update(20, 5);
    cout << "Heap after update: ";
    minHeap.printHeap();

    minHeap.deleteValue(5);
    cout << "Heap after delete: ";
    minHeap.printHeap();

    return 0;
}
