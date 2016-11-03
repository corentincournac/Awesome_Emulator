/* 
 * File:   Parser.cpp
 * Author: corentin
 * 
 * Created on 2 novembre 2016, 15:23
 */

#include "Parser.h"
#include "Instruction1o.h"
#include "Instruction2o.h"
#include "StringCutter.h"
#include <fstream>
#include <iostream>
#include <string>

Parser::Parser() {
}

Parser::Parser(const Parser& orig) {
}

Parser::~Parser() {
}

std::vector<AbstractInstruction> Parser::parseFile(std::string fileName) {
    std::vector<AbstractInstruction> res;
    
    std::ifstream file(fileName.c_str());
    int linecount = 0;
    while (!file.eof()) {
        std::string str;
        getline(file, str);
        linecount++;
        std::vector<std::string> instruction_cut = StringCutter::cutString(str);
        for (int i=0; i<instruction_cut.size(); i++) {
            std::cout << instruction_cut[i] << " ";
        }
        if (instruction_cut.size() == 0) {
            continue;
        }
        if (instruction_cut.size() == 1) {
            Instruction1o inst;
            std::string strinst = instruction_cut[0];
            if (strinst=="end") {
                inst = Instruction1o(0);
            } else if (strinst=="nop") {
                inst = Instruction1o(1);
            } else if (strinst=="flip") {
                inst = Instruction1o(30);
            } else {
                std::cerr << "Erreur ligne " + linecount+" : " +strinst+": instruction inconnue ou arguments incohérents";
            }
        } else if (instruction_cut.size() == 2) {
            Instruction2o inst;
            std::string strinst = instruction_cut[0];
            std::string arg = instruction_cut[1];
        }
    }
    m_program.push_back(0);
    return*/
}


