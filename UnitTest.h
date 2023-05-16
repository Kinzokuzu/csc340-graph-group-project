#include "Graph.h"

inline
bool test_NodeDefCon() {
  bool result = true;
  // Default constructor does nothing
  return result;
}

inline
bool test_NodeAssignment() {
  Node *first, *second, *test;
  try {
    first = new Node;
    second = new Node;
    test = new Node;
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
  if (!result)
    std::cout << "FAILED: test_NodeAssignment() | ";

  return result;
}

inline
bool test_NodeIsEqual() {
  bool result = true;

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

  if (!test1->isEqual(*first)) {
    result = false;
    std::cout << "FAILED: test_NodeIsEqual | ";
  }

  return result;
}

inline
bool test_GraphDefCon() {
  bool result = true;

  Graph test;
  // Test nodeCount, edgeCount
  if (test.getNodeCount() != 1) {
    result = false;
    std::cout << "FAILED: test_GraphDefCon: nodeCount != 0 | ";
  }
  if (test.getEdgeCount() != 0) {
    result = false;
    std::cout << "FAILED: test_GraphDefCon: edgeCount != 0 | ";
  }

  return result;
}

inline
bool test_GraphInitCon() {
  bool result = true;

  int size = 3;
  Graph test(size);
  // Test nodeCount
  if (test.getNodeCount() != size) {
    result = false;
    std::cout << "FAILED: test_GraphInitCon: nodeCount != " << size << " | ";
  }

  return result;
}

inline
bool test_GraphCopyCon() {
  Graph first;
  first.addNode(1);
  first.addNode(2);

  Graph second(first);

  bool result = second.isEqual(first);
  if (!result) {
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
  Graph first(2);
  Graph second = first;

  bool result = second.isEqual(first);
  if (!result) {
    std::cout << "FAILED: test_GraphAssignment() | ";
  }

  return result;
}

inline
bool test_GraphIsEqual() {
  Graph first, second;
  first.addNode(1);
  first.addNode(2);
  first.addEdge(0, 2);
  // Do same operations on second as first
  second.addNode(1);
  second.addNode(2);
  second.addEdge(0, 2);

  bool result = second.isEqual(first);
  if (!result) {
    std::cout << "FAILED: test_GraphIsEqual() | ";
  }

  return result;
}

inline
bool test_GraphAddNode() {
  bool result = true;
  Graph first;
  first.addNode(1);

  if (first.getNodeCount() != 2) {
    result = false;
    std::cout << "FAILED: test_GraphAddNode() | ";
  }

  return result;
}

inline
bool test_GraphAddEdge() {
  bool result = true;
  Graph first(2);
  first.addEdge(0, 1);

  if (first.getEdgeCount() != 1) {
    result = false;
    std::cout << "FAILED: test_GraphAddEdge() | ";
  }

  return result;
}

inline
bool test_GraphGetBFS() {
  Graph expected_tree(5);
  expected_tree.addEdge(0, 1);
  expected_tree.addEdge(0, 2);
  expected_tree.addEdge(1, 3);
  expected_tree.addEdge(2, 4);

  Graph test(5);
  test.addEdge(0, 1);
  test.addEdge(0, 2);
  test.addEdge(1, 2);
  test.addEdge(1, 3);
  test.addEdge(2, 4);
  test.addEdge(3, 4);

  Graph BFS_tree = test.getBFS(0);

  bool result = BFS_tree.isEqual(expected_tree);
  if (!result) {
    std::cout << "FAILED: test_GraphGetBDF() | ";
  }

  return result;
}

inline
bool test_GraphGetShortestPath() {
  Node *expected_list;
  try {
    expected_list = new Node;
  }
  catch (std::bad_alloc &e) {
    std::cout << e.what() << std::endl;
  }

  Graph test(5);
  test.addEdge(0, 1);
  test.addEdge(0, 2);
  test.addEdge(1, 2);
  test.addEdge(1, 3);
  test.addEdge(1, 4);
  test.addEdge(3, 4);
}

