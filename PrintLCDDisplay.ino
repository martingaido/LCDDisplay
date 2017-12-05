/*
   Print content on LCD Display
   Author: Martin Gaido
   https://github.com/martingaido
  
   Parts required:

   - Arduino UNO Board
   - LCD Display 16x2
   - Cables
  
   Conn Diagram
  
   LCD Display (GND) -> ARDUINO UNO (GND)
   LCD Display (VCC) -> ARDUINO UNO (5V)
   LCD Display (SDA) -> ARDUINO UNO (A4)
   LCD Display (SCL) -> ARDUINO UNO (A5)

   This example code is part of the public domain.
*/

#include "Wire.h"
#include "LiquidCrystal_I2C.h"

// Configure the display
LiquidCrystal_I2C lcd(0x3f, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {

  // Initialize the display, 2 rows x 16 columns
  lcd.begin(16,2);

  // Clear data on display
  lcd.clear();
  
  // Set the cursor on row 0, col 0
  lcd.setCursor(0,0);

  // Print the content on the 1st row
  lcd.print("First Line #1");

  // Set the cursor on row 1, col 0
  lcd.setCursor(0,1);

  // Print the content on the 2nd row
  lcd.print("Second Line #2");

  // Wait 5 seconds
  delay(5000);
  
}

void loop() {

  // Print content toward left
  for(int a=0; a<16; a++){
    lcd.scrollDisplayLeft();
    delay(300);
  }

  // Print content toward right
  for(int a=0; a<16; a++){
    lcd.scrollDisplayRight();
    delay(300);
  }

}
