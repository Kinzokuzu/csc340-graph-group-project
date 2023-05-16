#ifndef GRAPH_CPP_INCLUDE
#define GRAPH_CPP_INCLUDE

#include "Graph.h"
#include <vector>
#include <queue>

Graph::Graph() {}
Graph::Graph(int s) {}
// Big -3
Graph::~Graph() {}
Graph::Graph(const Graph &clone) {}
Graph Graph::operator=(const Graph &rhs) {}

void Graph::addNode(int newNode) {}
void Graph::addEdge(int u, int v) {}

Graph Graph::getBFS(int v)
{
    Graph bfsGraph(size);                   // create a new graph for BFS traversal
    std::vector<bool> visited(size, false); // keep track of visited nodes
    std::queue<int> q;                      // queue for BFS traversal

    visited[v] = true; // mark the starting node as visited
    q.push(v);         // enqueue the starting node

    while (!q.empty()) // while queue is not empty
    {
        int node = q.front(); // get the front element of the queue
        q.pop();              // remove the front element from the queue

        for (int i = 0; i < size; i++)
        {
            if (adj_list[node][i] == 1 && !visited[i])
            {
                visited[i] = true;         // mark the neighbor as visited
                q.push(i);                 // enqueue the neighbor
                bfsGraph.addEdge(node, i); // add an edge to the BFS graph
            }
        }
    }

    return bfsGraph;
}
int *Graph::getShortestPath(int s, int v) {}

void Graph::printGraph() {}

#endif
