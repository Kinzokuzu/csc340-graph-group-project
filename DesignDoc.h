/* DesignDoc.h, Graph.h, Graph.cpp, UnitTest.h, main.cpp
 * Authors: 11am Group 9
 *          Saul Cervantes-Hernandez
 *          Mya Phyu
 *          Kiran Poudel
 *          Guillermo Reyes Yanez
 *          Sidney Thomas
 *
 * Date: 5/18/23
 */

/*
Implement the breadth first search algorithm
Pseudo Code :

--> Creating a new graph (bfsGraph) for performing breadth-first search (BFS) traversal.

--> Initializing a boolean vector (visited) to keep track of visited nodes. Initially, all nodes are marked as not visited.

--> Creating a queue (q) for BFS traversal.

--> Marking the starting node (v) as visited and enqueueing it.

--> Performing BFS traversal using a while loop that continues until the queue is empty.

-- Inside the while loop:

--> Dequeueing a node from the front of the queue. --> Accessing the adjacency list of the dequeued node. --> Iterating over the neighbors of the current node and processing them. --> If a neighbor node has not been visited, mark it as visited, enqueue it, and add an edge between the current node and the neighbor node in the bfsGraph. --> After the BFS traversal is complete, the bfsGraph is returned.

Time Complexity : O(N + E), where N is the number of nodes and E is the number of edges in the graph.
*/