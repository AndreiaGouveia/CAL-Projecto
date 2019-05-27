//
// Created by Andreia Gouveia on 27/05/2019.
//

#ifndef CAL_PROJECTO_FULLGRAPH_H
#define CAL_PROJECTO_FULLGRAPH_H

#include "Graph.h"
#include "Node.h"
#include "Container.h"
#include "Station.h"
#include "Truck.h"
#include "Loader.h"

class FullGraph {

public:

    /*
     * Vectors and Matrix
     */
    Graph<Node> * mapGraph; //graph originated from the maps
    Graph<Node> * graph; //graph after preprocess
    vector<vector< Node >> edgesMatrix; //matrix of edges
    vector<Truck *> trucks;
    vector<Container*> containers;
    vector<Station *> stations;

    /*
     * Functions
     */
    FullGraph();

    FullGraph & preProcessGraph(); //preprocess the graph

    bool addTruck(Truck * truck); //add truck

    bool addStation(Station * station); //add station

    bool addContainer(Container * container); //add container

    vector<string> getContainerIds(); //get containers IDs

    /*
     * Functions to still implement
     */
    //FullGraph & displayRoads();
    // FullGraph & randomizeEdges(int nIntersections);
    //vector<Vertex<Node> * > generateSingleTruckSingleContainer(Truck * t, Container * c);
    //vector<Vertex<Node> * > generateOneTruckMultipleContainers(Truck * t, Station * s);
    //vector<vector<Vertex<Node> * >> generateMultipleTrucskMultipleContainers(Station * s, double trucksVolume);
    //void floydWarshallShortestPath();
    //vector<Vertex<Node> *> backPreProcess(vector<Vertex<Node>* > shortenedPath);
    //void recalculateDistContainers(int currentVertexPos, bool isSort);


};


#endif //CAL_PROJECTO_FULLGRAPH_H
