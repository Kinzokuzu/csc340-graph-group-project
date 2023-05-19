#ifndef TREE_H_CPP
#define TREE_H_CPP

#include <vector>
#include "Node.h"

class Tree {
  public:
    Tree();         // Sets nodeCount = 0, edgeCount = 0
    Tree(int size); // Sets nodeCount = size and create size nodes
    // Big 3
    virtual ~Tree();                          // De-constructor
    Tree(const Tree &clone);                  // Copy constructor
    virtual Tree& operator=(const Tree &rhs); // Assignment operator

    bool isEqual(const Tree &comp);
    // Adds the node v to node u's adjacency list and vice versa, also increments
    // edgeCount
    void addEdge(int u, int v);

    int getNodeCount() const;
    int getEdgeCount() const;

    void printTree();
    void updateAdjList(const std::vector<int>& bfsOrder);

  private:
    int nodeCount; // Holds the total number of nodes in graph.
    int edgeCount; // Hold the total number of edges in graph
    Node **adj_list;
    std::vector<int> bfsOrder;
}; // End class Tree

#endif
