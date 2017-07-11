/* Distanzmessung mit Ausgabe im LCD-Display
 * A04 LEDs ab bestimmten Abständen
 */

#include <LiquidCrystal.h> // Eibinden der LiquidCrystal Bibliothek
LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Parameter der LCD

const int Trig = 9;
const int Echo = 10;

long dauer;
int abstandCm;

void setup() 
{
  lcd.begin(16,2); // Legt die Dimension des LCD-Displays fest (Breite,Höhe)
  pinMode(Trig, OUTPUT); // Pin 9 ist Ausgang des Ultraschallsensors
  pinMode(Echo, INPUT); // Pin 10 ist Eingang des Ultraschallsensors

  pinMode(11, OUTPUT); // Pin 11 ist ein Ausgang für LED_gruen
}

void loop()
{
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  
  dauer = pulseIn(Echo, HIGH);
  abstandCm= dauer*0.034/2; // Umrechnen in Längeneinheit cm

  lcd.setCursor(0,0); // Setzt den Cursor auf den Punkt (0,0)
  lcd.print("Abstand: "); // Schreibt "Abstand" auf das LCD-Display
  lcd.print(abstandCm); // Schreibt die gemessene Distanz auf das LCD-Display
  lcd.print(" cm"); // Schreibt die Längeneinheit cm auf das LCD-Display
  delay(350);
  lcd.clear();

  if (abstandCm <= 15 && abstandCm > 10)
  {
    digitalWrite(11, HIGH); //Schalte LED an
    delay(1000); //LED blinken
    digitalWrite(11, LOW); //Schalte LED aus
  }
  else
  {
     digitalWrite(11, LOW); // Schalte LED aus
  }
    if (abstandCm <= 10 && abstandCm > 5)
  {
    digitalWrite(11, HIGH); // Schalte LED an
    delay(500);
    digitalWrite(11,LOW); //Schalte LED aus
  }
  else
  {
     digitalWrite(11, LOW); // Schalte LED aus
  }
     if (abstandCm <= 5)
  {
    digitalWrite(11, HIGH); // Schalte LED an
 
  }
  else
  {
     digitalWrite(11, LOW); // Schalte LED aus
  }
}
 
