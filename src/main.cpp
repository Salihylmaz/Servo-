#include <Arduino.h>
#include <Servo.h>
#include <string.h>
#include "kutupdeneme.h"
#include <math.h>

Servo myservo;  //Servo objesi. Kontrol etmek icin
Servo myservo2; //2 servo olunca ayri objelerden kontrol ediyoruz
//int pos = 0; 

float x = 0;
float y =90;
int yon =1;
//float y = 10;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(9); // 9 da bagladigimizi dedik
  myservo2.attach(10); // 2.servo 10 da
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
  float x_acisi = x_ekseni_hesapla(0,x);
  float y_acisi = y_ekseni_hesapla(0,0);

  delay(100);
  Serial.println(x_acisi);
  myservo.write(x_acisi);
  myservo2.write(y_acisi);
  x += yon * 10;
  if( x >= 180){
    yon = -1;
  }
  else if(x <= 0){
    yon = 1;
  }
  y += yon * 5;
  if( y >= 180){
    yon = -1;
  }
  else if(y <= 0){
    yon = 1;
  }

}
