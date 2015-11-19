/* 
 * File:   main.cpp
 * Author: ellioth
 *
 * Created on November 12, 2015, 5:19 PM
 */

#include <cstdlib>
#include "server.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    server * nuevo = new server("server1", 5005);
    return 0;
}

