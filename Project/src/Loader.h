#ifndef PROJECT_LOADER_H
#define PROJECT_LOADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "Graph.h"
#include "Node.h"
#include <algorithm>
#include "Station.h"


void LoadNodes(Graph<Node> & graph);
void LoadEdges(Graph<Node> & graph);
vector<vector<int>> LoadTags();


#endif //PROJECT_LOADER_H*/
