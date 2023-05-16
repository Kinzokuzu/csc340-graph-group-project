#include <iostream>
#include "Graph.h"

int main() {
  Node *head = new Node;
  Node *prev = new Node;
  Node *curr = new Node;

  int nodeCount = 10;
  // Create nodeCount nodes
  for (int i = 0; i < nodeCount; i++) {
    if (i == 0) {
      head->setValue(i);
      prev = head;
    } else {
      Node *newNode = new Node;
      newNode->setValue(i);
      prev->setNext(newNode);
      prev = newNode;
    }
  }

  // Print out all nodes in list
  head->printList();

  return 0;
}

// testing