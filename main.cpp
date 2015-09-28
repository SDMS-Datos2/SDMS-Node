/* 
 * File:   main.cpp
 * Author: osboxes
 *
 * Created on 12 September 2015, 22:55
 */

#include <cstdlib>
#include <iostream>
#include <string.h>
#include "Server.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Server * nuevo = new Server(5001);
    /**char numeros=48;
    for(int i=0; i<5;i++){
        cout<<numeros<<endl;
        numeros++;
        cout<<sizeof(numeros)<<endl;
    }
    */
    /**const char* msg="hola_mundo";
    cout<<strlen(msg)<<endl;*/
    /**long dato;
    cin>>dato;
    //usar atol para convertir de char* a long
    int * direccion= (int*)malloc(2*sizeof(int));
    int largo=contador(dato);
    int i=0;
    if(largo>10)
        (*direccion)=(dato/pow10(largo-10));
    dato%=(int)pow10(largo-10);
    *(++direccion)=(int)dato;
    cout<<*direccion<<endl;
    cout<<*(--direccion)<<endl;
    /**long i=123456789123;
    int num=i/pow10(2);
    //int num= contador(i);
    cout<<num<<endl;*/
    
    return 0;
}