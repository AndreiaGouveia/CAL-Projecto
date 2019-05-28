#include "FullGraph.h"
/*
 * Auxiliary Function for graph
 */

void addTags(vector<Container* > &containers, vector<Station*> &stations, vector<vector<int>> &tags, vector<Vertex<Node>*> &nodes) {
    /*
     * GET NORMAL CONTAINERS
     */
    for(int i : tags[0]) {
        for (auto x: nodes) {
            if (x->getID() == i) {
                containers.push_back(new Container(x->getID(), x->getInfo().getX_Coord(), x->getInfo().getY_Coord()));
                break;
            }
        }

    }
    /*
     * GET RECYCLING CONTAINERS
     */
    for(int i : tags[1]) {
        for (auto node : nodes) {
            if (node->getID() == i) { //found vertex with same id
                types_of_waste waste = paper;//MAKE THIS RANDOM
                containers.push_back(new Container(node->getID(), node->getInfo().getX_Coord(), node->getInfo().getY_Coord(), NoLimit, waste));
                break;
            }
        }
    }
    /*
     * GET STATIONS
     */
    for(int i : tags[2]) {
        for (auto node : nodes) {
            if (node->getID() == tags[2][i]) {     //found vertex with same id
                stations.push_back(new Station(node->getID(), node->getInfo().getX_Coord(), node->getInfo().getY_Coord(), true));
                break;
            }
        }
    }
}

FullGraph::FullGraph() {
    LoadNodes(mapGraph);
    LoadEdges(mapGraph);

    //distributing tags
    vector<vector<int>> tags = LoadTags();
    vector<Vertex<Node>*> nodes = mapGraph.getVertexSet();
    addTags(containers, stations, tags, nodes);//containers and stations filled

}

FullGraph *FullGraph::preProcessGraph() { //preprocess the graph
    mapGraph = * graph.preProcessGraph();
    return this;
}

bool FullGraph::addTruck(Truck * truck) { //add truck
    trucks.push_back(truck);
    return true;
}

bool FullGraph::addStation(Station * station) //add station
{
    stations.push_back(station);
    return true;
}

bool FullGraph::addContainer(Container * container) //add container
{
    containers.push_back(container);
    return true;
}

vector<int> FullGraph::getContainerIds() { //get containers IDs
    return containerIds;
}

void FullGraph::showGraphViewer() {
    /*GraphViewer *gv = new GraphViewer(2000, 2000, false);
    gv->createWindow(1000, 1000);

    for (size_t i = 0; i < graph.getVertexSet().size(); i++) {

    }*/
}
