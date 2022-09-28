#include "Checker.h"

std::string TrueCheckerPrint(std::vector<std::string> hard_coded_word, std::string args, int num){
    //VARIABLES
    std::string number_check = "";//to check if it's right, close or wrong
    std::string final_result = "";//final result with all verifications

    //CHECKS
    number_check = ReceiveCheck(hard_coded_word,args,num);//has number code raw
    DoubleCheck(number_check, args, hard_coded_word);

}

//FIRST CHECK
std::string ReceiveCheck(std::vector<std::string> hard_coded_word, std::string args, int num){
    //VARIABLES
    std::string check = "";//to check if it's right, close or wrong

    for (int i = 0; i < hard_coded_word[num].size(); i++){

        if(hard_coded_word[num][i] == args[i]){
            check += "2";//right position

        }else if(SecondCheck(hard_coded_word[num], args[i])){
            check += "1";//wrong position but letter exists
        }else
            check += "0";//letter does not exist
    }

    return check;
}

bool SecondCheck(std::string palavra, char c){ //to check if letter exists
    for (int i = 0; i < palavra.size(); i++){
        if(palavra[i]==c)
            return true;
    }
    return false;
}

//SECOND CHECK
int DoubleCheck(std::string number_check, std::string args, std::vector<std::string> hard_coded_word){
    //VARIABLES
    std::vector<std::string> double_checker;//if it exists, checks how many times
    std::vector<std::string> word_counter = WordCounter(hard_coded_word);// format letter | number; checks how many times x letter happens and registers on this variable



}

std::vector<std::string> WordCounter(std::vector<std::string> hard_coded_word){
    //VARIABLES
    std::vector<std::string> word_counter;

    for (int i = 0; i < hard_coded_word.size(); i++){
        char receiver = hard_coded_word[0][i];
        int times_word_appears = 1;
        for (int j = i; j < hard_coded_word.size(); j++){
            if(receiver == hard_coded_word[0][j]){
                times_word_appears++;
            }
        }
        word_counter.emplace_back(receiver,times_word_appears);
    }
    
}