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