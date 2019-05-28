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
    GraphViewer *gv = new GraphViewer(900, 900, false);
    gv->createWindow(900, 900);
    cout << "Window created" << endl;
    int counter = 0;

    for (size_t i = 0; i < graph.getVertexSet().size(); i++) {
        gv->addNode(graph.getVertexSet()[i]->getID(), (graph.getVertexSet()[i]->getInfo().getX_Coord()-526000)/10, (graph.getVertexSet()[i]->getInfo().getY_Coord()-4554200)/10);
        counter++;
    }
    cout << counter << endl;

    gv->rearrange();

    cout << "Display is done" << endl;
}
vector<Container *> FullGraph::getContainers()
        {
            return containers;
        }

vector<Station *> FullGraph::getStations()
{
    return stations;
}

vector<Truck *> FullGraph::getTrucks(){
    return trucks;
}

vector<Vertex<Node>> FullGraph::pathSingleTruckSingleContainer(Node * t, Node * c)
{

    vector<Node> path;
    vector<Vertex<Node>> result;
    //get path between truck and container
    path = graph.getfloydWarshallPath(*t,*c);
    cout<<"gets through it"<<endl;
    if(path.empty())
    {
        cout<<"!!first path empty!!!"<<endl;
        return result;
    }

    //vector of nodes to vector of vertex

    for(auto x: path)
    {
        Vertex<Node> * temp = graph.findVertex(x);
        if(temp == nullptr)
        {
            cout<<"erros"<<endl;
            continue;
        }
        result.push_back(*temp);
    }

    return result;

}
vector<Vertex<Node> > FullGraph::pathOneTruckMultipleContainers(Node * t, Node * s){
    //make the containers all full
    for(auto x: containers)
    {
        x->setToRecover(true);
    }
    //we are going to use the base case functions
    //we will use only one station
    Node current = *t;
    vector<Vertex<Node>> path,path2,path3;

    int testC=0;

    while(testC!=5) {//max 5 containers per truck
        int i = 0;
        for (; i < containers.size(); i++) {
            if(!(containers[i]->getToRecover()))//if already visited
                continue;

            Node *container = new Node(containers[i]->getID(), containers[i]->getX_Coord(),containers[i]->getY_Coord());
            path2 = pathSingleTruckSingleContainer(&current, container);

            if (path2.empty()) {//couldnt reach it
                cout << "This path was empty" << endl;
                continue;
            } else {
                containers[i]->emptyContainer();//sets to recover to false
                testC++;
                path.insert(path.end(), path2.begin(), path2.end());
                current = *container;
                cout << "Added path" << endl;
            }
        }
        if(i==containers.size())
            break;
    }
if(!path2.empty())
    path.insert(path.end(),path2.begin(),path2.end());//path from truck to containers


   /* for(int i=0 ; i<stations.size(); i++)
    {
        Node *s =new Node(stations[i]->getID(),stations[i]->getX_Coord(),stations[i]->getY_Coord());
        path2 = pathSingleTruckSingleContainer(&current,s);//path from last postion to station
        if(!path2.empty())
            break;//means we found a path
    }

    if(path2.empty())
    {
        cout<<"Couldn't find a path back to station";
        return path3;//return empty
    }

    path.insert(path.end(),path2.begin(),path2.end());*/
   path3=path;
   reverse(path.begin(),path.end());
   path3.insert(path3.end(),path.begin(),path.end());
    return path3;
}
void FullGraph::testCases(){
    cout<<endl<<"==========FIRST TEST==============="<<endl;
    //test base case

    Node truck = graph.getVertexSet()[400]->getInfo();
    Node station = graph.getVertexSet()[327]->getInfo();

    Node * c = nullptr;
    for(auto x: getContainers())
    {
        c = new Node(x->getID(),x->getX_Coord(),x->getY_Coord());
       if(graph.isPathPossible(truck,*c))
       {
           break;
       }

    }

    if (c == nullptr)
    {
        cout<<"There were no compatible paths";
        exit(1);
    }

    vector<Vertex<Node>> path = pathSingleTruckSingleContainer(&truck,c),path2= pathSingleTruckSingleContainer(c,&station);

    cout<<"Fist path: "<<endl;
    for(auto x: path)
    {
        cout<<"  "<<x.getInfo().getID();
    }
    cout<<"Second path: "<<endl;
    for(auto x: path2)
    {
        cout<<"  "<<x.getInfo().getID();
    }

    path.insert(path.end(),path2.begin(),path2.end());

    if(path.empty())
        cout<<"ITS EMPTYY"<<endl;

    for(auto x: path)
    {
        cout<<"  "<<x.getInfo().getID();
    }

    /*
     * ===================================================================
     */
    cout<<endl<<"==========SECOND TEST==============="<<endl;
    //test second case

    path = pathOneTruckMultipleContainers(&truck,&station);

    if(path.empty())
        cout<<"ITS EMPTYY 2 "<<endl;

    for(auto x: path)
    {
        cout<<"  "<<x.getInfo().getID();
    }
    /*
     * ===================================================================
     */
    //test thrid case
}

void FullGraph::actualizeNodes ()
{
    for(int i=0 ; i<containers.size(); i++)
    {
        if(graph.findVertex(*containers[i]) == nullptr)
            containers.erase(containers.begin()+i);
    }

    for(int i=0 ; i<stations.size(); i++)
    {
        if(graph.findVertex(*stations[i]) == nullptr)
            stations.erase(stations.begin()+i);
    }

    for(int i=0 ; i<trucks.size(); i++)
    {
        if(graph.findVertex(*trucks[i]) == nullptr)
            trucks.erase(trucks.begin()+i);
    }

}