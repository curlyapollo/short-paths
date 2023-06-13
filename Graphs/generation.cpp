#include "generation.h"

std::vector<std::vector<int64_t>> full(int n) {
    srand(time(nullptr));
    std::vector<std::vector<int64_t>> g(n, std::vector<int64_t>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int w = rand() % 10 + 1;
            g[i][j] = w;
            g[j][i] = w;
        }
    }
    return g;
}

std::vector<std::vector<int64_t>> connected(int n) {
    srand(time(nullptr));
    std::vector<std::vector<int64_t>> g(n, std::vector<int64_t>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (rand() % 2) {
                int w = rand() % 10 + 1;
                g[i][j] = w;
                g[j][i] = w;
            }
        }
    }
    return g;
}

std::vector<std::vector<int64_t>> tree(int n) {
    srand(time(nullptr));
    std::vector<std::vector<int64_t>> g(n, std::vector<int64_t>(n));
    for (int i = 0; i < n - 1; ++i) {
        int w = rand() % 10 + 1;
        g[i][i + 1] = w;
        g[i + 1][i] = w;
    }
    return g;
}