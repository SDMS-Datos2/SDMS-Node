/* 
 * File:   Constantes.cpp
 * Author: osboxes
 * 
 * Created on 12 September 2015, 22:56
 */

#include "Constantes.h"

using namespace std;

const char* Constantes::error1="ERROR opening socket";
const char* Constantes::error2="ERROR on binding";
const char* Constantes::error3="ERROR on accept";
const char* Constantes::error4="ERROR on fork";
const char* Constantes::error5="ERROR writing to socket";
const char* Constantes::error6="ERROR reading from socket";
const char* Constantes::salir="out";

int Constantes::getLenght(const char* msg) {
    return strlen(msg);
}

int Constantes::contador(long dato) {
    int i=0;
    for(i;dato>0;i++){
        dato/=10;
    }
    return i;
}


