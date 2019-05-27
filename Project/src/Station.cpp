//
// Created by Andreia Gouveia on 26/05/2019.
//

#include "Station.h"

Station:: Station(int id, float x, float y, bool station):Node(id,x,y){
    this->station = station;
};

bool Station::isStation(){
    return station;
}