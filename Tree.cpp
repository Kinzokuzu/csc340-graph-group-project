#ifndef TREE_CPP_INCLUDE
#define TREE_CPP_INCLUDE

#include <queue>
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
Tree::~Tree() {
    if (this->adj_list) {
        for (int i = 0; i < this->nodeCount; i++) {
            delete this->adj_list[i];  // Deallocate the Node
        }
        delete [] this->adj_list;    // Deallocate the array of Node pointers
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
    this->adj_list[i]->printList();
  }
}
void Tree::updateAdjList(const std::vector<int>& bfsOrder)
{
    Node** newAdjList = new Node*[nodeCount]; // create a new adjacency list

    // Traverse the BFS order and update the adjacency list accordingly
    for (int i = 0; i < bfsOrder.size(); i++) {
        int nodeIndex = bfsOrder[i];
        Node* curr = adj_list[nodeIndex];
        Node* newCurr = nullptr;
        Node* prev = nullptr;

        // Traverse the original adjacency list and create the new order
        while (curr != nullptr) {
            Node* newNode = new Node;
            newNode->setValue(curr->getValue());
            newNode->setNext(nullptr);
            if (prev) {
                prev->setNext(newNode);
            } else {
                newCurr = newNode;
            }
            prev = newNode;
            curr = curr->getNext();
        }

        newAdjList[i] = newCurr;
    }

    // Delete the original adjacency list
    for (int i = 0; i < nodeCount; i++) {
        Node* curr = adj_list[i];
        while (curr != nullptr) {
            Node* next = curr->getNext();
            delete curr;
            curr = next;
        }
    }
    delete[] adj_list;

    // Assign the new adjacency list
    adj_list = newAdjList;
}
// End class Tree
#endif