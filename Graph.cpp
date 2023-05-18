#ifndef GRAPH_CPP_INCLUDE
#define GRAPH_CPP_INCLUDE

#include "Graph.h"

Node::Node() {
  this->value = -1;
  this->next = nullptr;
}
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
Node* Node::getNext() const { return next; }

void Node::addNode(int val) {
  // Iterate to the last node in adjacency list
  Node *curr = this;
  while(curr->getNext()) {
    curr = curr->getNext();
  }
  // Create new node to append
  Node *newNode;
  try {
    newNode = new Node;
    newNode->setValue(val);
    newNode->setNext(nullptr);
  }
  catch (std::bad_alloc &e) {
    std::cout << e.what() << std::endl;
  }
  // Append new node
  curr->setNext(newNode);
}

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
  this->nodeCount = 0;
  this->edgeCount = 0;
  // Allocate memory for adjacency list
  try {
    this->adj_list = new Node*;
  }
  catch (std::bad_alloc &e) {
    std::cout << e.what() << std::endl;
  }
}

Graph::Graph(int size) {
  try {
    if (size <= 0) {
      throw std::invalid_argument("Graph size must be >= 1");
    }

    this->nodeCount =  size;
    this->edgeCount = 0;
    // Allocate memory for adjacency list
    this->adj_list = new Node*[size];
  }
  catch (std::invalid_argument &e) {
    std::cout << e.what() << std::endl;
  }
  catch (std::bad_alloc &e) {
    std::cout << e.what() << std::endl;
  }
  // Add size nodes to adjacency list
  for (int i = 0; i < size; i++) {
    Node *curr = new Node;
    curr->setValue(i);
    curr->setNext(nullptr);
    this->adj_list[i] = curr;
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
  try {
    this->adj_list = new Node*;
  }
  catch (std::bad_alloc &e) {
    std::cout << e.what() << std::endl;
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
  try {
    this->adj_list = new Node*;
  }
  catch (std::bad_alloc &e) {
    std::cout << e.what() << std::endl;
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
/*
void Graph::addNode(int newNodeVal) {
  try{
    // Check if newNode is greater than nodeCount
    if(newNodeVal >= nodeCount){
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
*/
void Graph::addEdge(int u, int v) {
  try {
    // if u and v are are greater than nodeCount valid node indexes
    if (u >= nodeCount || v >= nodeCount || u < 0 || v < 0) {
      throw std::invalid_argument("Invalid node indexes");
    }

    //the end of the adjacency list for node u
    Node* curr = adj_list[u];
    while (curr->getNext()) {
      curr = curr->getNext();
    }

    // Create a new node for node v and append it to the end of the adjacency
    // list for node u
    Node* newNode = new Node;
    newNode->setValue(v);
    newNode->setNext(nullptr);
    curr->setNext(newNode);
    // Increment the edge count
    edgeCount++;
/*  *** Implementation for undirected graph ***
    // Add an edge from v to u by finding the end of the adjacency list for node v
    curr = adj_list[v];
    while (curr->getNext()) {
      curr = curr->getNext();
    }

    // Create a new node for node u and append it to the end of the adjacency
    // list for node v
    newNode = new Node;
    newNode->setValue(u);
    newNode->setNext(nullptr);
    curr->setNext(newNode);
*/
    //Catch invalid argument
  } catch (std::invalid_argument& e) {
    std::cout << e.what() << std::endl;
    //Catch bad alloc
  } catch (std::bad_alloc& e) {
    std::cout << e.what() << std::endl;
    //Catch unknown error
  } catch (...) {
    std::cout << "Unknown error" << std::endl;
  }
}

Graph Graph::getBFS(int v)
{
  Graph bfsGraph(this->nodeCount);                   // create a new graph for BFS traversal
  std::vector<bool> visited(this->nodeCount, false); // keep track of visited nodes
  std::queue<int> q;                                 // queue for BFS traversal

  visited[v] = true; // mark the starting node as visited
  q.push(v);         // enqueue the starting node

  while (!q.empty()) // while queue is not empty
  {
    int nodeIndex = q.front();        // get the front element of the queue
    q.pop();                          // remove the front element from the queue
    Node *node = adj_list[nodeIndex]; // get the actual node from the adjacency list

    Node *curr = node; // pointer to traverse the adjacency list of the current node

    while (curr != nullptr)
    {
      int neighbor = curr->getValue(); // get the value of the neighbor node

      if (!visited[neighbor])
      {
        visited[neighbor] = true;              // mark the neighbor as visited
        q.push(neighbor);                      // enqueue the neighbor
        bfsGraph.addEdge(nodeIndex, neighbor); // add an edge to the BFS graph
      }

      curr = curr->getNext(); // move to the next neighbor
    }
  }
  // Print BFS tree (Graph)
  bfsGraph.printGraph();

  return bfsGraph;
}

Node* Graph::getShortestPath(int s, int v) {
  std::vector<bool> visited(this->nodeCount, false); // keep track of visited nodes
  std::vector<int> parent(this->nodeCount, -1); // keep track of parent nodes in the shortest path
  std::queue<int> q; // queue for BFS traversal

  visited[s] = true; // mark the starting node as visited
  q.push(s); // enqueue the starting node

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    Node* currentNode = this->adj_list[node]->getNext();
    while (currentNode != nullptr) {
      int neighbor = currentNode->getValue();
      if (!visited[neighbor]) {
        visited[neighbor] = true;
        parent[neighbor] = node;
        q.push(neighbor);
        if (neighbor == v)
          break; // stop BFS if the destination node is found
      }
      currentNode = currentNode->getNext();
    }
  }

  // Check if there is a path from s to v
  if (parent[v] == -1) {
    std::cout << "No path from " << s << " to " << v << " exists." << std::endl;
    return nullptr;
  }

  // Check if the destination is the starting node
  if (s == v) {
    Node* path = new Node;
    path->setValue(v);
    return path;
  }

  // Build the shortest path from s to v
  Node* path = nullptr;
  int current = v;
  while (current != -1) {
    Node* newNode = new Node;
    newNode->setValue(current);
    newNode->setNext(path);
    path = newNode;
    current = parent[current];
  }

  // Print the shortest path
  path->printList();

  return path;
}


int Graph::getNodeCount() const { return this->nodeCount; }
int Graph::getEdgeCount() const { return this->edgeCount; }

void Graph::printGraph() {
  for (int i = 0; i < this->nodeCount; i++) {
    this->adj_list[i]->printList();
  }
}

#endif