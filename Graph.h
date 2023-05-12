#ifndef GRAPH_H_INCLUDE
#define GRAPH_H_INCLUDE

#include <iostream>

class Graph {
  public:
    Graph();
    Graph(int s); // Sets this->size = s and allocates memory for s nodes
    // Big 3
    ~Graph();                          // Deconstructor
    Graph(const Graph &clone);         // Copy constructor
    Graph operator=(const Graph &rhs); // Assignment operator

    // Increasing the size of the graph (node count) may require reallocation
    // of memory
    void addNode(int newNode);
    void addEdge(int u, int v);
    // Returns the shortest path from s to v in graph as a list (int*)
    int* getShortestPath(int s, int v);

    void printList();
    void printGraph();

  private:
    int size;
    int **adj_list;
};

// Returns the breadth-first-search tree (graph) generated from input graph
Graph* breadthFirstSearch(const Graph &graph);

#endif
