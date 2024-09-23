#include "Graph.h"

Graph::Graph(int V) {
    this->V = V;
    adjList = new Node*[V];
    for (int i = 0; i < V; ++i) {
        adjList[i] = nullptr;
    }
}

Graph::~Graph() {
    for (int i = 0; i < V; ++i) {
        Node* temp = adjList[i];
        while (temp != nullptr) {
            Node* next = temp->getNext();
            delete temp;
            temp = next;
        }
    }
    delete[] adjList;
}

Node* Graph::createNode(int v, int weight, Node* head) {
    return new Node(v, weight, head);
}

void Graph::addEdge(int u, int v, int weight) {
    adjList[u] = createNode(v, weight, adjList[u]);
    adjList[v] = createNode(u, weight, adjList[v]);
}

void Graph::printGraph(){
    for (int i = 0; i < V; ++i) {
        Node* temp = adjList[i];
        std::cout << "Adjacency list of vertex " << i << ": ";
        while (temp != nullptr) {
            std::cout << "(" << temp->getVertex() << ", weight: " << temp->getWeight() << ") ";
            temp = temp->getNext();
        }
        std::cout << std::endl;
    }
}

int Graph::minDistance(int dist[], bool visited[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (!visited[v] && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void Graph::dijkstra(int src) {
    int* dist = new int[V];
    bool* visited = new bool[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = true;

        Node* temp = adjList[u];
        while (temp != nullptr) {
            int v = temp->getVertex();
            int weight = temp->getWeight();

            if (!visited[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
            temp = temp->getNext();
        }
    }

    std::cout << "Vertex \t\t Distance from Source " << src << std::endl;
    for (int i = 0; i < V; i++) {
        std::cout << i << " \t\t " << dist[i] << std::endl;
    }

    delete[] dist;
    delete[] visited;
}
