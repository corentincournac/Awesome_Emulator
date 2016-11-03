/* 
 * File:   Machine.cpp
 * Author: corentin
 * 
 * Created on 2 octobre 2016, 23:04
 */

#include <vector>

#include "Machine.h"
#include <iostream>

Machine::Machine() {
    m_registres = std::vector<int16_t>(32,0);
    m_flag=false;
    m_ram = (int16_t*) malloc(524288*sizeof(int16_t)); //2^19 cases
    m_registres[31] = 0;
    m_screen.create(sf::VideoMode(512,512), "Awesome Emulator");
    m_screen.setFramerateLimit(60);
    m_pixels = (u_int8_t*) malloc(4*65536*sizeof(u_int8_t));
}

Machine::Machine(const Machine& orig) {
}

Machine::~Machine() {
    free(m_ram);
    free(m_pixels);
    m_screen.close();
}

int16_t Machine::getRegistre(int registre) {
    return m_registres[registre];
}

void Machine::setRegistre(int registre, int16_t value) {
    m_registres[registre] = value;
}

void Machine::setFlag(bool flag) {
    m_flag = flag;
}

bool Machine::getFlag() {
    return m_flag;
}

int16_t Machine::getRamAt(u_int32_t addr) {
    return m_ram[addr];
}

void Machine::flipScreen() {
    sf::Image img;
    //sur 16 bits : 4bits r, 4bits g, 4bits b, 4bits useless
    for (int i=0; i<65536; i++) {
        u_int8_t r,g,b;
        u_int16_t ram = m_ram[i+0x70000];
        //std::cout << ram;
        r = 16*((ram & 0xF000)>>12);
        g = 16*((ram & 0x0F00)>>8);
        b = 16*((ram & 0x00F0)>>4);
        m_pixels[4*i] = r;
        m_pixels[4*i+1] = g;
        m_pixels[4*i+2] = b;
        m_pixels[4*i+3] = 255;
        //std::cout << ram << " " << (int)r << " " << (int)g << " " << (int)b << " ";
    }
    img.create(256,256,m_pixels);
    sf::Texture tex;
    tex.loadFromImage(img);
    sf::Sprite sprite;
    sprite.setTexture(tex);
    //std::cout << tex.getSize().x << " " << tex.getSize().y << " ";
    sprite.scale(2.0,2.0);
    //sprite.setPosition(10,10);
    sprite.setTextureRect(sf::IntRect(0,0,256,256));
    m_screen.clear();
    m_screen.draw(sprite);
    m_screen.display();
    //std::cout << "Flippé\n";
}

void Machine::setRamAt(u_int32_t addr, int16_t val) {
    m_ram[addr] = val;
}

int16_t* Machine::getRam() {
    return m_ram;
}