/* 
 * File:   Instruction.h
 * Author: corentin
 *
 * Created on 2 novembre 2016, 15:25
 */

#ifndef INSTRUCTION_H
#define	INSTRUCTION_H

#include <fstream>

class AbstractInstruction {
public:
    AbstractInstruction();
    AbstractInstruction(const AbstractInstruction& orig);
    virtual ~AbstractInstruction();
    virtual void writeBytes(std::ofstream file) {} 
private:

};

#endif	/* INSTRUCTION_H */

