#ifndef GRAPH_CPP_INCLUDE
#define GRAPH_CPP_INCLUDE

#include "Graph.h"
#include <vector>
#include <queue>

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

void Graph::addNode(int newNodeVal) {
  try{
    // Check if newNode is greater than nodeCount
    if(newNodeVal <= nodeCount){
      throw std::invalid_argument("New node must be greater than nodeCount");
    }
    // Allocate memory for new node
    Node *newNode = new Node;
    // Set value of new node to newNode
    newNode->setValue(newNodeVal);
    // Set next of new node to nullptr because it is at the end of the list
    newNode->setNext(nullptr);
    // Add new node to adj_list, this should always be right because if the node count is 0 then the new node will be at index 0 and then it will increment to 1 and so on
    adj_list[nodeCount] = newNode;
    // Increment nodeCount
    nodeCount++;
  }
  //Catch invalid argument
  catch(std::invalid_argument &e){
    std::cout << e.what() << std::endl;
  }
  //Catch bad alloc
  catch(std::bad_alloc &e){
    std::cout << e.what() << std::endl;
  }
  //Catch unknown error
  catch(...){
    std::cout << "Unknown error" << std::endl;
  }
}

void Graph::addEdge(int u, int v) {
    try{
    // Check if u and v are valid node indexes
    if(u >= nodeCount || v >= nodeCount || u < 0 || v < 0){
      throw std::invalid_argument("Invalid node indexes");
    }
    // Find the end of the adjacency list for node u
    Node *curr = adj_list[u];
    while(curr->getNext()){
      curr = curr->getNext();
    }
    // Create a new node for node v
    Node *newNode = new Node;
    newNode->setValue(v);
    newNode->setNext(nullptr);
    // Append the new node to the end of the adjacency list for node u
    curr->setNext(newNode);
  }
  catch(std::invalid_argument &e){
    std::cout << e.what() << std::endl;
  }
  catch(std::bad_alloc &e){
    std::cout << e.what() << std::endl;
  }
  catch(...){
    std::cout << "Unknown error" << std::endl;
  }
}

Graph Graph::getBFS(int v)
{
    Graph bfsGraph(size);                   // create a new graph for BFS traversal
    std::vector<bool> visited(size, false); // keep track of visited nodes
    std::queue<int> q;                      // queue for BFS traversal

    visited[v] = true; // mark the starting node as visited
    q.push(v);         // enqueue the starting node

    while (!q.empty()) // while queue is not empty
    {
        int node = q.front(); // get the front element of the queue
        q.pop();              // remove the front element from the queue

        for (int i = 0; i < size; i++)
        {
            if (adj_list[node][i] == 1 && !visited[i])
            {
                visited[i] = true;         // mark the neighbor as visited
                q.push(i);                 // enqueue the neighbor
                bfsGraph.addEdge(node, i); // add an edge to the BFS graph
            }
        }
    }

    return bfsGraph;
}

int *Graph::getShortestPath(int s, int v) {}

int Graph::getNodeCount() const { return this->nodeCount; }
int Graph::getEdgeCount() const { return this->edgeCount; }

void Graph::printGraph() {}

#endif