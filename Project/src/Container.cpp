#include "Conainer.h"

using namespace std;

Container::Container() {
    max_capacity_rate= 0.75;
    waste = domestic;
    capacity = 0;
    capacity_rate = 0.0;
};

Container::Container(float max, enum types_of_waste waste) {
    max_capacity = maz;
    max_capacity_rate =0.75;
    this->waste = waste;
    capacity = 0;
    capacity_rate = 0.0;
}

int Container::getMax_capacity_rate() {
    return max_capacity_rate;
}

void setMax_capacity_rate(float rate)) {
    max_capacity_rate = rate;
}

enum types_of_waste Container::getWaste() {
    return waste;
}

void Container::setWaste(enum types_of_waste waste) {
    this->waste = waste;
}

float Container::getCapacity() {
    return capacity;
}

float Container::getCapacityRate() {
    return capacity_rate;
}

void Container::updateCapacity(float waste_volume) {
    if ((capacity + waste_volume) <= max_capacity && capacity_rate <= 100.0) {
        capacity += waste_volume;
        capacity_rate = (capacity / volume) * 100;
    }
}