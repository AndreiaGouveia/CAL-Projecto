#ifndef PROJECT_TRUCK_H
#define PROJECT_TRUCK_H

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

class Truck {
    int volume;
    enum types_of_waste waste;
    float capacity;                 //capacity of the truck occupied with garbage
    float capacity_rate;            //percentage occupied;
public:
    Truck();                                        //unlimited capacity truck
    Truck(int volume, enum types_of_waste waste);   //limited capacity truck
    int getVolume();
    void setVolume(int volume);             //set new truck volume
    enum types_of_waste getWaste();
    void setWaste(enum types_of_waste waste);
    float getCapacity();
    float getCapacityRate();
    void updateCapacity(float waste_volume);
};


#endif //PROJECT_TRUCK_H
