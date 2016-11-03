/* 
 * File:   Instruction2o.cpp
 * Author: corentin
 * 
 * Created on 2 novembre 2016, 15:36
 */

#include "Instruction2o.h"

Instruction2o::Instruction2o(char octet1, char octet2) {
    m_o1 = octet1;
    m_o2 = octet2;
}

Instruction2o::Instruction2o(const Instruction2o& orig) {
}

Instruction2o::~Instruction2o() {
}

void Instruction2o::writeBytes(std::ofstream file) {
    file << m_o1 << m_o2;
}

