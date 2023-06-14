#include "algorithms.h"

int64_t dijkstra_on_pq(std::vector<std::vector<int64_t>> &graph, int n, int finish) {
    std::vector<int64_t> distances(n, kInf);
    distances[0] = 0;
    std::priority_queue<std::pair<int64_t, int64_t>, std::vector<std::pair<int64_t, int64_t>>,
                        std::greater<>>
            q;
    q.emplace(0, 0);
    while (!q.empty()) {
        int64_t v = q.top().second;
        int64_t d_v = q.top().first;
        q.pop();
        if (d_v != distances[v]) {
            continue;
        }
        for (int j = 0; j < n; ++j) {
            if (graph[v][j]) {
                int64_t len = graph[v][j];
                if (distances[v] + len < distances[j]) {
                    distances[j] = distances[v] + len;
                    q.emplace(distances[j], j);
                }
            }
        }
    }
    return distances[finish];
}

int64_t ford_bellman(std::vector<std::vector<int64_t>> &graph, int n, int finish) {
    std::vector<Edge> e;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (graph[i][j]) {
                e.emplace_back(i, j, graph[i][j]);
                e.emplace_back(j, i, graph[i][j]);
            }
        }
    }
    std::vector<int64_t> d(n, kInf);
    d[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (auto &j : e) {
            if (d[j.a] < kInf) {
                if (d[j.b] > d[j.a] + j.cost) {
                    d[j.b] = std::max(-kInf, d[j.a] + j.cost);
                }
            }
        }
    }
    return d[finish];
}

int64_t floyd_warshall(std::vector<std::vector<int64_t>> &graph, int n, int finish) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (graph[i][j] == 0 && i != j) {
                graph[i][j] = kInf;
            }
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (graph[i][k] < kInf && graph[k][j] < kInf) {
                    graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }
    return graph[0][finish];
}


int64_t dijkstra_on_set(std::vector<std::vector<int64_t>> &graph, int n, int finish) {
    std::vector<int64_t> d(n, kInf), p(n);
    d[0] = 0;
    std::set<std::pair<int,int>> q;
    q.insert (std::make_pair(d[0], 0));
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (int j = 0; j < n; ++j) {
            int64_t len = graph[v][j];
            if (d[v] + len < d[j]) {
                q.erase (std::make_pair(d[j], j));
                d[j] = d[v] + len;
                q.insert(std::make_pair(d[j], j));
            }
        }
    }
    return d[finish];
}


