#ifndef GRAPH_H_INCLUDE
#define GRAPH_H_INCLUDE

#include <iostream>

struct Node {
  int value;
  Node *prevNode;

  Node();
  Node(int v, Node *pn);

  Node* getPrevNode();
};

class Graph {
  public:
    Graph();
    Graph(int s); // Sets this->size = s and allocates memory for s nodes
    // Big 3
    ~Graph();                          // Deconstructor
    Graph(const Graph &clone);         // Copy constructor
    Graph operator=(const Graph &rhs); // Assignment operator

    // Increasing node/edge count requires allocation of memory
    void addNode(int newNode);
    void addEdge(int u, int v);
    // Returns and prints the breadth-first-search tree (graph) from a given
    // source node
    Graph getBFS(int v);
    // Returns the shortest path from s to v in graph as a list (int*)
    int* getShortestPath(int s, int v);

    void printList();
    void printGraph();

  private:
    int size;
    Node **adj_list;
}; // End class Graph

#endif
