#include "Node.h"

Node::Node(int v, int w, Node* n) : vertex(v), weight(w), next(n) {}

int Node::getVertex()  {
    return vertex;
}

int Node::getWeight() {
    return weight;
}

Node* Node::getNext() {
    return next;
}
