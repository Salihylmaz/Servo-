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

// Koordinatlar dizisi (x, y)
float koordinatlar[6][2] = {
  {10, 25},
  {30, 45},
  {50, 65},
  {70, 85},
  {90, 105},
  {110, 125}
};
const int koordinatSayisi = sizeof(koordinatlar) / sizeof(koordinatlar[0]);

// Şu anki hedef koordinat indeksi
int hedefIndeks = 0;

//enlem boylam onu x y kordinatina cevrilecek bir fonksiyon bu batıkaf sonrası


//Z) arctan dene. hazir x1,y1 x2 y2 arctan da deniycen
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
  // Hedef koordinatları al
  float xHedef = koordinatlar[hedefIndeks][0];
  float yHedef = koordinatlar[hedefIndeks][1];

  Serial.print("Hedef x: ");
  Serial.println(xHedef);
  Serial.print("Hedef y: ");
  Serial.println(yHedef);

  // x ve y eksenindeki farkları hesapla
  float deltaX = x_ekseni_hesapla(0, xHedef);   // X eksenindeki fark
  float deltaY = y_ekseni_hesapla(0, yHedef);   // Y eksenindeki fark

  // İki eksene göre açıları hesapla
  float aci = aci_bul(deltaX, deltaY); // Genel açı hesapla
  float x_acisi = deltaX >= 0 ? aci : 180 - aci; // X eksenine göre açı ayarla
  float y_acisi = deltaY >= 0 ? aci : 180 - aci; // Y eksenine göre açı ayarla

  // Sonuçları Seri portta göster
  Serial.print("x acisi: ");
  Serial.println(x_acisi);
  Serial.print("y acisi: ");
  Serial.println(y_acisi);
  myservo.write(x_acisi);
  myservo2.write(y_acisi);

  delay(500);

  // Bir sonraki koordinata geç
  hedefIndeks++;
  if (hedefIndeks >= koordinatSayisi) {
    hedefIndeks = 0; // Eğer son koordinata ulaşıldıysa başa dön
  }
}
