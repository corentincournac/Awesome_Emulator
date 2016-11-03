/* 
 * File:   Parser.cpp
 * Author: corentin
 * 
 * Created on 2 octobre 2016, 22:46
 */

#include <vector>
#include <cstdlib>
#include <fstream>
#include "Parser.h"

Parser::Parser() {
}

Parser::Parser(const Parser& orig) {
}

Parser::~Parser() {
}

void Parser::setSource(std::string sourceName) {
    m_sourceName = sourceName;
}

void Parser::parse() {
    //On lit le fichier caractère par caractère.
    //Comme on est en 8 bits, c'est pareil lol
    //On écrit tout à la suite dans m_program.
    std::ifstream file(m_sourceName.c_str());
    while (!file.eof()) {
        std::string str;
        getline(file, str);
        if (!str.empty()) {
            for (int i=0; i<str.size(); i++) {
                m_program.push_back(str[i]);
            }
        }
    }
    m_program.push_back(0);
}

std::vector<u_int8_t> Parser::getProgram() {
    return m_program;
}