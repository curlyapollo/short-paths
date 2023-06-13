#ifndef GRAPHS_ALGORITHMS_H
#define GRAPHS_ALGORITHMS_H
#include <iostream>
#include <vector>
#include <queue>
#include <set>

struct Edge {
    int64_t a, b, cost;

    Edge(int st, int fn, int c) {
        a = st;
        b = fn;
        cost = c;
    }
};

const int64_t kInf = 1000000000000;

int64_t dijkstra_on_pq(std::vector<std::vector<int64_t>> &graph, int n, int finish);

int64_t ford_bellman(std::vector<std::vector<int64_t>> &graph, int n, int finish);

int64_t floyd_warshall(std::vector<std::vector<int64_t>> &graph, int n, int finish);

int64_t dijkstra_on_set(std::vector<std::vector<int64_t>> &graph, int n, int finish);

#endif
