#ifndef GRAPH_CPP_INCLUDE
#define GRAPH_CPP_INCLUDE

#include "Graph.h"

Graph::Graph() {
  this->size = 0;
}
Graph::Graph(int s) {}
// Big -3
Graph::~Graph() {}
Graph::Graph(const Graph &clone) {}
Graph Graph::operator=(const Graph &rhs) {}

void Graph::addNode(int newNode) {}
void Graph::addEdge(int u, int v) {}

Graph Graph::getBFS(int v) {}
int* Graph::getShortestPath(int s, int v) {}

void Graph::printGraph() {}

#endif
