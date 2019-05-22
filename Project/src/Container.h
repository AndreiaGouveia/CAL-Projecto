#ifndef PROJECT_CONTAINER_H
#define PROJECT_CONTAINER_H

#include <iostream>
#include <vector>
#include <string>
#include <limits>

#define INF numeric_limits<int>::max()

enum types_of_waste {
    paper,
    plastic,
    glass,
    domestic
};

class Container {
    enum types_of_waste waste;
    float max_capacity_rate;        //max that is interesting for a truck to pick up
    float max_capacity;             //max capacity that a container can have
    float capacity;                 //current capacity of the container
    float capacity_rate;            //percentage currently occupied
public:
    Container();
    Container(float max, enum types_of_waste waste);   //limited capacity truck
    int getMax_capacity_rate();
    void setMax_capacity_rate(float rate);             //set new truck volume
    enum types_of_waste getWaste();
    void setWaste(enum types_of_waste waste);
    float getCapacity();
    float getCapacityRate();
    void updateCapacity(float waste_volume);
};


#endif //PROJECT_CONTAINER_H