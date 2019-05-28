#include "FullGraph.h"
/*
 * Auxiliary Function for graph
 */

void addTags(vector<Container* > &containers, vector<Station*> &stations, vector<vector<int>> &tags, vector<Vertex<Node>*> &nodes) {
    /*
    * GET NORMAL CONTAINERS
    */
    for (int i = 0; i < tags[0].size(); i++) {
        for (auto x: nodes) {
            if (x->getID() == tags[0][i]) { //found vertex with same id
                containers.push_back(new Container(x->getID(), x->getInfo().getX_Coord(), x->getInfo().getY_Coord()));
                break;
            }
        }
    }

    /*
     * GET RECYCLING CONTAINERS
     */
    for (int i = 0; i < tags[1].size(); i++) {
        for (auto x: nodes) {
            if (x->getID() == tags[1][i]) { //found vertex with same id
                types_of_waste waste = paper;//MAKE THIS RANDOM
                containers.push_back(
                        new Container(x->getID(), x->getInfo().getX_Coord(), x->getInfo().getY_Coord(), NoLimit,
                                      waste));
                break;
            }
        }
    }

    /*
     * GET STATIONS
     */
    for (int i = 0; i < tags[2].size(); i++) {
        for (auto x: nodes) {
            if (x->getID() == tags[2][i]) { //found vertex with same id
                stations.push_back(new Station(x->getID(), x->getInfo().getX_Coord(), x->getInfo().getY_Coord(), true));
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
    graph = * mapGraph.preProcessGraph();
    return this;
}

bool FullGraph::addTruck(Truck * truck) { //add truck
    trucks.push_back(truck);
    return true;
}

bool FullGraph::addStation(Station * station) { //add station
    stations.push_back(station);
    return true;
}

bool FullGraph::addContainer(Container * container) { //add container
    containers.push_back(container);
    return true;
}

vector<int> FullGraph::getContainerIds() { //get containers IDs
    return containerIds;
}



void FullGraph::showGraphViewer() {
    GraphViewer *gv = new GraphViewer(900, 900, false);
    gv->createWindow(900, 900);
    cout << "Window created" << endl;
    int id = 1;

    for (size_t i = 0; i < graph.getVertexSet().size(); i++) {
        gv->addNode(graph.getVertexSet()[i]->getID(), (graph.getVertexSet()[i]->getInfo().getX_Coord()-526000)/10, (graph.getVertexSet()[i]->getInfo().getY_Coord()-4554200)/10);
    }
    for (size_t i = 0; i < graph.getVertexSet().size(); i++) {
        for (size_t j = 0; j < graph.getVertexSet()[i]->getAdj().size(); j++) {
            gv->addEdge(id, graph.getVertexSet()[i]->getID(), graph.getVertexSet()[i]->getAdj()[j].getDest()->getID(), 1);
            id++;
        }
    }

    gv->rearrange();

    cout << "Display is done" << endl;
}
vector<Container *> FullGraph::getContainers() {
    return containers;
}

vector<Station *> FullGraph::getStations() {
    return stations;
}

vector<Truck *> FullGraph::getTrucks(){
    return trucks;
}

vector<Vertex<Node>> FullGraph::pathSingleTruckSingleContainer(Truck * t, Container * c) {
    Station * s = getStations()[0];
    Node * station = new Node(s->getID(),s->getX_Coord(),s->getY_Coord());
    cout<<"Station id"<<station->getID()<<endl;
    Node * truck = new Node(t->getID(),t->getX_Coord(),t->getY_Coord());
    cout<<"Truck id"<<truck->getID()<<endl;
    Node * container = new Node(c->getID(),c->getX_Coord(),c->getY_Coord());
    cout<<"Container id"<<container->getID()<<endl;

    vector<Node> path;
    //get path between truck and container
    path = graph.getfloydWarshallPath(*truck,*container);
    cout<<"gets through it"<<endl;
    if(path.empty()) {
        cout<<"!!first path empty!!!"<<endl;
    }

    //vector of nodes to vector of vertex
    vector<Vertex<Node>> result;
    for(auto x: path) {
        Vertex<Node> * temp = graph.findVertex(x);
        if(temp == nullptr) {
            cout<<"erros"<<endl;
            continue;
        }
        result.push_back(*temp);
    }
    return result;
}