#include "FullGraph.h"
/*
 * Auxiliary Function for graph
 */
void addTags(vector<Container* > & containers, vector<Station* > & stations,vector<vector<int>> &tags,vector<Vertex<Node>*> &nodes)
{

    /*
     * GET NORMAL CONTAINERS
     */
    for(int i : tags[0])
    {
        for (auto x: nodes) {

            if (x->getID() == i)//found vertex with same id
            {
                containers.push_back(new Container(x->getID(),x->getInfo().getX_Coord(),x->getInfo().getY_Coord()));
                break;
            }
        }

    }

    /*
     * GET RECYCLING CONTAINERS
     */
    for(int i : tags[1])
    {
        for (auto x: nodes) {

            if (x->getID() == i)//found vertex with same id
            {
                types_of_waste waste = paper;//MAKE THIS RANDOM
                containers.push_back(new Container(x->getID(),x->getInfo().getX_Coord(),x->getInfo().getY_Coord(),NoLimit,waste));
                break;
            }
        }
    }

    /*
     * GET STATIONS
     */
    for(int i : tags[2])
    {
        for (auto x: nodes) {

            if (x->getID() == i)//found vertex with same id
            {
                stations.push_back(new Station(x->getID(),x->getInfo().getX_Coord(),x->getInfo().getY_Coord(),true));
                break;
            }
        }
    }
}

FullGraph::FullGraph()
{
    LoadNodes(mapGraph);
    LoadEdges(mapGraph);

    //distributing tags
    vector<vector<int>> tags = LoadTags();
    vector<Vertex<Node>*> a =mapGraph.getVertexSet();
    addTags(containers, stations,tags,a);//containers and stations filled

}

FullGraph & FullGraph::preProcessGraph() //preprocess the graph
{
    graph = mapGraph;
    return *this;
}

bool FullGraph::addTruck(Truck * truck) //add truck
{
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

vector<int> FullGraph::getContainerIds() //get containers IDs
{
    return containerIds;
}

void FullGraph::floydWarshallShortestPath(){
    cout<< "Applying Floyd Warshall Shortest Path..."<<endl;
    graph.floydWarshallShortestPath();
    cout<< "Finished Floyd Warshall Shortest Path..."<<endl;
}

vector<Vertex<Node>  > FullGraph::pathSingleTruckSingleContainer(Truck * t, Container * c)
{
    vector<Vertex<Node>> result;
    vector<Node> temp1, temp2;

    Node * container= new Node(c->getID(),c->getX_Coord(),c->getY_Coord());
    Node * station = new Node(stations[0]->getID(),stations[0]->getX_Coord(),stations[0]->getY_Coord());

    temp1 = graph.getfloydWarshallPath(t->getInitialLocation(), *container);
    temp2 = graph.getfloydWarshallPath(*container, *station);

    //join both paths
    temp1.insert(temp1.end(), temp2.begin()+1, temp2.end());
    temp1.push_back(*station);

    //convert vector in vector of vertex
    for(auto i : temp1)
    {
        Vertex<Node> vertex = *graph.findVertex(i);
        result.push_back(vertex);
    }

    return result;
}