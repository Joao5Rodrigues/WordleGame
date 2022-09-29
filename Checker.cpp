#include "Checker.h"

Checker::Checker(){}
Checker::~Checker(){}

std::string Checker::TrueCheckerPrint(std::string hard_coded_word, std::string args){
    //VARIABLES
    std::string number_check = "";//to check if it's right, close or wrong
    std::string final_result = "";//final result with all verifications

    //CHECKS
    number_check = ReceiveCheck(hard_coded_word,args);//has number code raw
    DoubleCheck(number_check, args, hard_coded_word);
    return "  ";
}

//FIRST CHECK
std::string Checker::ReceiveCheck(std::string hard_coded_word, std::string args){
    //VARIABLES
    std::string check = "";//to check if it's right, close or wrong

    for (int i = 0; i < hard_coded_word.size(); i++){

        if(hard_coded_word[i] == args[i]){
            check += "2";//right position

        }else if(SecondCheck(hard_coded_word, args[i])){
            check += "1";//wrong position but letter exists
        }else
            check += "0";//letter does not exist
    }

    return check;
}

bool Checker::SecondCheck(std::string palavra, char c){ //to check if letter exists
    for (int i = 0; i < palavra.size(); i++){
        if(palavra[i]==c)
            return true;
    }
    return false;
}

//SECOND CHECK
int Checker::DoubleCheck(std::string number_check, std::string args, std::string hard_coded_word){
    //VARIABLES
    std::string double_checker;//if it exists, checks how many times
    std::vector<std::string> word_counter = WordCounter(hard_coded_word);// format letter | number; checks how many times x letter happens and registers on this variable

    //CODE


    return 0;
}

std::vector<std::string> Checker::WordCounter(std::string hard_coded_word){//to check how many times letters appear in a word
    //VARIABLES
    std::vector<std::string> word_counter;
    std::string receiver = "";
    int times_word_appears = 1;

    for (int i = 0; i < hard_coded_word.size(); i++){
        receiver += hard_coded_word[i];
        if (WordCounterCheck(word_counter, receiver[0])){
        
            for (int j = i + 1; j < hard_coded_word.size(); j++){
                if(receiver[0] == hard_coded_word[j]){
                    times_word_appears++;
                }
            }
            receiver += std::to_string(times_word_appears);
            word_counter.emplace_back(receiver);
        }
        receiver = "";
        times_word_appears = 1;
    }
    return word_counter;
}

bool Checker::WordCounterCheck(std::vector<std::string> word_counter, char c){//to not repeat letters from WordCounter
    for (int i = 0; i < word_counter.size(); i++){
        if(c == word_counter[i][0]){
            return false;
        }
    }
    return true;    
}