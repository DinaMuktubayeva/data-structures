#include <iostream>
#include <list>
#include <ostream>
#include <vector>

/* An implementation of a graph with
an adjacency list */
class graph
{
  size_t num_vertices; // number of vertices
  size_t num_edges;    // number of edges
  std::list<int> *adj; // pointer to an array of adjacency lists

public:
  graph(int v) : num_edges(0),
                 num_vertices(v),
                 adj(new std::list<int>[v])
  {
  }

  // Copy constructor
  graph(const graph &g);

  // Initializer list constructor
  graph(std::initializer_list<std::vector<int>> ilist);

  // Copy assignment
  graph &operator=(const graph &g);

  // Check for equality
  bool operator==(const graph &g) const;

  // Check for inequality
  bool operator!=(const graph &g) const;

  // Add a directed edge from x to y
  void addEdge(int x, int y);

  // Check if there is an edge from x to y
  bool hasEdge(int x, int y);

  // Remove an edge from x to y
  void removeEdge(int x, int y);

  // Get neighbors of a vertex
  std::list<int>& getNeighbors(int v);

  // Get a reversed graph
  graph reverse();

  // Empty the graph
  void clear();

  // Returns whether the graph is empty
  bool empty() const;

  // Returns the number of vertices
  size_t numVertices() const;

  // Returns the number of edges
  size_t numEdges() const;

  // Print out the contents of the stack
  void print(std::ostream &out) const
  {
    for (size_t i = 0; i < num_vertices; i++)
    {
      std::cout << i + 1 << " ";
      for (auto it : adj[i])
        std::cout << it << " ";

      std::cout << std::endl;
    }
  }

  // Destructor
  ~graph();
};

inline std::ostream &operator<<(std::ostream &out, const graph &g)
{
  g.print(out);
  return out;
}