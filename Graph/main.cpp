#include "Graph.h"

int main() {
    int V = 5;

    Graph graph(V);

    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 4, 1);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 5);
    graph.addEdge(1, 4, 2);
    graph.addEdge(2, 3, 1);
    graph.addEdge(3, 4, 7);

    graph.printGraph();
    graph.dijkstra(0);

    return 0;
}
