/* 
 * File:   main.cpp
 * Author: osboxes
 *
 * Created on 12 September 2015, 22:55
 */

#include <cstdlib>
#include <iostream>
#include <string.h>
#include <math.h>
#include "Server.h"
#include "Constantes.h"
using namespace std;

/*
 * 
 *
int contador(long dato) {
    int i=0;
    for(i;dato>0;i++){
        dato/=10;
    }
    return i;
}*/

int main(int argc, char** argv) {
    Server * nuevo = new Server("holamunfdo",5001);
    delete(nuevo);
    //Server * nuevo1 = new Server("diuev",5002);
    //Server * nuevo2 = new Server("nowboq",5003);
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
    if(largo<10){
        *direccion=(int)dato;
    }
    else{
        largo;
        (*direccion)=(dato/pow10(largo-9));
        dato%=(int)pow10(largo-9);
        *(++direccion)=(int)dato;
    }
    cout<<*direccion<<endl;
    cout<<*(--direccion)<<endl;
    /**long i=123456789123;
    int num=i/pow10(2);
    //int num= contador(i);
    cout<<num<<endl;*/
    
    return 0;
}