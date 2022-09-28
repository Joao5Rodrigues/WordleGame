#ifndef BOARD_H
#define BOARD_H

#include "DefaultIncludes.h"
class Board{
private:
public:
    Board();
    ~Board();

    std::vector<std::string> SetHardCodedWord();
    void PrintBoardInside(std::vector<std::string> hard_coded_word);
};




#endif //BOARD_H