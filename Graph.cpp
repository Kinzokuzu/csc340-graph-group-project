#ifndef GRAPH_CPP_INCLUDE
#define GRAPH_CPP_INCLUDE

#include "Graph.h"

Node::Node() {}
// Assignment only copies fields and not addresses
Node& Node::operator=(const Node &rhs) {
  // Don't allow self assignment
  if (this == &rhs) {
    return *this;
  }

  this->value = rhs.value;
  if (rhs.next) {
    // Allocate memory to get a different address for next
    Node *nextNode;
    try {
      nextNode = new Node;
    } catch (std::bad_alloc &e) {
      std::cout << e.what() << std::endl;
    }
    // Recursively assign fields of nextNode
    nextNode = rhs.next;
    this->next = nextNode;
  } else {
    this->next = nullptr;
  }

  return *this;
}

bool Node::isEqual(const Node &comp) {
  bool result = true;
  // Check address
  if (this == &comp) {
    return result;
  }
  // Check values
  if (this->value != comp.value)
    result = false;
  // Recursively check subsequent nodes
  if (this->next && comp.next && result) {
    result = this->next->isEqual(*comp.next);
  } else {
    result = false;
  }

  return result;
}

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
