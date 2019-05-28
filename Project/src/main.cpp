#include <iostream>
#include "FullGraph.h"

using namespace std;

int main() {
    FullGraph graph;
    graph.preProcessGraph();
    graph.graph.floydWarshallShortestPath();//get the shortest path--takes 5 min to process--
    graph.testCases();
    system("pause");
    return 0;
}