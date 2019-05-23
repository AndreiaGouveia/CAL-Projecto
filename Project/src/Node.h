#ifndef PROJECT_NODE_H
#define PROJECT_NODE_H

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

class Node {
protected:
    int id;
    float x_coord;
    float y_coord;
public:
    Node();
    Node(int id, float x_coord, float y_coord);
    int getID();
    float getX_Coord();
    float getY_Coord();
    void setX_Coord(float x_coord);
    void setY_Coord(float y_coord);
    float distance (Node &n);
};


#endif //PROJECT_NODE_H
