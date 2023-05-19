#include "Graph.h"

inline
bool test_NodeDefCon() {
  std::cout << "TESTING: Node default constructor" << std::endl;

  Node node1;
  bool result = (node1.getValue() == -1);
  if (result) {
    std::cout << "PASSED: test_NodeDefCon | ";
  }
  else {
    std::cout << "FAILED: test_NodeDefCon() | ";
  }

  return result;
}

inline
bool test_NodeAssignment() {
  std::cout << "TESTING: Node::operator=()" << std::endl;
  Node *first, *second, *test;
  try {
    first = new Node;
    second = new Node;
  }
  catch (std::bad_alloc &e) {
    std::cout << e.what() << std::endl;
  }

  first->setValue(1);
  first->setNext(second);
  second->setValue(1);
  second->setNext(nullptr);

  test = first;

  bool result = test->isEqual(*first);
  if (result) {
    std::cout << "PASSED: test_NodeAssignment() | ";
  }
  else {
    std::cout << "FAILED: test_NodeAssignment() | ";
  }

  return result;
}

inline
bool test_NodeIsEqual() {
  std::cout << "TESTING: Node::isEqual()" << std::endl;

  Node *first, *second, *test1, *test2;
  try {
    first = new Node;
    second = new Node;
    test1 = new Node;
    test2 = new Node;
  }
  catch (std::bad_alloc &e) {
    std::cout << e.what() << std::endl;
  }

  first->setValue(1);
  second->setValue(2);
  first->setNext(second);
  second->setNext(nullptr);
  // Assign test1, test2 with same values as first, second (different addresses)
  test1->setValue(1);
  test2->setValue(2);
  test1->setNext(test2);
  test2->setNext(nullptr);

  bool result = test1->isEqual(*first);

  if (result) {
    std::cout << "PASSED: test_NodeIsEqual() | ";
  }
  else {
    std::cout << "FAILED: test_NodeIsEqual() | ";
  }

  return result;
}

inline
bool test_NodeAddNode() {
  std::cout << "TESTING: Node::addNode()" << std::endl;

  Node *first;
  try {
    first = new Node;
  }
  catch (std::bad_alloc &e){
    std::cout << e.what() << std::endl;
  }
  first->addNode(1);

  bool result = true;
  if (first->getNext()->getValue() != 1) {
    result = false;
  }

  if (result) {
    std::cout << "PASSED: test_AddNode() | ";
  }
  else {
    std::cout << "FAILED: test_AddNode() | ";
  }

  return result;
}

inline
bool test_GraphDefCon() {
  std::cout << "TESTING: Graph default constructor" << std::endl;
  bool result = true;

  Graph test;
  // Test nodeCount, edgeCount
  if (test.getNodeCount() != 0) {
    result = false;
    std::cout << "FAILED: test_GraphDefCon(): nodeCount != 0 | ";
  }
  if (test.getEdgeCount() != 0) {
    result = false;
    std::cout << "FAILED: test_GraphDefCon(): edgeCount != 0 | ";
  }
  if (result) {
    std::cout << "PASSED: test_GraphDefCon() | ";
  }

  return result;
}

inline
bool test_GraphInitCon() {
  std::cout << "TESTING: Graph initialized constructor" << std::endl;
  bool result = true;

  int size = 3;
  Graph test(size);
  // Test nodeCount
  if (test.getNodeCount() != size) {
    result = false;
    std::cout << "expected nodeCount: " << size << "\n"
              << "actual nodeCount: " << test.getNodeCount() << "\n"
              << "FAILED: test_GraphInitCon() | ";
  }
  if (result) {
    std::cout << "PASSED: test_GraphInitCon() | ";
  }

  return result;
}

inline
bool test_GraphCopyCon() {
  std::cout << "TESTING: Graph copy constructor" << std::endl;
  Graph first(2);

  Graph second(first);

  bool result = second.isEqual(first);
  if (result) {
    std::cout << "PASSED: test_GraphCopyCon() | ";
  }
  else {
    std::cout << "FAILED: test_GraphCopyCon() | ";
  }

  return result;
}

inline
bool test_GraphDeCon() {
  bool result = true;
  // Not sure how???
  return result;
}

