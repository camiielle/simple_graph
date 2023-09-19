#include "graph.hpp"

#include <algorithm>
#include <queue>
#include <stack>

// defining BFS and DFS search algorithms, as well as auxiliary print function

std::vector<int>& Graph::bfs(int const start, std::vector<int>& traversal) {
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

std::vector<int>& Graph::dfs(int const start, std::vector<int>& traversal) {
  assert(traversal.empty());

  std::vector<bool> visited(adjList_.size(), false);
  std::stack<int> stack;
  visited[start] = true;
  stack.push(start);

  while (!stack.empty()) {
    int current{stack.top()};
    stack.pop();
    traversal.push_back(current);

    for (int const& neighbor : adjList_[current]) {
      if (!visited[neighbor]) {
        visited[neighbor] = true;
        stack.push(neighbor);
      }
    }
  }
  return traversal;
}

void printTraversal(std::vector<int> const& traversal) {
  for (int const& i : traversal) {
    std::cout << i << "  ";
  }
}