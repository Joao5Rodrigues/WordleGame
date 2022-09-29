#include "Board.h"
#include <ctime>
#include <limits>

Board::Board(){}
Board::~Board(){}

std::string Board::SetHardCodedWord(){
    srand((unsigned int)time(NULL));

    //VARIABLES
    std::fstream file("palavras.txt");
    std::string hard_coded_word;
    std::string line;

    int random_number = 0;

    bool create_word = true;
    bool get_word = true;
    do{
        if(get_word && (random_number <= 0 || random_number >= 1162242)){
            random_number = std::rand();
        }else
            get_word = false;
    } while (get_word);

    
    if(!file.is_open())
        return "teste";
    for (int i = 1; i <= random_number; i++){
        std::getline(file,hard_coded_word);
    }

    return hard_coded_word;
}

void Board::PrintBoardInside(std::string hard_coded_word){
    for (int i = 0; i < hard_coded_word.size(); i++){
        std::cout << hard_coded_word << std::endl;
    }
}