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
    void showWordSecret(std::string word_secret, std::vector<std::string> player_attempts, bool state_game);
    Interface();
    ~Interface();
};


#endif //INTERFACE_H