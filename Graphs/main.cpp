#include <iostream>
#include "tables.h"


int main() {
    std::vector<std::string>  graphs {"full", "connected", "tree"};
    std::vector<std::string>  algorithms {"dijkstra-on-pq", "ford-bellman", "floyd-warshall", "dijkstra-on-set"};

    int cnt = 1;
    for (int i = 0; i < 3; ++i) {
        makeCSV_ver_graph("vertexes-graph-" + graphs[i], i);
        std::cout << cnt++ << '\n';
        makeCSV_edg_graph("edges-graph-" + graphs[i], i);
        std::cout << cnt++ << '\n';
    }
    for (int i = 0; i < 4; ++i) {
        makeCSV_ver_algorithm("vertexes-algorithms-" + algorithms[i], i);
        std::cout << cnt++ << '\n';
        makeCSV_edg_algorithm_full("edges-algorithms-full-" + algorithms[i], i);
        std::cout << cnt++ << '\n';
        makeCSV_edg_algorithm_connected("edges-algorithms-connected-" + algorithms[i], i);
        std::cout << cnt++ << '\n';
        makeCSV_edg_algorithm_tree("edges-algorithms-tree-" + algorithms[i], i);
        std::cout << cnt++ << '\n';
    }
}
