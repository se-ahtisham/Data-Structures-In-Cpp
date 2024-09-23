#include "Node.h"
#include <iostream>
#include <climits>

class Graph {
    int V;
    Node** adjList;

public:
    Graph(int V);
    ~Graph();
    void addEdge(int u, int v, int weight);
    void printGraph() const;
    void dijkstra(int src);

private:
    Node* createNode(int v, int weight, Node* head);
    int minDistance(int dist[], bool visited[]);
};