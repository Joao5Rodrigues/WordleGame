#include "Interface.h"

Interface::Interface(){}

Interface::~Interface(){}

void Interface::run(){
    std::string hard_coded_word = BoardCaller.SetHardCodedWord();
    std::string player_word;
    std::string args = "";
    int attempts = 0;

    //Presentation
    std::cout << "Bem vindo!" << std::endl;

    //Running Code in single Word mode
    do{    
        std::cout << "Insira uma palavra: ";
        std::cin >> args;
        
        if(args == "cheat"){
            BoardCaller.PrintBoardInside(hard_coded_word);
        }else if(args == "exit"){
            std::cout << "Cya!" << std::endl;
            return;
        }else if(args.size() != hard_coded_word.size()){
            std::cout << "Palavras de " << std::to_string(hard_coded_word.size()) << " letras!" << std::endl;//Mudar mais tarde
        }else{
            player_word = args;//lembrar de rever esta parte
            CheckCaller.TrueCheckerPrint(hard_coded_word,args);//pensar em maneira de dar check entre letras e adicionar um print do estado atual
            attempts++;
        }
    }while (attempts != 6);
    
}