#include "DefaultIncludes.h"
//#include "Board.h"
#include "Checker.h"

std::vector<std::string> SetHardCodedWord(){
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

void PrintBoardInside(std::vector<std::string> hard_coded_word){
    for (int i = 0; i < hard_coded_word.size(); i++)
    {
        std::cout << hard_coded_word[i] << std::endl;
    }
}




int main(){
    //Variables
    std::vector<std::string> hard_coded_word = SetHardCodedWord();
    std::vector<std::string> player_word;
    std::string args = "";
    int attempts = 0;

    //Presentation
    std::cout << "Bem vindo!" << std::endl;

    //Running Code in single Word mode
    do{    
        std::cout << "Insira uma palavra: ";
        std::cin >> args;
        
        if(args == "cheat"){
            PrintBoardInside(hard_coded_word);
        }else if(args == "exit"){
            std::cout << "Cya!" << std::endl;
            return 0;
        }else if(args.size() != 5){
            std::cout << "Palavras de 5 letras so!" << std::endl;
        }else{
            player_word.emplace_back(args);
            TrueCheckerPrint(hard_coded_word,args,0);//pensar em maneira de dar check entre letras e adicionar um print do estado atual
            attempts++;
        }
    } while (attempts != 6);
    
    //END
    return 0;
}