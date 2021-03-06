/* 
 * File:   Constantes.h
 * Author: ellioth
 *
 * Created on November 12, 2015, 5:19 PM
 */

#ifndef CONSTANTES_H
#define	CONSTANTES_H
#include <string.h>
#include <stdlib.h>

class Constantes {
public:
    /**
     * bandera de debug
     */
    static const bool _debug=true;
    /**
     * cero=0
     */
    static const int cero=0;
    /**
     * uno=1
     */
    static const int uno=1;
    /**
     * dos=2
     */
    static const int dos=2;
    /**
     * tres=3
     */
    static const int tres=3;
    /**
     * cuatro=4
     */
    static const int cuatro=4;
    /**
     * cinco=5
     */
    static const int cinco=5;
     /**
     * nueve
     */
    static const int nueve=9;
    /**
     * DosCincoSeis=256
     */
    static const int DosCientaSeis=256;
    /**
     * QuinDoce=512
     */
    static const int QuinDoce=512;
    /**
     * puerto=6200
     */
    static const int puerto=6200;
    /**
     * "ERROR opening socket"
     */
    static const char* error1;
    /**
     * "ERROR on binding"
     */
    static const char* error2;
    /**
     * "ERROR on accept"
     */
    static const char* error3;
    /**
     * "ERROR on fork"
     */
    static const char* error4;
    /**
     * "ERROR writing to socket"
     */
    static const char* error5;
    /**
     * "ERROR reading from socket"
     */
    static const char* error6;
    /**
     * "out"
     */
    static const char* salir;
};

#endif	/* CONSTANTES_H */

