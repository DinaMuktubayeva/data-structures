#include "graph.h"

int main(int argc, char const *argv[])
{
  std::cout << "Created a directed graph g1 with 6 vertices:" << std::endl;
  graph g1(6);
  std::cout << g1 << std::endl;

  std::cout << "Adding an edge 1-4" << std::endl;
  g1.addEdge(1, 4);
  std::cout << "Does g1 has an edge 1-4 ? " << g1.hasEdge(1, 4) << std::endl;
  std::cout << "Does g1 has an edge 4-1 ? " << g1.hasEdge(4, 1) << std::endl;

  std::cout << "Removing the edge 1-4" << std::endl;
  g1.removeEdge(1, 4);
  std::cout << "Does g1 has an edge 1-4 ? " << g1.hasEdge(1, 4) << std::endl;

  std::cout << "Adding two more edges to g1" << std::endl;
  g1.addEdge(1, 2);
  g1.addEdge(5, 3);
  std::cout << "Printing g" << std::endl;
  std::cout << g1 << std::endl;
  std::cout << "Printing a reverse of g" << std::endl;
  std::cout << g1.reverse() << std::endl;
  std::cout << "How many edges does g1 have? " << g1.numEdges() << std::endl;

  std::cout << "Creating g2 as a copy of g1" << std::endl;
  graph g2(g1);
  std::cout << "Creating g3 with 4 vertices:" << std::endl;
  graph g3(4);
  std::cout << g3 << std::endl;

  std::cout << "Is g3 empty? " << g3.empty() << std::endl;

  std::cout << "Copying g1 into g3:" << std::endl;
  g3 = g1;

  std::cout << g3 << std::endl;
  std::cout << "Is g1 equal to g2? " << (g1 == g3) << std::endl;
  std::cout << "Is g1 equal to g3? " << (g1 == g3) << std::endl;
  std::cout << "Is g2 equal to g3? " << (g1 == g3) << std::endl;
  std::cout << "Is g1 not equal to g3? " << (g1 != g3) << std::endl;
  std::cout << "Is g1 equal to its reverse? " << (g1 == g1.reverse()) << std::endl;

  return 0;
}
