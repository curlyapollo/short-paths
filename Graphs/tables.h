#ifndef GRAPHS_TABLES_H
#define GRAPHS_TABLES_H

#include <iostream>
#include <fstream>
#include <vector>
#include "measurements.h"
#include "algorithms.h"
#include "generation.h"

void makeCSV_ver_graph(const std::string& name, int type);

void makeCSV_edg_graph(const std::string& name, int type);

void makeCSV_ver_algorithm(const std::string& name, int type);

void makeCSV_edg_algorithm_full(const std::string& name, int type);

void makeCSV_edg_algorithm_connected(const std::string& name, int type);

void makeCSV_edg_algorithm_tree(const std::string& name, int type);

#endif//GRAPHS_TABLES_H
