#include "Truck.h"

using namespace std;

int Truck::idg = 1;

Truck::Truck() : id(idg++) {
    volume = INF;
    waste = domestic;
    capacity = 0;
    capacity_rate = 0.0;
}

Truck::Truck(int volume, enum types_of_waste waste) : id(idg++) {
    this->volume = volume;
    this->waste = waste;
    capacity = 0;
    capacity_rate = 0.0;
}

int Truck::getVolume() {
    return volume;
}

void Truck::setVolume(int volume) {
    this->volume = volume;
}

enum types_of_waste Truck::getWaste() {
    return waste;
}

void Truck::setWaste(enum types_of_waste waste) {
    this->waste = waste;
}

int Truck::getID() {
    return id;
}

float Truck::getCapacity() {
    return capacity;
}

float Truck::getCapacityRate() {
    return capacity_rate;
}

void Truck::updateCapacity(float waste_volume) {
    if ((capacity + waste_volume) <= volume && capacity_rate <= 100.0) {
        capacity += waste_volume;
        capacity_rate = (capacity/volume) * 100;
    }
    else {
        // Vai direto para a central
    }
}

Node Truck::getInitialLocation(){
    return initialLocation;
}