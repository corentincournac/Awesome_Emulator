/* 
 * File:   Instruction1o.h
 * Author: corentin
 *
 * Created on 2 novembre 2016, 15:32
 */

#ifndef INSTRUCTION1O_H
#define	INSTRUCTION1O_H

#include "AbstractInstruction.h"


class Instruction1o : public AbstractInstruction {
public:
    Instruction1o() {}
    Instruction1o(char octet);
    Instruction1o(const Instruction1o& orig);

    virtual void writeBytes(std::ofstream file);

    virtual ~Instruction1o();
private:
    char octet;
};

#endif	/* INSTRUCTION1O_H */

