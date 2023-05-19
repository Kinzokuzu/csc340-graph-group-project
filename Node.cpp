#ifndef NODE_CPP_INCLUDE
#define NODE_CPP_INCLUDE

#include "Node.h"

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
// End class Node
#endif