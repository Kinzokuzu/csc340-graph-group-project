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
addEdge()
pseudocode:
- checks if the provided node indexes u and v are within the valid range.
If the indexes are invalid, it throws an InvalidNodeIndexesException.
Otherwise, it traverses to the end of the adjacency list for node u.

- creates a new node object newNode and sets its value to v.
- appends newNode to the end of the adjacency list for node u.
- increments the edgeCount variable to keep track of the number of edges.
- It performs the same steps for node v, adding an edge from v to u.
- If any exceptions occur, 
- catch and print the corresponding error messages.

time complexity: O(n) 
In the worst case, we have to loop through all the edges until the last edge

space complexity: O(1)
Since we are not storing any extra space.
*/

/* addEdge()
 * time complexity: O(u) because in the worst case, we have to iterate through each node(u) until the end
 * To create a new node(v), we need to update the next pointer of the last node. So it takes O(1). 
 * 
 * space complexity: O(1) because we are not creating any extra space for two nodes
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
Implement addNode 
Psuedo Code:
input(val)
  set curr as the current node
  while curr has a next node-> curr = next node
  create a new node newNode
  try:
    set newNode's value to val
    set newNode's next to nullptr
  append the list by adding curr's next pointer to be newNode
  Time complexity: O(n) with n being how many nodes there are.

getShortestPath():
  Initialize data structures (visited, parent, queue).
  Mark the starting node as visited and enqueue it.
  Perform a BFS traversal until the queue is empty, and for each node visited, update the visited status, set parent, and enqueue neighbors.
  Stop BFS if the destination node is found, and then check if a path from start to destination exists based on the parent of the destination node.
  If no path exists, return nullptr.
  If the start and destination nodes are the same, return a linked list with a single node.
  Build the shortest path by traversing the parent array in reverse order.
  Print the shortest path.
  The time complexity is O(v + e), where v is the number of nodes and e is the number of edges in the graph.
*/

