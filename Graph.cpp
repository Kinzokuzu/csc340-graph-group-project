#ifndef GRAPH_CPP_INCLUDE
#define GRAPH_CPP_INCLUDE

#include "Graph.h"

Node::Node() {/* Does nothing */}
// Assignment only copies fields and not addresses
Node& Node::operator=(const Node &rhs) {
  // Don't allow self assignment
  if (this == &rhs) {
    return *this;
  }

  this->value = rhs.value;
  if (rhs.next) {
    // Recursively assign fields of nextNode
    Node *nextNode = rhs.next;
    this->next = nextNode;
  }
  else {
    this->next = nullptr;
  }

  return *this;
}

bool Node::isEqual(const Node &comp) {
  // Compare addresses
  if (this == &comp)
    return true;

  bool result = true;
  // Compare values
  if (this->value != comp.value)
    result = false;
  // Recursively compare subsequent nodes
  if (this->next && comp.next && result) {
    result = this->next->isEqual(*comp.next);
  } // this->next XOR comp.next
  else if ((!this->next && comp.next) || (this->next && !comp.next)) {
    result = false;
  }

  return result;
}

void Node::setValue(int val) { this->value = val; }
int Node::getValue() const { return value; }

void Node::setNext(Node *n) { this->next = n; }
Node* Node::getNext() { return next; }

void Node::printList() {
  Node *curr = this;
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

Graph::Graph() {
  this->nodeCount = 1;
  this->edgeCount = 0;
  // Allocate memory for adjacency list
  try {
    this->adj_list = new Node*;
  }
  catch (std::bad_alloc &e) {
    std::cout << e.what() << std::endl;
  }
  // Create initNode outside first try's scope
  Node *initNode;
  try {
    initNode = new Node;
  }
  catch (std::bad_alloc &e) {
    std::cout << e.what() << std::endl;
  }
  initNode->setValue(0);
  initNode->setNext(nullptr);

  adj_list[0] = initNode;
}
Graph::Graph(int size) {
  try {
    if (size <= 0) {
      throw std::invalid_argument("Graph size must be >= 1");
    }

    this->nodeCount =  size;
    this->edgeCount = 0;
    // Allocate memory for adjacency list
    this->adj_list = new Node*;
    adj_list = nullptr;
  }
  catch (std::invalid_argument &e) {
    std::cout << e.what() << std::endl;
  }
  catch (std::bad_alloc &e) {
    std::cout << e.what() << std::endl;
  }
  // Add size nodes to adjacency list
  for (int i = 0; i < size; i++) {
    this->addNode(i);
  }
}
// Big-3
Graph::~Graph() {
  if (this->adj_list) {
    delete [] this->adj_list;
    this->adj_list = nullptr;
  }
}

Graph::Graph(const Graph &clone) {
  this->nodeCount = clone.nodeCount;
  this->edgeCount = clone.edgeCount;
  // Allocate memory to this->adj_list
  if (!this->adj_list) {
    this->adj_list = new Node*;
  }
  // Copy all nodes/node lists from rhs to this
  for (int i = 0; i < clone.nodeCount; i++) {
    this->adj_list[i] = clone.adj_list[i];
  }
}

Graph& Graph::operator=(const Graph &rhs) {
  // Don't allow self assignment
  if (this == &rhs) {
    return *this;
  }

  this->nodeCount = rhs.nodeCount;
  this->edgeCount = rhs.edgeCount;
  // Allocate memory to this->adj_list
  if (!this->adj_list) {
    this->adj_list = new Node*;
  }
  // Copy all nodes/node lists from rhs to this
  for (int i = 0; i < rhs.nodeCount; i++) {
    this->adj_list[i] = rhs.adj_list[i];
  }

  return *this;
}

bool Graph::isEqual(const Graph &comp) {
  // Compare address
  if (this == &comp)
    return true;

  bool result = true;
  // Compare nodeCount, edgeCount
  if (this->nodeCount != comp.nodeCount)
    result = false;
  if (this->edgeCount!= comp.edgeCount)
    result = false;
  // Compare adjacency lists
  for (int i = 0; result && i < comp.nodeCount; i++) {
    result = this->adj_list[i]->isEqual(*comp.adj_list[i]);
  }

  return result;
}

void Graph::addNode(int newNode) {}
void Graph::addEdge(int u, int v) {}

Graph Graph::getBFS(int v) {}
Node* Graph::getShortestPath(int s, int v) {}

int Graph::getNodeCount() const { return this->nodeCount; }
int Graph::getEdgeCount() const { return this->edgeCount; }

void Graph::printGraph() {}

#endif
