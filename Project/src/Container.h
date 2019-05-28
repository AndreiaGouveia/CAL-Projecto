#ifndef PROJECT_CONTAINER_H
#define PROJECT_CONTAINER_H

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <ctime>
#include <cstdlib>
#include "Node.h"
#include "Utils.h"

class Container : public Node {
    enum types_of_waste waste;      //type of waste of the container
    float max_capacity;             //max capacity that a container can have
    float capacity;                 //current capacity of the container
    float capacity_rate;            //percentage currently occupied
    bool toRecover;                 //bool that allows to know if a container should be picked up or not
    int a = 101, b = 0;             //waste
public:
    Container(int id, float x, float y);    //Default constructor
    Container(int id, float x, float y,float max, enum types_of_waste waste);   //limited capacity truck
    enum types_of_waste getWaste(); //gets the type of waste
    void setWaste(enum types_of_waste waste);   //sets the type of waste
    float getCapacity();    //gets container capacity
    float getCapacityRate();    //gets the capacity Rate
    bool getToRecover();    //gets the bool that tells if a container should be picked up or not
    void setToRecover(bool recover);    //sets the bool that tells if a container should be picked up or not
    void updateCapacity();  //updates container capacity
    void emptyContainer();  //empties container
};


#endif //PROJECT_CONTAINER_H