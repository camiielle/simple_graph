#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <cassert>
#include <random>
#include <unordered_map>
#include <vector>

// defines class Graph using adjacency list representation

class Graph {
  std::unordered_map<int, std::vector<int>> adjList_;

 public:
  Graph(std::unordered_map<int, std::vector<int>> const& adjList)
      : adjList_{adjList} {
    assert(!(adjList_.empty()));
  }

  // N.B. not risking narrowing with int as return type since parameter
  // numOfNodes is an int
  int size() const { return adjList_.size(); }
  std::vector<int>& operator[](int index) { return adjList_[index]; }
  std::vector<int>& bfs(int const start,
                        std::vector<int>& traversal);  // breadth first search
  std::vector<int>& dfs(int const start,
                        std::vector<int>& traversal);  // depth first search
};

#endif