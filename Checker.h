#ifndef CHECKER_H
#define CHECKER_H

#include "DefaultIncludes.h"

std::string TrueCheckerPrint(std::vector<std::string> hard_coded_word, std::string args, int num);//Sends words with all the checks in place

//FIRST CHECK
std::string ReceiveCheck(std::vector<std::string> hard_coded_word, std::string args, int num);//Sends number code to TCP
bool SecondCheck(std::string palavra, char c);//Checks if word exists even if it is in the wrong place

//SECOND CHECK
int DoubleCheck(std::string palavra, char c);
std::vector<std::string> WordCounter(std::vector<std::string> hard_coded_word){;
#endif //CHECKER_H