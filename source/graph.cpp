#include "graph.hpp"

#include <algorithm>
#include <queue>

// defining BFS and DFS search algorithms

// takes a filled graph, applies BFS algorithm storing and returning the
// traversal

std::vector<int>& Graph::bfs(int const start,
                             std::vector<int>& traversal) {
  assert(traversal.empty());
  std::vector<bool> visited(adjList_.size(), false);
  std::queue<int> queue;

  visited[start] = true;
  queue.push(start);

  while (!queue.empty()) {
    int current{queue.front()};
    queue.pop();
    traversal.push_back(current);

    for (int const& neighbor : adjList_[current]) {
      if (!visited[neighbor]) {
        visited[neighbor] = true;
        queue.push(neighbor);
      }
    }
  }

  return traversal;
}
