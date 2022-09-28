#include "Board.h"

Board::Board(){}
Board::~Board(){}

std::vector<std::string> Board::SetHardCodedWord(){
    std::vector<std::string> hard_coded_word;

    hard_coded_word.emplace_back("teste");
    // hard_coded_board.emplace_back("certo");
    // hard_coded_board.emplace_back("cinco");
    // hard_coded_board.emplace_back("vinho");
    // hard_coded_board.emplace_back("grupo");
    // hard_coded_board.emplace_back("termo");
    // hard_coded_board.emplace_back("gerar");
    // hard_coded_board.emplace_back("visao");
    // hard_coded_board.emplace_back("chama");
    // hard_coded_board.emplace_back("gerir");

    return hard_coded_word;
}

void Board::PrintBoardInside(std::vector<std::string> hard_coded_word){
    for (int i = 0; i < hard_coded_word.size(); i++){
        std::cout << hard_coded_word[i] << std::endl;
    }
}