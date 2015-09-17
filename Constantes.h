/* 
 * File:   Constantes.h
 * Author: osboxes
 *
 * Created on 12 September 2015, 22:56
 */

#ifndef CONSTANTES_H
#define	CONSTANTES_H
#include <string.h>

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
     * DosCincoSeis=256
     */
    static const int DosCientaSeis=256;
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
    /**
     * metodo que recibe una linea caracteres y retorna la cantidad 
     * de letras que contiene.
     * @param msg dato tipo char*, este el mensaje que se le quiere calcular 
     * el largo.
     * @return retorna un dato tipo entero que es el largo del mensaje que 
     * se le paso.
     */
    int getLenght(const char* msg);
    /**
     * contador de cantidad de digitos en un numero long,
     * se va a utilizar para partir un numero mayor a bytes
     * para ingresarlo en un int.
     * @param dato dato tipo long.
     * @return retorna un entero que es la cantidad de datos
     * que contiene.
     */
    int contador(long dato);
};

#endif	/* CONSTANTES_H */

