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
}

