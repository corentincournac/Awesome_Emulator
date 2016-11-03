/* 
 * File:   main.cpp
 * Author: corentin
 *
 * Created on 2 novembre 2016, 15:22
 */

#include <iostream>
#include <string>
#include <vector>

#include "StringCutter.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    string test = "  ze  ezr ld $1 $20 ; swag";
    vector<string> testtest = StringCutter::cutString(test);
    cout << testtest.size() << endl;
    for (int i=0; i<testtest.size(); i++) {
        cout << testtest[i] << "-";
    }
    return 0;
}

