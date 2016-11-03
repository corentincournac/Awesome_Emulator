/* 
 * File:   Instruction2o.h
 * Author: corentin
 *
 * Created on 2 novembre 2016, 15:36
 */

#ifndef INSTRUCTION2O_H
#define	INSTRUCTION2O_H

#include "AbstractInstruction.h"


class Instruction2o: public AbstractInstruction {
public:
    Instruction2o() {}
    Instruction2o(char octet1, char octet2);
    Instruction2o(const Instruction2o& orig);

    virtual void writeBytes(std::ofstream file);

    virtual ~Instruction2o();
private:
    char m_o1, m_o2;

};

#endif	/* INSTRUCTION2O_H */

