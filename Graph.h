#ifndef GRAPH_H_INCLUDE
#define GRAPH_H_INCLUDE

#include <iostream>

class Node {
  public:
    Node(); // Does nothing
    // Assignment only copies fields and not addresses
    Node& operator=(const Node &rhs);
    bool isEqual(const Node &comp);

    void setValue(int val);
    int getValue() const;

    void setNext(Node *n);
    Node* getNext();

    void printList();

  private:
    int value;
    Node *next;
}; // End class Node

class Graph {
  public:
    Graph(); // Sets nodeCount = 1, edgeCount = 0, and creates 1 node (value = 0)
    Graph(int size); // Sets nodeCount = size and allocates memory for size nodes
    // Big 3
    ~Graph();                          // De-constructor
    Graph(const Graph &clone);         // Copy constructor
    Graph& operator=(const Graph &rhs); // Assignment operator

    bool isEqual(const Graph &comp);
    // Adds a new node with specified value to adj_list and increments nodeCount
    // value must be > nodeCount
    void addNode(int value);
    // Adds the node with value v to the list headed by node with value u and
    // increments edgeCount
    void addEdge(int u, int v);
    // Returns and prints the breadth-first-search tree (graph) from a given
    // source node
    Graph getBFS(int v);
    // Returns and prints the shortest path from s to v in graph as a list (Node*)
    Node* getShortestPath(int s, int v);

    int getNodeCount() const;
    int getEdgeCount() const;

    void printGraph();

  private:
    int nodeCount; // Holds the total number of nodes in graph.
    int edgeCount; // Hold the total number of edges in graph
    Node **adj_list;
}; // End class Graph

#endif
