#include "tables.h"

int edges(std::vector<std::vector<int64_t>> &graph, int n) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (graph[i][j]) {
                cnt++;
            }
        }
    }
    return cnt;
}

void makeCSV_ver_graph(const std::string& name, int type) {
    std::ofstream fout;
    fout.open("../csv/" + name + ".csv", std::ofstream::out | std::ofstream::trunc);
    fout << "Vertexes;Dijkstra on pq;Ford-Bellman;Floyd-Warshall;Dijkstra on set\n";
    std::cout << "[";
    for (int i = 10; i < 1011; i += 50) {
        std::vector<std::vector<int64_t>> graph;
        if (type == 0) {
            graph = full(i);
        } else if (type == 1) {
            graph = connected(i);
        } else {
            graph = tree(i);
        }
        fout << i << ";" << measurement_dijkstra_on_pq(i, graph) << ";" <<
                measurement_ford_bellman(i, graph) << ";" <<
                measurement_floyd_warshall(i, graph) << ";" <<
                measurement_dijkstra_on_set(i, graph) << "\n";
        std::cout << ".";
    }
    std::cout << "]\n";
}

void makeCSV_edg_graph(const std::string& name, int type) {
    std::ofstream fout;
    fout.open("../csv/" + name + ".csv", std::ofstream::out | std::ofstream::trunc);
    fout << "Edges;Dijkstra on pq;Ford-Bellman;Floyd-Warshall;Dijkstra on set\n";
    std::cout << "[";
    for (int i = 10; i < 1011; i += 50) {
        std::vector<std::vector<int64_t>> graph;
        if (type == 0) {
            graph = full(i);
        } else if (type == 1) {
            graph = connected(i);
        } else {
            graph = tree(i);
        }
        fout << edges(graph, i) << ";" << measurement_dijkstra_on_pq(i, graph) << ";" <<
                measurement_ford_bellman(i, graph) << ";" <<
                measurement_floyd_warshall(i, graph) << ";" <<
                measurement_dijkstra_on_set(i, graph) << "\n";
        std::cout << '.';
    }
    std::cout << "]\n";
}

void makeCSV_ver_algorithm(const std::string& name, int type) {
    std::ofstream fout;
    fout.open("../csv/" + name + ".csv", std::ofstream::out | std::ofstream::trunc);
    fout << "Vertexes;Full;Connected;Tree\n";
    std::cout << "[";
    for (int i = 10; i < 1011; i += 50) {
        std::vector<std::vector<int64_t>> graph1 = full(i);
        std::vector<std::vector<int64_t>> graph2 = connected(i);
        std::vector<std::vector<int64_t>> graph3 = tree(i);
        if (type == 0) {
            fout << i << ";" << measurement_dijkstra_on_pq(i, graph1) << ";" <<
                    measurement_dijkstra_on_pq(i, graph2) << ";" <<
                    measurement_dijkstra_on_pq(i, graph3) << "\n";
        } else if (type == 1) {
            fout << i << ";" << measurement_ford_bellman(i, graph1) << ";" <<
                    measurement_ford_bellman(i, graph2) << ";" <<
                    measurement_ford_bellman(i, graph3) << "\n";
        } else if (type == 2) {
            fout << i << ";" << measurement_floyd_warshall(i, graph1) << ";" <<
                    measurement_floyd_warshall(i, graph2) << ";" <<
                    measurement_floyd_warshall(i, graph3) << "\n";
        } else {
            fout << i << ";" << measurement_dijkstra_on_set(i, graph1) << ";" <<
                    measurement_dijkstra_on_set(i, graph2) << ";" <<
                    measurement_dijkstra_on_set(i, graph3) << "\n";
        }
        std::cout << ".";
    }
    std::cout << "]\n";
}

void makeCSV_edg_algorithm_full(const std::string& name, int type) {
    std::ofstream fout;
    fout.open("../csv/" + name + ".csv", std::ofstream::out | std::ofstream::trunc);
    fout << "Edges;Full\n";
    std::cout << '[';
    for (int i = 10; i < 1011; i += 50) {
        std::vector<std::vector<int64_t>> graph = full(i);
        if (type == 0) {
            fout << edges(graph, i) << ";" << measurement_dijkstra_on_pq(i, graph) << "\n";
        } else if (type == 1) {
            fout << edges(graph, i) << ";" << measurement_ford_bellman(i, graph) << "\n";
        } else if (type == 2) {
            fout << edges(graph, i) << ";" << measurement_floyd_warshall(i, graph) << "\n";
        } else {
            fout << edges(graph, i) << ";" << measurement_dijkstra_on_set(i, graph) << "\n";
        }
        std::cout << '.';
    }
    std::cout << "]\n";
}

void makeCSV_edg_algorithm_connected(const std::string& name, int type) {
    std::ofstream fout;
    fout.open("../csv/" + name + ".csv", std::ofstream::out | std::ofstream::trunc);
    fout << "Edges;Connected\n";
    std::cout << '[';
    for (int i = 10; i < 1011; i += 50) {
        std::vector<std::vector<int64_t>> graph = connected(i);
        if (type == 0) {
            fout << edges(graph, i) << ";" << measurement_dijkstra_on_pq(i, graph) << "\n";
        } else if (type == 1) {
            fout << edges(graph, i) << ";" << measurement_ford_bellman(i, graph) << "\n";
        } else if (type == 2) {
            fout << edges(graph, i) << ";" << measurement_floyd_warshall(i, graph) << "\n";
        } else {
            fout << edges(graph, i) << ";" << measurement_dijkstra_on_set(i, graph) << "\n";
        }
        std::cout << '.';
    }
    std::cout << "]\n";
}

void makeCSV_edg_algorithm_tree(const std::string& name, int type) {
    std::ofstream fout;
    fout.open("../csv/" + name + ".csv", std::ofstream::out | std::ofstream::trunc);
    fout << "Edges;Tree\n";
    std::cout << "[";
    for (int i = 10; i < 1011; i += 50) {
        std::vector<std::vector<int64_t>> graph = tree(i);
        if (type == 0) {
            fout << edges(graph, i) << ";" << measurement_dijkstra_on_pq(i, graph) << "\n";
        } else if (type == 1) {
            fout << edges(graph, i) << ";" << measurement_ford_bellman(i, graph) << "\n";
        } else if (type == 2) {
            fout << edges(graph, i) << ";" << measurement_floyd_warshall(i, graph) << "\n";
        } else {
            fout << edges(graph, i) << ";" << measurement_dijkstra_on_set(i, graph) << "\n";
        }
        std::cout << '.';
    }
    std::cout << "]\n";
}