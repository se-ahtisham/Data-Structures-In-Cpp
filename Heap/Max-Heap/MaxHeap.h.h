class MaxHeap {
public:
    int* heap;
    int size;
    int capacity;

    MaxHeap(int capacity);
    ~MaxHeap();
    void heapifyUp(int index);
    void heapifyDown(int index);
    void insert(int value);
    int extractMax();
    void printHeap();
    int search(int value) ;
    void update(int oldValue, int newValue);
    void deleteValue(int value);
};