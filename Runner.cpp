/* 
 * File:   Runner.cpp
 * Author: corentin
 * 
 * Created on 2 octobre 2016, 22:47
 */

#include "Runner.h"
#include <iostream>

Runner::Runner() {
}

Runner::Runner(const Runner& orig) {
}

Runner::~Runner() {
}

void Runner::runProgram(Machine *m, std::vector<u_int8_t> program_vec) {
    u_int32_t addr_start = program_vec[3]+(program_vec[2]*256)+(program_vec[1]*65536)+
            program_vec[0]*16777216;
    //std::cout << addr_start;
    //on dump le programme dans la RAM
    for (int i=4; i<program_vec.size(); i++) {
        m->setRamAt(addr_start+i-4, program_vec[i]);
    }
    //on remplit l'écran de pixels noirs
    for (int i=0x70000; i<0x7FFFF; i++) {
        m->setRamAt(i,0);
    }
    //on commence là
    u_int32_t program_pointer = addr_start;
    u_int8_t instruction = 0;
    u_int8_t arg1 = 0;
    u_int8_t arg2 = 0;
    do {
        int16_t* program = m->getRam();
        instruction = program[program_pointer++];
        arg1 = program[program_pointer++];
        arg2 = program[program_pointer++];
        u_int16_t val = 0;
        u_int32_t val32 = 0;
        switch (instruction) {
            case 2:
                //Le LD : ld rg1 rg2 -> rg1 := rg2
                m->setRegistre(arg1, m->getRegistre(arg2));
                break;
            case 3:
                //LDI reg int16.
                //Pour le int16 on doit utiliser une case de plus dans le programme mais c'est oklm
                val = (u_int16_t) arg2 * 256 + program[program_pointer++];
                m->setRegistre(arg1, val);
                break;
            case 4:
                //ADD rg1 rg2
                if (65536 - m->getRegistre(arg1) < m->getRegistre(arg2)) {
                    m->setFlag(true);
                } else {
                    m->setFlag(false);
                }
                m->setRegistre(arg1, m->getRegistre(arg1) + m->getRegistre(arg2));
                break;
            case 5:
                //ADDI rg1 int16
                //4 octets
                val = (int16_t) arg2 * 256 + program[program_pointer++];
                if (65536 - m->getRegistre(arg1) < val) {
                    m->setFlag(true);
                } else {
                    m->setFlag(false);
                }
                m->setRegistre(arg1, m->getRegistre(arg1) + val);
                break;
            case 6:
                //SUB rg1 rg2
                if (m->getRegistre(arg2) > m->getRegistre(arg1)) {
                    m->setFlag(true);
                } else {
                    m->setFlag(false);
                }
                m->setRegistre(arg1, m->getRegistre(arg1) - m->getRegistre(arg2));
                break;
            case 7:
                //SUBI rg1 int16
                //4 octets
                val = (int16_t) arg2 * 256 + program[program_pointer++];
                if (val > m->getRegistre(arg1)) {
                    m->setFlag(true);
                } else {
                    m->setFlag(false);
                }
                m->setRegistre(arg1, m->getRegistre(arg1) - val);
                break;
            case 8:
                //MUL rg1 rg2
                m->setRegistre(arg1, m->getRegistre(arg2) * m->getRegistre(arg1));
                break;
            case 9:
                //DIV rg1 rg2
                if (m->getRegistre(arg2) != 0) {
                    m->setRegistre(arg1, m->getRegistre(arg1) / m->getRegistre(arg2));
                    m->setFlag(false);
                } else {
                    m->setFlag(true);
                }
                break;
            case 10:
                //EZ rg1
                if (m->getRegistre(arg1) != 0) {
                    m->setFlag(false);
                } else {
                    m->setFlag(true);
                }
                program_pointer--; //2 octets donc ça libère
                break;
            case 11:
                //NZ rg1
                if (m->getRegistre(arg1) != 0) {
                    m->setFlag(true);
                } else {
                    m->setFlag(false);
                }
                program_pointer--; //2 octets donc ça libère
                break;
            case 12:
                //GZ rg1
                (m->getRegistre(arg1) > 0) ? m->setFlag(true) : m->setFlag(false);
                program_pointer--; //2 octets donc ça libère
                break;
            case 13:
                //GEZ rg1
                (m->getRegistre(arg1) >= 0) ? m->setFlag(true) : m->setFlag(false);
                program_pointer--; //2 octets donc ça libère
                break;
            case 14:
                //LZ rg1
                (m->getRegistre(arg1) < 0) ? m->setFlag(true) : m->setFlag(false);
                program_pointer--; //2 octets donc ça libère
                break;
            case 15:
                //LEZ rg1
                (m->getRegistre(arg1) <= 0) ? m->setFlag(true) : m->setFlag(false);
                program_pointer--; //2 octets donc ça libère
                break;
            case 16:
                //FLAG rg1
                m->setRegistre(arg1, m->getFlag());
                program_pointer--;
                break;
            case 17:
                //OR rg1 rg2
                m->setRegistre(arg1, m->getRegistre(arg1) | m->getRegistre(arg2));
                break;
            case 18:
                //ORI rg1 int16
                val = (int16_t) arg2 * 256 + program[program_pointer++];
                m->setRegistre(arg1, m->getRegistre(arg1) | val);
                break;
            case 19:
                //AND rg1 rg2
                m->setRegistre(arg1, m->getRegistre(arg1) & m->getRegistre(arg2));
                break;
            case 20:
                //ANDI rg1 int16
                val = (int16_t) arg2 * 256 + program[program_pointer++];
                m->setRegistre(arg1, m->getRegistre(arg1) & val);
                break;
            case 21:
                //POP rg1
                m->setRegistre(arg1, m->getRamAt(m->getRegistre(31)));
                m->setRegistre(31, m->getRegistre(31) - 1);
                program_pointer--; //2o
                break;
            case 22:
                //PUSH rg1
                m->setRegistre(31, m->getRegistre(31) + 1);
                m->setRamAt(m->getRegistre(31), m->getRegistre(arg1));
                program_pointer--;
                break;
            case 23:
                //READ rg3 rg1 rg2
                val32 = (u_int32_t) ((u_int16_t)m->getRegistre(arg2))*65536
                        + ((u_int16_t)m->getRegistre(program[program_pointer++]));
                m->setRegistre(arg1, m->getRamAt(val));
                break;
            case 24:
                //WRITE rg3 rg1 rg2
                val32 = (u_int32_t) ((u_int16_t)m->getRegistre(arg2))*65536
                        + ((u_int16_t)m->getRegistre(program[program_pointer++]));
                m->setRamAt(val32, m->getRegistre(arg1));
                break;
            case 29:
                //ADDR addr32 rg1 rg2
                val32 = ((u_int32_t) ((u_int16_t)arg1) << 24) + ((u_int32_t) ((u_int16_t)arg2) << 16) +
                        ((u_int32_t) ((u_int16_t)program[program_pointer++]) << 8) 
                        + (u_int32_t)((u_int16_t)program[program_pointer++]);
                arg1 = program[program_pointer++];
                arg2 = program[program_pointer++];
                m->setRegistre(arg1, val32 / 65536);
                m->setRegistre(arg2, val32 % 65536);
                break;
            case 25:
                //J addr32
                val32 = ((u_int32_t) ((u_int16_t)arg1) << 24) + ((u_int32_t) ((u_int16_t)arg2) << 16) +
                        ((u_int32_t) ((u_int16_t)program[program_pointer++]) << 8) 
                        + (u_int32_t)((u_int16_t)program[program_pointer++]);
                program_pointer = val32;
                break;
            case 26:
                //JF addr32
                val32 = ((u_int32_t) ((u_int16_t)arg1) << 24) + ((u_int32_t) ((u_int16_t)arg2) << 16) +
                        ((u_int32_t) ((u_int16_t)program[program_pointer++]) << 8) 
                        + (u_int32_t)((u_int16_t)program[program_pointer++]);
                if (m->getFlag()) {
                    program_pointer = val32;
                }
                break;
            case 27:
                //JR reg1 reg2
                val32 = (u_int32_t) ((u_int16_t)m->getRegistre(arg2))*65536
                        + (u_int32_t) ((u_int16_t)m->getRegistre(program[program_pointer++]));
                program_pointer = val32;
                break;
            case 28:
                //JRF reg1 reg2
                val32 = (u_int32_t) ((u_int16_t)m->getRegistre(arg2))*65536
                        + (u_int32_t) ((u_int16_t)m->getRegistre(program[program_pointer++]));
                if (m->getFlag()) {
                    program_pointer = val32;
                }
                break;
            case 30:
                m->flipScreen();
                program_pointer-=2;
                break;
            case 255:
                std::cout << m->getRegistre(arg1);
                program_pointer--;
                break;

            default: //0,1 ou unknown
                break;

        }
        /*if (instruction==26) {
            std::cout << val32 << std::endl;
        }*/
        //std::cout << program_pointer << " : " <<(int) instruction << " " << (int) arg1 << " " << (int) arg2 << std::endl;
        
        //std::cout << (int)instruction << std::endl;
        //std::cout << "4="<<(u_int32_t)((u_int16_t)m->getRegistre(4)) <<" 2="<<(u_int32_t)((u_int16_t)m->getRegistre(2))<<std::endl;

    } while (instruction != 0);
}

