#include "Interface.h"
#include <windows.h>

Interface::Interface(){}

Interface::~Interface(){}

void Interface::run(){
    //VARIABLES
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); 
    std::string hard_coded_word = "";
    std::string player_word;
    std::string args = "";
    int attempts = 0;
    bool quit_game = false;
    std::vector<std::string> player_attempts;
    std::vector<std::string> player_attempts_color;

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
                showWordSecret(hard_coded_word, player_attempts, player_attempts_color, true);
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
                    SetConsoleTextAttribute(h, 10);
                    std::cout << hard_coded_word << std::endl;
                    SetConsoleTextAttribute(h, 15);
                    break;
                    
                }else{
                    player_word = args;//lembrar de rever esta parte
                    player_attempts.emplace_back(player_word);
                    player_attempts_color = CheckCaller.TrueCheckerPrint(hard_coded_word,args,player_attempts_color);//pensar em maneira de dar check entre letras e adicionar um print do estado atual
                    attempts++;
                }
            }while (attempts != 6);
            if(args != hard_coded_word){
                std::cout << "\nPerdeu o jogo!" << std::endl;
                showWordSecret(hard_coded_word, player_attempts, player_attempts_color, false);
            }
        }else if (args == "exit"){
            quit_game = true;
        }else
            std::cout << "Comando nao reconhecido!" << std::endl;
    }while (quit_game!=true);
    // system("CLS");
    std::cout << "Cya!" << std::endl;
}

void Interface::showWordSecret(std::string word_secret, std::vector<std::string> player_attempts, std::vector<std::string> player_attempts_color, bool state_game){
    //VARIABLES
    std::cout << "Palavra: ";
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); 

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
        for (int j = 0; j < player_attempts[i].size(); j++){   
            if(player_attempts_color[i][j]=='0'){
                SetConsoleTextAttribute(h, 15);
                std::cout << player_attempts[i][j];
            }else if (player_attempts_color[i][j]=='1'){
                SetConsoleTextAttribute(h, 14);
                std::cout << player_attempts[i][j];
            }else if (player_attempts_color[i][j]=='2'){
                SetConsoleTextAttribute(h, 10);
                std::cout << player_attempts[i][j];
            }
        }
        SetConsoleTextAttribute(h, 15);
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