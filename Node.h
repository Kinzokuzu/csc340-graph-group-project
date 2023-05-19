#ifndef NODE_H_INCLUDE
#define NODE_H_INCLUDE

#include <iostream>

class Node {
  public:
    Node(); // Sets value = -1, next = nullptr
    // Assignment only copies fields and not addresses
    Node& operator=(const Node &rhs);
    bool isEqual(const Node &comp);

    void setValue(int val);
    int getValue() const;

    void setNext(Node *n);
    Node* getNext() const;

    // Appends a node with value val to the list (Node*) that calls it
    void addNode(int val);

    void printList();

  private:
    int value;
    Node *next;
}; // End class Node

#endif