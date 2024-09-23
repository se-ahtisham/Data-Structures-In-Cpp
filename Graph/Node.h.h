class Node {
public:
    int vertex;
    int weight;
    Node* next;

    Node(int v, int w, Node* n = nullptr);
    int getVertex();
    int getWeight() ;
    Node* getNext() ;
};