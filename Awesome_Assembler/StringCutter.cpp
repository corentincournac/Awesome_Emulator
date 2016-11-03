/* 
 * File:   StringCutter.cpp
 * Author: corentin
 * 
 * Created on 2 novembre 2016, 15:43
 */

#include "StringCutter.h"

StringCutter::StringCutter() {
}

StringCutter::StringCutter(const StringCutter& orig) {
}

StringCutter::~StringCutter() {
}

std::vector<std::string> StringCutter::cutString(std::string str) {
    std::vector<std::string> res;
    std::string cut = "";
    for (int i=0; i<str.length(); i++) {
        if (str[i]==' ') {
            if (cut.length() != 0) {
                res.push_back(cut);
                cut = "";
            }
        } else if (str[i]==';') {
            break;
        } else {
            cut += str[i];
        }
    }
    if (cut.length() != 0) {
        res.push_back(cut);
    }
    
    return res;
}


