#include "Interface.h"
#include <stdlib.h>

Interface::Interface(){}

Interface::~Interface(){}

void Interface::run(){
    //VARIABLES
    std::string hard_coded_word = "";
    std::string player_word;
    std::string args = "";
    int attempts = 0;
    bool quit_game = false;
    std::vector<std::string> player_attempts;

    //CODE
    // system("CLS");
    do{
        //Presentation
        std::cout << "\nBem vindo!" << std::endl;
        std::cout << "1)Novo jogo - start" << std::endl;
        std::cout << "2)Sair do jogo - exit" << std::endl;
        std::cin >> args;
        // system("CLS");
        if (args =="start"){
            //Running Code in single Word mode
            hard_coded_word = BoardCaller.SetHardCodedWord();
            do{    
                std::cout << "\nEscreva <exit> para sair para o menu do jogo!" << std::endl;
                showWordSecret(hard_coded_word, player_attempts, true);
                PrintKeyboard();
                std::cout << "\nInsira uma palavra: ";
                std::cin >> args;
                // system("CLS");
                
                if(args == "konami_code"){
                    BoardCaller.PrintBoardInside(hard_coded_word);
                }else if(args == "exit"){
                    break;
                }else if(args.size() != hard_coded_word.size()){
                    std::cout << "Palavras de " << std::to_string(hard_coded_word.size()) << " letras!" << std::endl;//Mudar mais tarde
                }else if(VerifyPlayerWord(args)){
                    std::cout << "Palavra nao existe no dicionario!" << std::endl;//checks if players inserted a word that is in the dictionary
                }else if(args == hard_coded_word){
                    //ACABAR RESTRIÇÕES E PROGRESSO
                    std::cout << "Ganhou! A palavra era ";
                    std::cout << hard_coded_word << std::endl;
                    break;
                }else{
                    player_word = args;//lembrar de rever esta parte
                    player_attempts.emplace_back(player_word);
                    CheckCaller.TrueCheckerPrint(hard_coded_word,args);//pensar em maneira de dar check entre letras e adicionar um print do estado atual
                    attempts++;
                }
            }while (attempts != 6);
            if(args != hard_coded_word){
                std::cout << "\nPerdeu o jogo!" << std::endl;
                showWordSecret(hard_coded_word, player_attempts, false);
            }
        }else if (args == "exit"){
            quit_game = true;
        }else
            std::cout << "Comando nao reconhecido!" << std::endl;
    }while (quit_game!=true);
    // system("CLS");
    std::cout << "Cya!" << std::endl;
}

void Interface::showWordSecret(std::string word_secret, std::vector<std::string> player_attempts, bool state_game){
    //VARIABLES
    std::cout << "Palavra: ";

    //CODE
    if(state_game){
        for (size_t i = 0; i < word_secret.size(); i++){
            std::cout << "_";
        }
    }else{
        std::cout << word_secret << std::endl;
    }

    for (int i = 0; i < player_attempts.size(); i++){
        putchar('\n');
        std::cout << player_attempts[i];
    }
}

bool Interface::VerifyPlayerWord(std::string word){
    //VARIABLES
    std::fstream file("palavras.txt");
    std::string ler;

    //CODE 
    if(!file.is_open())
        return true;

    while(std::getline(file,ler)){
        if (word == ler){
            return false;
        }
    }

    return true;    
}

void Interface::PrintKeyboard(){
    putchar('\n');
    std::cout <<    ",---,---,---,---,---,---,---,---,---,---,---,---,---,-------," << std::endl;
    std::cout <<    "|   |   |   |   |   |   |   |   |   |   |   |   |   |       |" << std::endl;
    std::cout <<    "|---,-,-'-,-'-,-|-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-----|" << std::endl;
    std::cout <<    "|     | Q | W | E | R | T | Y | U | I | O | P |   |   |     |" << std::endl;
    std::cout <<    "|-----',--',--',--',--',--',--',--',--',--',--',--',--'|    |" << std::endl;
    std::cout <<    "|      | A | S | D | F | G | H | J | K | L |   |   |   |    |" << std::endl;
    std::cout <<    "|----,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'---'----|" << std::endl;
    std::cout <<    "|    |   | Z | X | C | V | B | N | M |   |   |   |          |" << std::endl;
    std::cout <<    "|----'-,-',--'--,'---'---'---'---'---'---'-,-'---',--,------|" << std::endl;
    std::cout <<    "|      |  |     |                          |      |  |      |" << std::endl;
    std::cout <<    "'------'--'-----'--------------------------'------'--'------'" << std::endl;
}