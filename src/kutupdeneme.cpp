#include "kutupdeneme.h"
#include <math.h>

float yone_dogru(float xMotor, float yMotor, float xHedef, float yHedef){
    //Belki ilerde fikir icin lazim olur diye duruyor
    float aci; // Hedef ile motorun arasindaki aci
    float deltaY = yHedef - yMotor;
    float deltaX = xHedef-xMotor;
    aci = atan2(deltaY,deltaX) * (180 / M_PI);
    return aci;
}


float eksen_hesapla(float dAnten, float dHedef){
    float deltaD; //tek fonksiyonda olur aslında ama okunabilirlik acisindan sorun olur mu?
    deltaD = dHedef - dAnten; 
    return deltaD;   
}


float x_ekseni_hesapla(float xAnten, float xHedef){
    float deltaX; //x2 - x1 sonucundaki delta x
    deltaX = xHedef - xAnten; 
    return deltaX;   
}


float y_ekseni_hesapla(float yAnten, float yHedef){
    float deltaY; //y2 - y1 sonucundaki delta y
    deltaY = yHedef - yAnten;
    return deltaY;    
}

float aci_bul(float deltaX, float deltaY){
    float aci; 
    aci = atan2(deltaY,deltaX) * (180 / M_PI); //arctan ile iki nokta arasındaki aciyi buluyoruz
    return aci; 
}