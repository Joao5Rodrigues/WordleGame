#ifndef INTERFACE_H
#define INTERFACE_H

#include "DefaultIncludes.h"
#include "Checker.h"
#include "Board.h"

class Interface{
private:
    Checker CheckCaller;
    Board BoardCaller;
public:
    void run();
    Interface();
    ~Interface();
};


#endif //INTERFACE_H