inline
bool test_GraphAssignment() {
  std::cout << "TESTING: Graph::operator=()" << std::endl;
  Graph first(2);
  Graph second = first;

  bool result = second.isEqual(first);
  if (result) {
    std::cout << "PASSED: test_GraphAssignment() | ";
  }
  else {
    std::cout << "FAILED: test_GraphAssignment() | ";
  }

  return result;
}

inline
bool test_GraphIsEqual() {
  std::cout << "TESTING: Graph::isEqual()" << std::endl;
  Graph first(2);
  first.addEdge(0, 1);
  // Do same operations on second as first
  Graph second(2);
  second.addEdge(0, 1);

  bool result = second.isEqual(first);
  if (result) {
    std::cout << "PASSED: test_GraphIsEqual() | ";
  }
  else {
    std::cout << "FAILED: test_GraphIsEqual() | ";
  }

  return result;
}

inline
bool test_GraphAddEdge() {
  std::cout << "TESTING: Graph::addEdge()" << std::endl;
  bool result = true;
  Graph first(2);
  first.addEdge(0, 1);

  if (first.getEdgeCount() != 1) {
    result = false;
    std::cout << "FAILED: test_GraphAddEdge() | ";
  }
  if (result) {
    std::cout << "PASSED: test_GraphAddEdge() | ";
  }

  return result;
}

inline
bool test_GraphGetBFS1() {
  std::cout << "TESTING: Graph::getBFS() #1" << std::endl;
  Tree expected_tree(5);
  expected_tree.addEdge(0, 1);
  expected_tree.addEdge(0, 2);
  expected_tree.addEdge(1, 3);
  expected_tree.addEdge(2, 4);
  std::cout << "Expected BFS tree:\n";
  expected_tree.printTree();

  Graph test(5);
  test.addEdge(0, 1);
  test.addEdge(0, 2);
  test.addEdge(1, 2);
  test.addEdge(1, 3);
  test.addEdge(2, 4);
  test.addEdge(3, 4);

  std::cout << "Returned BFS tree:\n";
  Tree BFS_tree = test.getBFS(0);

  bool result = BFS_tree.isEqual(expected_tree);
  if (result) {
    std::cout << "PASSED: test_GraphGetBDF1() | ";
  }
  else {
    std::cout << "FAILED: test_GraphGetBDF1() | ";
  }

  return result;
}

inline
bool test_GraphGetBFS2() {
  std::cout << "TESTING: Graph::getBFS() #2" << std::endl;
  Tree expected_tree(6);
  expected_tree.addEdge(2, 4);
  expected_tree.addEdge(2, 5);
  expected_tree.addEdge(4, 0);
  expected_tree.addEdge(5, 3);
  expected_tree.addEdge(0, 1);
  std::cout << "Expected BFS tree:" << std::endl;
  expected_tree.printTree();

  Graph test(6);
  test.addEdge(1, 0);
  test.addEdge(2, 4);
  test.addEdge(2, 5);
  test.addEdge(3, 1);
  test.addEdge(4, 0);
  test.addEdge(5, 3);

  std::cout << "Returned BFS tree:\n";
  Tree BFS_tree = test.getBFS(2);

  bool result = BFS_tree.isEqual(expected_tree);
  if (result) {
    std::cout << "PASSED: test_GraphGetBDF2() | ";
  }
  else {
    std::cout << "FAILED: test_GraphGetBDF2() | ";
  }

  return result;
}

inline
bool test_GraphGetBFS3() {
  std::cout << "TESTING: Graph::getBFS() #3" << std::endl;
  Tree expected_tree(7);
  expected_tree.addEdge(6, 1);
  expected_tree.addEdge(6, 2);
  expected_tree.addEdge(6, 3);
  expected_tree.addEdge(6, 4);
  expected_tree.addEdge(1, 0);
  expected_tree.addEdge(3, 5);
  std::cout << "Expected BFS tree:" << std::endl;
  expected_tree.printTree();

  Graph test(7);
  test.addEdge(0, 1);
  test.addEdge(0, 2);
  test.addEdge(1, 6);
  test.addEdge(2, 6);
  test.addEdge(6, 3);
  test.addEdge(6, 4);
  test.addEdge(3, 5);
  test.addEdge(4, 5);

  std::cout << "Returned BFS tree:\n";
  Tree BFS_tree = test.getBFS(6);

  bool result = BFS_tree.isEqual(expected_tree);
  if (result) {
    std::cout << "PASSED: test_GraphGetBDF3() | ";
  }
  else {
    std::cout << "FAILED: test_GraphGetBDF3() | ";
  }

  return result;
}

