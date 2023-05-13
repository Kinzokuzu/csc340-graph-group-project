#ifndef GRAPH_H_INCLUDE
#define GRAPH_H_INCLUDE

#include <iostream>

class Node {
  public:
    void setValue(int val);
    int getValue();

    void setNext(Node *n);
    Node* getNext();

    void printList();

  private:
    int value;
    Node *next;
}; // End class Node

class Graph {
  public:
    Graph();
    Graph(int s); // Sets this->size = s and allocates memory for s nodes
    // Big 3
    ~Graph();                          // Deconstructor
    Graph(const Graph &clone);         // Copy constructor
    Graph operator=(const Graph &rhs); // Assignment operator

    // Adds a new node with specified value to adj_list and increments nodeCount
    // value must be > nodeCount
    void addNode(int value);
    // Adds the node with value v to the list headed by node with value u and
    // increments edgeCount
    void addEdge(int u, int v);
    // Returns and prints the breadth-first-search tree (graph) from a given
    // source node
    Graph getBFS(int v);
    // Returns the shortest path from s to v in graph as a list (int*)
    int* getShortestPath(int s, int v);

    void printGraph();

  private:
    int nodeCount; // Holds the total number of nodes in graph.
    int edgeCount; // Hold the total number of edges in graph
    Node **adj_list;
}; // End class Graph

#endif
