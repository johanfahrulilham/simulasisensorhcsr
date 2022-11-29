#include <LiquidCrystal.h>

int D7_pin = 4; 
int D6_pin = 5; 
int D5_pin = 6; 
int D4_pin = 7; 
int EN_pin = 11;
int RS_pin = 12; 
LiquidCrystal lcd(RS_pin, EN_pin, D4_pin, D5_pin, D6_pin, D7_pin);

int trig = 9;   // sesuaikan pada port arduino yang mengarah pada trig
int echo = 10;  // sesuaikan pada port arduino yang mengarah pada echo
long durasi, jarak;

void setup() {
  lcd.begin(16, 2);  
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT); 
  Serial.begin(9600);   
}

void loop() {
  // output yang akan ditampilkan pertama
  lcd.clear(); 
  lcd.print("Johan Fahrul Ilham"); 
  lcd.setCursor(0, 1); 
  lcd.print("G.211.19.0061"); 
  delay(1500);  
  
  // program dibawah ini agar trigger memancarakan suara ultrasonic
  digitalWrite(trig, LOW);
  delayMicroseconds(8);
  digitalWrite(trig, HIGH);
  delayMicroseconds(8);
  digitalWrite(trig, LOW);
  delayMicroseconds(8);

  // membuat rumus jarak
  durasi = pulseIn(echo, HIGH); 
  jarak = (durasi / 2) / 29.1;  

  // output jarak yang akan ditampilkan
  Serial.println(jarak);
  lcd.clear(); 
  lcd.print("Sensor Jarak = "); 
  lcd.setCursor(0, 1); 
  lcd.print(jarak); 
  delay(1500);
}
