#include <LiquidCrystal.h>

int inches = 0;

int cm = 0;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
    lcd.print("click");
    pinMode(13, INPUT);

}


long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}


void loop()
{
  if (digitalRead(13)) {
    cm = 0.01723 * readUltrasonicDistance(7, 7);
    delay(100); 
    lcd.setCursor(0, 0);
    lcd.print(cm);
    lcd.print("cm   ");
  }
}
 
