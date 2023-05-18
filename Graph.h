#ifndef GRAPH_H_INCLUDE
#define GRAPH_H_INCLUDE

#include <queue>
#include <vector>

#include "Node.h"
#include "Tree.h"

class Graph {
  public:
    Graph();         // Sets nodeCount = 0, edgeCount = 0
    Graph(int size); // Sets nodeCount = size and create size nodes
    // Big 3
    virtual ~Graph();                   // De-constructor
    Graph(const Graph &clone);          // Copy constructor
    Graph& operator=(const Graph &rhs); // Assignment operator

    bool isEqual(const Graph &comp);
    // Adds the node v to node u's adjacency list and vice versa, also increments
    // edgeCount
    virtual void addEdge(int u, int v);
    // Returns and prints the breadth-first-search tree (graph) from a given
    // source node
    Tree getBFS(int v);
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
