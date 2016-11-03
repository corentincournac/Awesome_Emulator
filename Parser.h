/* 
 * File:   Parser.h
 * Author: corentin
 *
 * Created on 2 octobre 2016, 22:46
 */

#ifndef PARSER_H
#define	PARSER_H

#include <string>
#include <vector>
#include <cstdlib>

class Parser {
public:
    Parser();
    Parser(const Parser& orig);
    virtual ~Parser();
    void setSource(std::string sourceName);
    void parse();
    std::vector<u_int8_t> getProgram();
private:
    std::string m_sourceName;
    std::vector<u_int8_t> m_program;
};

#endif	/* PARSER_H */

