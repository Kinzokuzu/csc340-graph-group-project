#ifndef GRAPH_CPP_INCLUDE
#define GRAPH_CPP_INCLUDE

#include "Graph.h"

void Node::setValue(int val) { this->value = val; }
int Node::getValue() { return value; }

void Node::setNext(Node *n) { this->next = n; }
Node* Node::getNext() { return next; }

void Node::printList() {
  Node *curr;
  try {
    curr = new Node;
  } catch (std::bad_alloc &e) {
    std::cout << e.what() << std::endl;
  }
  // Set curr to head (this)
  curr = this;
  // Print out head
  std::cout << curr->getValue();
  // Set the current node equal to the next node
  curr = curr->getNext();
  // Print out following nodes
  while (curr) {
    std::cout << " -> " << curr->getValue();
    curr = curr->getNext();
  }
  std::cout << std::endl;
}

Graph::Graph() {}
Graph::Graph(int s) {}
// Big-3
Graph::~Graph() {}
Graph::Graph(const Graph &clone) {}
Graph Graph::operator=(const Graph &rhs) {}

void Graph::addNode(int newNode) {}
void Graph::addEdge(int u, int v) {}

Graph Graph::getBFS(int v) {}
int* Graph::getShortestPath(int s, int v) {}

void Graph::printGraph() {}

#endif
