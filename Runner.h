/* 
 * File:   Runner.h
 * Author: corentin
 *
 * Created on 2 octobre 2016, 22:47
 */

#ifndef RUNNER_H
#define	RUNNER_H

#include <vector>

#include "Machine.h"

class Runner {
public:
    Runner();
    Runner(const Runner& orig);
    virtual ~Runner();
    void runProgram(Machine *m, std::vector<u_int8_t> program);
private:

};

#endif	/* RUNNER_H */

