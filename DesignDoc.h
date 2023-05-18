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


/* addEdge()
 * time complexity: O(u) because in the worst case, we have to iterate through each node(u) until the end
 * To create a new node(v), we need to update the next pointer of the last node. So it takes O(1). 
 * 
 * space complexity: O(1) because we are not creating any extra space for two nodes
 */