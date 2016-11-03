/* 
 * File:   Instruction1o.cpp
 * Author: corentin
 * 
 * Created on 2 novembre 2016, 15:32
 */

#include "Instruction1o.h"

Instruction1o::Instruction1o(char octet) {
    this->octet = octet;
}

Instruction1o::Instruction1o(const Instruction1o& orig) {
}

Instruction1o::~Instruction1o() {
}

void Instruction1o::writeBytes(std::ofstream file) {
    file << octet;
}


