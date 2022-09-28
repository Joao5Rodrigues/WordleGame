#include "DefaultIncludes.h"
//#include "Board.h"

std::vector<std::string> SetHardCodedBoard(){
    std::vector<std::string> hard_coded_board;

    hard_coded_board.emplace_back("teste");
    hard_coded_board.emplace_back("certo");
    hard_coded_board.emplace_back("cinco");
    hard_coded_board.emplace_back("vinho");
    hard_coded_board.emplace_back("grupo");
    hard_coded_board.emplace_back("termo");
    hard_coded_board.emplace_back("gerar");
    hard_coded_board.emplace_back("visao");
    hard_coded_board.emplace_back("chama");
    hard_coded_board.emplace_back("gerir");

    return hard_coded_board;
}

void PrintBoardInside(std::vector<std::string> hard_coded_board){
    for (int i = 0; i < 5; i++)
    {
        std::cout << hard_coded_board[i] << std::endl;
    }
}

bool SecondCheck(std::string palavra, char c){
    for (int i = 0; i < palavra.size(); i++){
        if(palavra[i]==c)
            return true;
    }
    return false;
}

void ReceiveCheck(std::vector<std::string> hard_coded_board, std::string args, int num){
    std::string check = "";
    for (int i = 0; i < hard_coded_board[num].size(); i++){

        if(hard_coded_board[num][i] == args[i]){
            check += "2";//posição certa

        }else if(SecondCheck(hard_coded_board[num], args[i])){
            check += "1";//posição errada mas letra existe

        }else
            check += "0";//letra não existe
    }
}


int main(){
    //Variables
    std::vector<std::string> hard_coded_board = SetHardCodedBoard();
    std::vector<std::string> player_board;
    std::string args = "";
    int check = 0;

    //Presentation
    std::cout << "Bem vindo!" << std::endl;

    //Running Code
    do{    
        std::cout << "Insira uma palavra: ";
        std::cin >> args;
        
        if(args == "cheat"){
            PrintBoardInside(hard_coded_board);
        }else if(args == "exit"){
            std::cout << "Cya!" << std::endl;
            return 0;
        }else if(args.size() != 5){
            std::cout << "Palavras de 5 letras so!" << std::endl;
        }else{
            player_board.emplace_back(args);
            ReceiveCheck(hard_coded_board,args,check);//pensar em maneira de dar check entre letras e adicionar um print do estado atual
            check++;
        }
    } while (check != hard_coded_board.size());
    
    //END
    return 0;
}