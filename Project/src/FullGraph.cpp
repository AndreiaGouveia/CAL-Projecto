//
// Created by Andreia Gouveia on 27/05/2019.
//

#include "FullGraph.h"

FullGraph::FullGraph()
{
    LoadNodes(*mapGraph);
    LoadEdges(*mapGraph);
    vector<vector<int>> tags = LoadTags();

    int i=0;
    for ( ; i<tags[0].size() ; i++)
    {
        containers.push_back(new Container(tags[0][i],))
    }

}

FullGraph & FullGraph::preProcessGraph() //preprocess the graph
{

}

bool FullGraph::addTruck(Truck * truck) //add truck
{
    trucks.push_back(truck);
}

bool FullGraph::addStation(Station * station) //add station
{
    stations.push_back(station);
}

bool FullGraph::addContainer(Container * container) //add container
{
    containers.push_back(container);
}

vector<string> FullGraph::getContainerIds() //get containers IDs
{

}