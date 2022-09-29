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
    void showWordSecret(std::string word_secret, std::vector<std::string> player_attempts, std::vector<std::string> player_attempts_color, bool state_game);
    bool VerifyPlayerWord(std::string word);
    void PrintKeyboard();
    // std::vector<float> calc_percentagem(std::vector<std::string> player_attempts_color, std::vector<float> num);
    Interface();
    ~Interface();
};


#endif //INTERFACE_H