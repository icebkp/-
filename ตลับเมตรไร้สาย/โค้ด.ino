#include <LiquidCrystal_I2C.h>
const int trigPin = PIN_PC0;
const int echoPin = PIN_PC1;
const int buzzerPin = PIN_PB0;
LiquidCrystal_I2C lcd(0x27, 16, 2);

long duration;
int distance;
void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(buzzerPin, OUTPUT);
  lcd.begin(16, 2);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(5, 0);
  lcd.print("HELLO");
}
void loop() {
  lcd.clear();
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.setCursor(5, 1);
  lcd.print("cm");
  if (distance <= 10) {
    tone(buzzerPin, 100);
    delay(50);
    noTone(buzzerPin);
    delay(1000);
  }
  delay(500); 

}
