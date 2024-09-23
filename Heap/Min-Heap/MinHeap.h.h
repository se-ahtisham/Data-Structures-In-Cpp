class MinHeap {
public:
    int* heap;
    int size;
    int capacity;

    MinHeap(int capacity);
    ~MinHeap();
    void heapifyUp(int index);
    void heapifyDown(int index);
    void insert(int value);
    int extractMin();
    void printHeap();
    int search(int value);
    void update(int oldValue, int newValue);
    void deleteValue(int value);
};