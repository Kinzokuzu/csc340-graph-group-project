#include <iostream>
#include "UnitTest.h"

int main() {

  Graph first(3);
  first.addEdge(0, 1);
  first.addEdge(0, 2);
  first.printGraph();

  Graph second(first);
  second.printGraph();

  std::cout << first.isEqual(second) << std::endl;
  std::cout << second.isEqual(first) << std::endl;

  std::cout << "Tests\n";
  // Test Node
//  std::cout << test_NodeDefCon() << std::endl;
//  std::cout << test_NodeAssignment() << std::endl;
//  std::cout << test_NodeIsEqual() << std::endl;
//  // Test Graph constructors, de-constructors and assignment operator
//  std::cout << test_GraphDefCon() << std::endl;
//  std::cout << test_GraphInitCon() << std::endl;
//  std::cout << test_GraphCopyCon() << std::endl;
//  std::cout << test_GraphDeCon() << std::endl;
//  std::cout << test_GraphAssignment() << std::endl; // Failed
//  // Test Graph member functions
//  std::cout << test_GraphIsEqual() << std::endl;
//  std::cout << test_GraphAddNode() << std::endl;
//  std::cout << test_GraphAddEdge() << std::endl; // Failed
//  std::cout << test_GraphGetBFS() << std::endl; // Failed
//  std::cout << test_GraphGetShortestPath() << std::endl; // Failed
    test_GraphAddNode();
  return 0;
}

// testing