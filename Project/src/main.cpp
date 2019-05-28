#include <iostream>
#include "FullGraph.h"

using namespace std;

int main() {
    FullGraph graph;
    graph.preProcessGraph();
    Node truck = graph.graph.getVertexSet()[0]->getInfo();
    Node station = graph.graph.getVertexSet()[1]->getInfo();
    Container * temp = graph.getContainers()[0];
    Truck t(truck);
    Station *s = new Station(station.getID(),station.getX_Coord(),station.getY_Coord(),true);
    graph.addStation(s);
    vector<Vertex<Node>> path = graph.pathSingleTruckSingleContainer(&t,temp);

    if(path.empty())
        cout<<"ITS EMPTYY"<<endl;
    for(auto x: path)
    {
        cout<<"  "<<x.getInfo().getID();
    }
    system("pause");
    return 0;
}