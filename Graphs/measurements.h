#ifndef GRAPHS_MEASUREMENTS_H
#define GRAPHS_MEASUREMENTS_H

#include <iostream>
#include "generation.h"
#include "algorithms.h"

double measurement_dijkstra_on_pq(int n, std::vector<std::vector<int64_t>> &graph);

double measurement_ford_bellman(int n, std::vector<std::vector<int64_t>> &graph);

double measurement_floyd_warshall(int n, std::vector<std::vector<int64_t>> &graph);

double measurement_dijkstra_on_set(int n, std::vector<std::vector<int64_t>> &graph);

#endif//GRAPHS_MEASUREMENTS_H
