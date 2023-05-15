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

void Graph::addNode(int newNode) {
  try{
    // Check if newNode is greater than nodeCount
    if(newNode <= nodeCount){
      throw std::invalid_argument("New node must be greater than nodeCount");
    }
    // Allocate memory for new node
    Node *newNode = new Node;
    // Set value of new node to newNode
    newNode->setValue(newNode);
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

Graph Graph::getBFS(int v) {}
int* Graph::getShortestPath(int s, int v) {}

void Graph::printGraph() {}

#endif