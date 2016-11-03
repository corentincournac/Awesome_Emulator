/* 
 * File:   Parser.h
 * Author: corentin
 *
 * Created on 2 novembre 2016, 15:23
 */

#ifndef PARSER_H
#define	PARSER_H

#include "AbstractInstruction.h"
#include <vector>
#include <string>

class Parser {
public:
    Parser();
    Parser(const Parser& orig);
    virtual ~Parser();
    std::vector<AbstractInstruction> parseFile(std::string fileName);
private:

};

#endif	/* PARSER_H */

