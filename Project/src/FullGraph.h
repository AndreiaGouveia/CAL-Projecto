#ifndef CAL_PROJECTO_FULLGRAPH_H
#define CAL_PROJECTO_FULLGRAPH_H

#include "Graph.h"
#include "Node.h"
#include "Container.h"
#include "Station.h"
#include "Truck.h"
#include "Loader.h"
#include "Utils.h"
#include "Loader.h"
#include "graphviewer.h"

class FullGraph {
public:
    /*
     * Vectors and Matrix
     */
    Graph<Node> mapGraph; //graph originated from the maps
    Graph<Node> graph; //graph after preprocess
    vector<vector< Node >> edgesMatrix; //matrix of edges
    vector<Truck *> trucks;
    vector<Container*> containers;
    vector<Station*> stations;
    vector<int> containerIds;

    /*
     * Functions
     */
    FullGraph();
    FullGraph * preProcessGraph(); //preprocess the graph -> GRAPH.H
    bool addTruck(Truck * truck); //add truck
    bool addStation(Station * station); //add station
    bool addContainer(Container * container); //add container
    vector<int> getContainerIds(); //get containers IDs
    vector<Container *> getContainers();
    vector<Station *> getStations();
    vector<Truck *> getTrucks();
    void actualizeNodes ();//updates the unprocessed vectors

    //cases
    vector<Vertex<Node>  > pathSingleTruckSingleContainer(Node * t, Node * c);
    vector<Vertex<Node>  > pathOneTruckMultipleContainers(Node * t, Node * s);

    void testCases();//tests all the cases (1/3)

    GraphViewer createGraphView();
    void showGraphViewer(GraphViewer &gv);
    void paintNodes(GraphViewer &gv);
    /*
     * Functions to still implement
     */
    //FullGraph & displayRoads();
    // FullGraph & randomizeEdges(int nIntersections);

    //vector<Vertex<Node> * > generateOneTruckMultipleContainers(Truck * t, Station * s);
    //vector<vector<Vertex<Node> * >> generateMultipleTrucskMultipleContainers(Station * s, double trucksVolume);
    //vector<Vertex<Node> *> backPreProcess(vector<Vertex<Node>* > shortenedPath);
    //void recalculateDistContainers(int currentVertexPos, bool isSort);


};


#endif //CAL_PROJECTO_FULLGRAPH_H
