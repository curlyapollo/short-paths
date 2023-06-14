#include "measurements.h"

/// Прогон и замер времени алгоритма Дейкстры на приоритетной очереди. Замеров 10.
double measurement_dijkstra_on_pq(int n, std::vector<std::vector<int64_t>> &graph) {
    long long time = 0;
    for (int i = 0; i < 5; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        dijkstra_on_pq(graph, n, n - 1);
        time += std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - start).count();
    }
    return time / 5.0;
}

/// Прогон и замер времени алгоритма Форда-Беллмана. Замеров 10.
double measurement_ford_bellman(int n, std::vector<std::vector<int64_t>> &graph) {
    long long time = 0;
    for (int i = 0; i < 5; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        floyd_warshall(graph, n, n - 1);
        time += std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - start).count();
    }
    return time / 5.0;
}

/// Прогон и замер времени алгоритма Флойда-Уоршелла. Замеров 10.
double measurement_floyd_warshall(int n, std::vector<std::vector<int64_t>> &graph) {
    long long time = 0;
    for (int i = 0; i < 5; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        ford_bellman(graph, n, n - 1);
        time += std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - start).count();
    }
    return time / 5.0;
}

/// Прогон и замер времени алгоритма Дейкстры на сете. Замеров 10.
double measurement_dijkstra_on_set(int n, std::vector<std::vector<int64_t>> &graph) {
    long long time = 0;
    for (int i = 0; i < 5; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        dijkstra_on_set(graph, n, n - 1);
        time += std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - start).count();
    }
    return time / 5.0;
}
