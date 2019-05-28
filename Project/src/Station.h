#ifndef CAL_PROJECTO_SATION_H
#define CAL_PROJECTO_SATION_H

#include "Node.h"


class Station : public Node {

private:
    bool station; //temporary, dunno what to put here, to MODIFY

public:
    Station(int id, float x, float y, bool station);
    bool isStation();

};


#endif //CAL_PROJECTO_SATION_H
