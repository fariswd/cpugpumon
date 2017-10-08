/**
 * Displays text sent over the serial port (e.g. from the Serial Monitor) on
 * an attached LCD.
 */
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <string.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
char inData[17]; // Allocate some space for the string
char inChar; // Where to store the character read
byte i = 0; // Index into array; where to store the character

void setup()
{
	lcd.begin();
	lcd.backlight();
  
	// Initialize the serial port at a speed of 9600 baud
	Serial.begin(9600);
}

void loop()
{
  
  memset(inData, 0, 17); // Allocate some space for the string
  byte i = 0; // Index into array; where to store the character
  
	// If characters arrived over the serial port...
	if (Serial.available()) {
		// Wait a bit for the entire message to arrive
		delay(100);
		// Clear the screen
		//lcd.clear();

		// Write all characters received with the serial port to the LCD.
		while (Serial.available() > 0) {
      if(i < 18) // One less than the size of the array
      {
          inChar = Serial.read(); // Read a character
          inData[i] = inChar; // Store it
          i++; // Increment where to write next
          inData[i] = '\0'; // Null terminate the string
      }
		}
     Serial.println(String(inData));
   if(String(inData).substring(0,1) == "1"){
    lcd.setCursor(0, 0);
    lcd.print(String(inData).substring(1,17));
   }
   
   if(String(inData).substring(0,1) == "2"){
    lcd.setCursor(0, 1);
    lcd.print(String(inData).substring(1,17));
   }
   
   if(String(inData) == "cl"){
    lcd.clear();
   }
	}
}
