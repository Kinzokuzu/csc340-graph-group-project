#include <iostream>
#include "UnitTest.h"

int main() {
  std::cout << "--UNIT TESTS--\n" << std::endl;
  // Test Node
  std::cout << test_NodeDefCon() << "\n" << std::endl;
  std::cout << test_NodeAssignment() << "\n" << std::endl;
  std::cout << test_NodeIsEqual() << "\n" << std::endl;
  std::cout << test_NodeAddNode() << "\n" << std::endl;
  // Test Graph constructors, de-constructors and assignment operator
  std::cout << test_GraphDefCon() << "\n" << std::endl;
  std::cout << test_GraphInitCon() << "\n" << std::endl;
  std::cout << test_GraphCopyCon() << "\n" << std::endl;
  //std::cout << test_GraphDeCon() << "\n" << std::endl;
  std::cout << test_GraphAssignment() << "\n" << std::endl;
  // Test Graph member functions
  std::cout << test_GraphIsEqual() << "\n" << std::endl;
  std::cout << test_GraphAddEdge() << "\n" << std::endl;
  std::cout << test_GraphGetBFS1() << "\n" << std::endl;
  std::cout << test_GraphGetBFS2() << "\n" << std::endl;
  std::cout << test_GraphGetBFS3() << "\n" << std::endl;
  std::cout << test_GraphGetShortestPath1() << "\n" << std::endl;
  std::cout << test_GraphGetShortestPath2() << "\n" << std::endl;
  std::cout << test_GraphGetShortestPath3() << std::endl;

  return 0;
}

// testing