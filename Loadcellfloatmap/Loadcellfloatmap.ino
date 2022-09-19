// Written by MMDP, August 2020 - Bilbao University
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

// the setup routine runs once when you press reset:
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin A0:
  int analogValue = analogRead(A0);
  // Rescale to potentiometer's voltage (from 0V to 5V):
  //float voltage = floatMap(analogValue, 0, 1023, 0, 5);
  float scale = floatMap(analogValue, 0, 1023, -20000, 20000);

  //================================================================
  //Serial Out
  Serial.print("Analogue: ");
  Serial.print(analogValue);
  // print out the value you read:
  Serial.print(", Scale: ");
  Serial.println(scale);
  //===================================================================
  // LCD Out
  // (note: line 0 is the sFirst row, since counting begins with 0):
  lcd.setCursor(0, 0);
  // print out the value you read:
  lcd.print("Analogue: ");
  lcd.print(analogValue);
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  //print out the scale
  lcd.print("Scale: ");
  lcd.print(scale);  


  delay(1000);
}
