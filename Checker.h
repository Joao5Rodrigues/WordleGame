#ifndef CHECKER_H
#define CHECKER_H

#include "DefaultIncludes.h"

class Checker
{
private:
public:
    Checker(/* args */);
    ~Checker();


    std::vector<std::string> TrueCheckerPrint(std::string hard_coded_word, std::string args, std::vector<std::string> player_attempts_color);//Sends words with all the checks in place

    //FIRST CHECK
    std::string ReceiveCheck(std::string hard_coded_word, std::string args);//Sends number code to TCP
    bool SecondCheck(std::string palavra, char c);//Checks if word exists even if it is in the wrong place

    //SECOND CHECK
    int DoubleCheck(std::string number_check, std::string args, std::string hard_coded_word);
    std::vector<std::string> WordCounter(std::string hard_coded_word);
    bool WordCounterCheck(std::vector<std::string> word_counter, char c);
};

#endif //CHECKER_H