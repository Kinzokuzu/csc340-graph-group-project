#ifndef TREE_CPP_INCLUDE
#define TREE_CPP_INCLUDE

#include "Tree.h"

Tree::Tree() {
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

Tree::Tree(int size) {
  try {
    if (size <= 0) {
      throw std::invalid_argument("Graph size must be >= 1");
    }

    this->nodeCount = size;
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
    // This code was commented out because we don't want to give our Node fields
    // values.
    //curr->setValue(i);
    //curr->setNext(nullptr);
    this->adj_list[i] = curr;
  }
}
// Big-3
Tree::~Tree() {
  if (this->adj_list) {
    delete [] this->adj_list;
    this->adj_list = nullptr;
  }
}

Tree::Tree(const Tree &clone) {
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

Tree& Tree::operator=(const Tree &rhs) {
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

bool Tree::isEqual(const Tree &comp) {
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

void Tree::addEdge(int u, int v) {
  try {
    // if u and v are are greater than nodeCount valid node indexes
    if (u >= nodeCount || v >= nodeCount || u < 0 || v < 0) {
      throw std::invalid_argument("Invalid node indexes");
    }
    // Check if u exists
    bool u_exists = false;
    for (int pos= 0; pos < this->nodeCount && !u_exists; pos++) {
      if (adj_list[pos]->getValue() == u) {
        // Add v to u
        adj_list[pos]->addNode(v);
        u_exists = true;
      }
    }
    // If u doesn't exist, add u in the next available position
    for (int pos = 0; pos < this->nodeCount && !u_exists; pos++) {
      // Look for first available default node
      if (adj_list[pos]->getValue() == -1) {
        // Create u
        adj_list[pos]->setValue(u);
        u_exists = true;
        // Add v to u
        adj_list[pos]->addNode(v);
      }
    }

    // Increment the edge count
    edgeCount++;
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

int Tree::getNodeCount() const { return this->nodeCount; }
int Tree::getEdgeCount() const { return this->edgeCount; }

void Tree::printTree() {
  for (int i = 0; i < this->nodeCount; i++) {
    if (this->adj_list[i]->getNext()) {
      this->adj_list[i]->printList();
    }
  }
}
// End class Tree
#endif