inline
bool test_GraphGetShortestPath1() {
  std::cout << "TESTING: Graph::getShortestPath() #1" << std::endl;
  Node *expected_list, *node1, *node4;
  try {
    expected_list = new Node;
    node1 = new Node;
    node4 = new Node;
    // Expected list is as follows: 0 -> 1 -> 4
    expected_list->setValue(0);
    expected_list->setNext(node1);
    node1->setValue(1);
    node1->setNext(node4);
    node4->setValue(4);
    node4->setNext(nullptr);
  }
  catch (std::bad_alloc &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "Expected shortest path\n";
  expected_list->printList();

  Graph test(5);
  test.addEdge(0, 1);
  test.addEdge(0, 2);
  test.addEdge(1, 2);
  test.addEdge(1, 3);
  test.addEdge(1, 4);
  test.addEdge(3, 4);

  std::cout << "Returned shortest path:\n";
  Node *test_list = test.getShortestPath(0, 4);

  bool result = test_list->isEqual(*expected_list);
  if (result) {
    std::cout << "PASSED: test_GraphGetShortestPath()1 | ";
  }
  else {
    std::cout << "FAILED: test_GraphGetShortestPath()1 | ";
  }

  return result;
}

inline
bool test_GraphGetShortestPath2() {
  std::cout << "TESTING: Graph::getShortestPath() #2" << std::endl;
  Node *expected_list, *node1, *node4;
  try {
    expected_list = new Node;
    node1 = new Node;
    node4 = new Node;
    // Expected list is as follows: 2 -> 4 -> 0
    expected_list->setValue(2);
    expected_list->setNext(node1);
    node1->setValue(4);
    node1->setNext(node4);
    node4->setValue(0);
    node4->setNext(nullptr);
  }
  catch (std::bad_alloc &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "Expected shortest path:\n";
  expected_list->printList();

  Graph test(6);
  test.addEdge(1, 0);
  test.addEdge(2, 4);
  test.addEdge(2, 5);
  test.addEdge(3, 1);
  test.addEdge(4, 0);
  test.addEdge(5, 3);

  std::cout << "Returned shortest path:\n";
  Node *test_list = test.getShortestPath(2, 0);

  bool result = test_list->isEqual(*expected_list);
  if (result) {
    std::cout << "PASSED: test_GraphGetShortestPath2() | ";
  }
  else {
    std::cout << "FAILED: test_GraphGetShortestPath2() | ";
  }

  return result;
}
inline
bool test_GraphGetShortestPath3() {
  std::cout << "TESTING: Graph::getShortestPath() #3" << std::endl;
  Node *expected_list, *node1, *node6, *node3, *node5;
  try {
    expected_list = new Node;
    node1 = new Node;
    node6 = new Node;
    node3 = new Node;
    node5 = new Node;
    // Expected list is as follows: 0 -> 1 -> 6 -> 3 -> 5
    expected_list->setValue(0);
    expected_list->setNext(node1);
    node1->setValue(1);
    node1->setNext(node6);
    node6->setValue(6);
    node6->setNext(node3);
    node3->setValue(3);
    node3->setNext(node5);
    node5->setValue(5);
  }
  catch (std::bad_alloc &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "Expected shortest path:\n";
  expected_list->printList();

  Graph test(7);
  test.addEdge(0, 1);
  test.addEdge(0, 2);
  test.addEdge(1, 6);
  test.addEdge(2, 6);
  test.addEdge(6, 3);
  test.addEdge(6, 4);
  test.addEdge(3, 5);
  test.addEdge(4, 5);

  std::cout << "Returned shortest path:\n";
  Node *test_list = test.getShortestPath(0, 5);

  bool result = test_list->isEqual(*expected_list);
  if (result) {
    std::cout << "PASSED: test_GraphGetShortestPath3() | ";
  }
  else {
    std::cout << "FAILED: test_GraphGetShortestPath3() | ";
  }

  return result;
}
