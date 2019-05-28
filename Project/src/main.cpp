#include <iostream>
#include "FullGraph.h"

using namespace std;

int main() {
    cout << "Starting Waste Collect program" << endl;
    system("pause");

    FullGraph graph;
    graph.preProcessGraph();                        //Pre Process the graph
    graph.graph.floydWarshallShortestPath();        //get the shortest path--takes 5 min to process--
    graph.testCases();

    GraphViewer *gv = new GraphViewer(900, 900, false);

    graph.showGraphViewer(*gv);
    graph.paintNodes(*gv);*/
    system("pause");
    return 0;
}