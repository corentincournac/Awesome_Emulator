/* 
 * File:   Machine.h
 * Author: corentin
 *
 * Created on 2 octobre 2016, 23:04
 */

#ifndef MACHINE_H
#define	MACHINE_H

#include <cstdlib>
#include <SFML/Graphics.hpp>

class Machine {
public:
    Machine();
    Machine(const Machine& orig);
    virtual ~Machine();
    void setRegistre(int registre, int16_t value);
    int16_t getRegistre(int registre);
    void setFlag(bool flag);
    bool getFlag();
    int16_t getRamAt(u_int32_t addr);
    void setRamAt(u_int32_t addr, int16_t val);
    int16_t* getRam();
    void flipScreen();
private:
    std::vector<u_int16_t> m_registres;
    bool m_flag;
    u_int16_t* m_ram;
    u_int8_t* m_pixels;
    sf::RenderWindow m_screen;
};

#endif	/* MACHINE_H */

