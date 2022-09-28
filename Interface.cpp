#include "Interface.h"

Interface::Interface(){}
Interface::~Interface(){}

bool Interface::run(std::vector<std::string> args_main){
    std::vector<std::string> hard_coded_word = BoardCaller.SetHardCodedWord();
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
            BoardCaller.PrintBoardInside(hard_coded_word);
        }else if(args == "exit"){
            std::cout << "Cya!" << std::endl;
            return 0;
        }else if(args.size() != hard_coded_word.size()){
            std::cout << "Palavras de 5 letras so!" << std::endl;//Mudar mais tarde
        }else{
            player_word.emplace_back(args);
            CheckCaller.TrueCheckerPrint(hard_coded_word,args,0);//pensar em maneira de dar check entre letras e adicionar um print do estado atual
            attempts++;
        }
    }while (attempts != 6);
    
}