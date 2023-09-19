#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "graph.hpp"

TEST_CASE("testing Graph") {
  std::unordered_map<int, std::vector<int>> adjList0{
      {0, {2, 3}}, {1, {2}}, {2, {0, 1, 3}}, {3, {0, 2}}};
  std::unordered_map<int, std::vector<int>> adjList1{
      {0, {1}}, {1, {0, 2}}, {2, {1}}};
  std::unordered_map<int, std::vector<int>> adjList2{
      {0, {2, 3, 4}}, {1, {2}},    {2, {0, 1, 3}}, {3, {0, 2}},
      {4, {0, 5}},    {5, {4, 6}}, {6, {5}}};

  Graph g0{adjList0};
  Graph g1{adjList1};
  Graph g2{adjList2};

  SUBCASE("testing size") {
    CHECK(g0.size() == 4);
    CHECK(g1.size() == 3);
    CHECK(g2.size() == 7);
  }

  SUBCASE("testing constructor and subscript operator") {
    CHECK(g0[0] == std::vector<int>{2, 3});
    CHECK(g0[1] == std::vector<int>{2});
    CHECK(g0[2] == std::vector<int>{0, 1, 3});
    CHECK(g0[3] == std::vector<int>{0, 2});

    CHECK(g1[0] == std::vector<int>{1});
    CHECK(g1[1] == std::vector<int>{0, 2});
    CHECK(g1[2] == std::vector<int>{1});

    CHECK(g2[0] == std::vector<int>{2, 3, 4});
    CHECK(g2[1] == std::vector<int>{2});
    CHECK(g2[2] == std::vector<int>{0, 1, 3});
    CHECK(g2[3] == std::vector<int>{0, 2});
    CHECK(g2[4] == std::vector<int>{0, 5});
    CHECK(g2[5] == std::vector<int>{4, 6});
    CHECK(g2[6] == std::vector<int>{5});
  }

  SUBCASE("testing bfs") {
    SUBCASE("testing on g0") {
      std::vector<int> traversal0;
      g0.bfs(0, traversal0);
      CHECK(traversal0[0] == 0);
      CHECK(traversal0.size() == 4);
      std::sort(traversal0.begin(), traversal0.end());
      CHECK(std::adjacent_find(traversal0.begin(), traversal0.end()) ==
            traversal0.end());
    }

    SUBCASE("testing on g1") {
      std::vector<int> traversal1;
      g1.bfs(1, traversal1);
      CHECK(traversal1[0] == 1);
      CHECK(traversal1.size() == 3);
      std::sort(traversal1.begin(), traversal1.end());
      CHECK(std::adjacent_find(traversal1.begin(), traversal1.end()) ==
            traversal1.end());
    }

    SUBCASE("testing on g2") {
      std::vector<int> traversal2;
      g2.bfs(6, traversal2);
      CHECK(traversal2[0] == 6);
      CHECK(traversal2[1] == 5);
      CHECK(traversal2[2] == 4);
      CHECK(traversal2.size() == 7);
      std::sort(traversal2.begin(), traversal2.end());
      CHECK(std::adjacent_find(traversal2.begin(), traversal2.end()) ==
            traversal2.end());
    }
  }
}
