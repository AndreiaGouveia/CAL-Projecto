#include <iostream>
#include "FullGraph.h"

using namespace std;

int main() {
    cout << "Starting Waste Collect program" << endl;
    cout << "Press ENTER" << endl;
    system("pause");

    FullGraph graph;
    graph.preProcessGraph();
    graph.graph.floydWarshallShortestPath();//get the shortest path--takes 5 min to process--
    graph.testCases();

    GraphViewer *gv = new GraphViewer(900, 900, false);
    gv->createWindow(900, 900);

    graph.showGraphViewer(*gv);
    graph.paintNodes(*gv);
    system("pause");
    return 0;
}