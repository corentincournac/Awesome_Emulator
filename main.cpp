/* 
 * File:   main.cpp
 * Author: corentin
 *
 * Created on 2 octobre 2016, 22:27
 */

#include <cstdlib>
#include <iostream>
#include <string>

#include "Parser.h"
#include "Runner.h"
#include "Machine.h"
#include <SFML/Graphics.hpp>
#include <unistd.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Parser p;
    //if (argc>1)
    std::string source = argv[1];
    //else
       // source = "test.bin";
    p.setSource(source);
    p.parse();
    Runner r;
    Machine m;
    r.runProgram(&m, p.getProgram());
    //m.flipScreen();
    //std::cout << ((65280 & 0xF000)>>12);
    std::cout << "End of Program" << std::endl;
    sleep(1);
    return 0;
}

