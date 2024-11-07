#include <Arduino.h>
#include <Servo.h>
#include <string.h>
#include "kutupdeneme.h"
#include <math.h>

Servo myservo;  //Servo objesi. Kontrol etmek icin

int pos = 0; 

float x = 0;
float y = 10;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(9); // 9 da bagladigimizi dedik
}

void loop() {
  // put your main code here, to run repeatedly:
  
  /*
  for(pos = 0; pos<= 180;pos+=1){
    myservo.write(pos);

    Serial.print("Position straight: ");
    Serial.println(pos);
    delay(15); // 15 ms pozisyona varmak icin bekliyor
  }
  for(pos=180; pos >= 0;pos--){
    myservo.write(pos);
    Serial.print("Position back: ");
    Serial.println(pos);
    delay(15);
  }
  */
  float aci = yone_dogru(0,0,x,y);

  //float aci = 0;
  //aci_hesapla(0,0,30,40,aci);
  delay(100);
  Serial.println(aci);
  myservo.write(aci);
  
  if(x<100000)
    x += x+ 50;
  else {
    x = 0;

  }
  
 /*
  myservo.write(0);
  delay(700);
  myservo.write(170);
  delay(700);
  */
}
