#include <iostream>

int main() {
  // Create a graph of nodeCount nodes (nodes are represented by ints)
  int nodeCount = 3;
  int **Graph = new int*[nodeCount];

  int num = 1; // Just for printing, not an accurate description of node
  // For every node, create a node list
  for (int i = 0; i < nodeCount; i++) {
    Graph[i] = new int[i + 1]; // Graph[i] is a node list
    *Graph[i] = num; // Assigning first node in Graph[i] an arbitrary value
    num++;

    // Assigning an arbitrary value for every subsequent node in Graph[i]
    for (int j = 1; j < i + 1; j++) {
      Graph[i][j] = num;
      num++;
    }
  }

  // Printing out the graph.  Again, printed values are arbitrary
  for (int i = 0; i < nodeCount; i++) {
    for (int j = 0; j < i + 1; j++) {
      if (j == 0) {
        std::cout << Graph[i][j];
      } else {
        std::cout << " -> " << Graph[i][j];
      }
    }
    std::cout << std::endl;
  }

  return 0;
}