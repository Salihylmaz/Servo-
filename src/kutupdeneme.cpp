#include "kutupdeneme.h"
#include <math.h>

int toplam(int a,int b){
    return a + b;
}

float yone_dogru(float xMotor, float yMotor, float xHedef, float yHedef){
    float aci; // Hedef ile motorun arasindaki aci
    float deltaY = yHedef - yMotor;
    float deltaX = xHedef-xMotor;
    aci = atan2(deltaY,deltaX) * (180 / M_PI);
    
    return aci;
}

void aci_hesapla(float xMotor, float yMotor, float xHedef, float yHedef,float aci){
    // Hedef ile motorun arasindaki aci
    float deltaY = yHedef - yMotor;
    float deltaX = xHedef-xMotor;
     while(deltaX < 170 && deltaY < 170){
        deltaX = deltaX + 10;
        deltaY = deltaX + 10;
        aci = atan2(deltaY,deltaX) * (180 / M_PI);
    }
}
