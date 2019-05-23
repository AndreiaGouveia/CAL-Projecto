#include "Node.h"

using namespace std;

Node::Node() {
    id = 0;
    x_coord = 0;
    y_coord = 0;
}

Node::Node(int id, float x_coord, float y_coord) {
    this->id = id;
    this->x_coord = x_coord;
    this->y_coord = y_coord;
}

int Node::getID() {
    return id;
}

float Node::getX_Coord() {
    return x_coord;
}

float Node::getY_Coord() {
    return y_coord;
}

void Node::setX_Coord(float x_coord) {
    this->x_coord = x_coord;
}

void Node::setY_Coord(float y_coord) {
    this->y_coord = y_coord;
}

float Node::distance(Node &n) {
    return sqrt(pow(x_coord - n.getX_Coord(), 2) + pow(y_coord - n.getY_Coord(), 2));
}