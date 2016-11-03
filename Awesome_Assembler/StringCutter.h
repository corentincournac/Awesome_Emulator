/* 
 * File:   StringCutter.h
 * Author: corentin
 *
 * Created on 2 novembre 2016, 15:43
 */

#ifndef STRINGCUTTER_H
#define	STRINGCUTTER_H

#include <string>
#include <vector>

class StringCutter {
public:
    StringCutter();
    StringCutter(const StringCutter& orig);
    static std::vector<std::string> cutString(std::string str);
    virtual ~StringCutter();
private:

};

#endif	/* STRINGCUTTER_H */

