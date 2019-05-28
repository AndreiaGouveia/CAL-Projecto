#include "Container.h"

using namespace std;

Container::Container(int id, float x, float y):Node(id, x, y){
    max_capacity = NoLimit;
    waste = domestic;
    capacity = 0;
    capacity_rate = 0.0;
    toRecover = false;
};

Container::Container(int id, float x, float y,float max, enum types_of_waste waste):Node(id, x, y) {
    max_capacity = max;
    this->waste = waste;
    capacity = 0;
    capacity_rate = 0.0;
    toRecover = false;
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

bool Container::getToRecover() {
    return toRecover;
}

void Container::setToRecover(bool recover) {
    this->toRecover = recover;
}

/**
 * Function that updates the content of a container
 * like if a day has passed and people have filled the container
 */
void Container::updateCapacity() {
    float r = rand() % a + b;
    a = 101-r;
    b = r;
    capacity = (r/100) * max_capacity;
    capacity_rate = (r/100);

    if (capacity_rate > 0.75) {
        cout << "Needs recover" << endl;
        setToRecover(true);
    }
}

/**
 * Function that simulates the collect of a container
 * like when the waste is collected by the workers day by day
 */
void Container::emptyContainer() {
    a = 101;
    b = 0;
    capacity = 0;
    capacity_rate = 0.0;
    setToRecover(false);
}
