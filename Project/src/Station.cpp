#include "Station.h"

Station:: Station(int id, float x, float y, bool station):Node(id,x,y){
    this->station = station;
};

bool Station::isStation(){
    return station;
}