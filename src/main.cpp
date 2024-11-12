#include <Arduino.h>
#include <Servo.h>
#include <string.h>
#include "kutupdeneme.h"
#include <math.h>

Servo myservo;  //Servo objesi. Kontrol etmek icin
Servo myservo2; //2 servo olunca ayri objelerden kontrol ediyoruz

float x = 0;
float y =90;
int yon =1;
int yon2 = 1;

//enlem boylam onu x y kordinatina cevrilecek bir fonksiyon bu batıkaf sonrası


//Z) cos ile arctan dene hangisi iyiyse ona göre yapılacak. hazir x1,y1 x2 y2 arctan ile costa deniycen
//2 ardunioda calistirmayi dene
//---------------------------------
//S) aci hesapla zimbirtisi bende


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(9); // 9 da bagladigimizi dedik
  myservo2.attach(10); // 2.servo 10 da
}

void loop() {
  float x_acisi = x_ekseni_hesapla(0,x);
  float y_acisi = y_ekseni_hesapla(0,y);



  delay(100);
  Serial.print("x acisi: ");
  Serial.println(x_acisi);
  Serial.print("y acisi ");
  Serial.println(y_acisi);
  myservo.write(x_acisi);
  myservo2.write(y_acisi);

  x += yon * 10;
  if( x >= 180){
    yon = -1;
  }
  else if(x <= 0){
    yon = 1;
  }
  y += yon2 * 5;
  if( y >= 180){
    yon2 = -1;
  }
  else if(y <= 0){
    yon2 = 1;
  }

}
