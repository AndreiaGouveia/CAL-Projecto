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
    enum types_of_waste waste;
    float max_capacity;             //max capacity that a container can have
    float capacity;                 //current capacity of the container
    float capacity_rate;            //percentage currently occupied
    bool toRecover;
    int a = 101, b = 0;
public:
    Container();
    Container(float max, enum types_of_waste waste);   //limited capacity truck
    enum types_of_waste getWaste();
    void setWaste(enum types_of_waste waste);
    float getCapacity();
    float getCapacityRate();
    bool getToRecover();
    void setToRecover(bool recover);
    void updateCapacity();
    void emptyContainer();
};


#endif //PROJECT_CONTAINER_H