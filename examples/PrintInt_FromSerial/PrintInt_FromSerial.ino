/**
 * Name: Print int from serial
 * Description: This example show how you can print out a number from serial to the display
 * Author: RekoSK
 * Date: 17.9.2024
 */

//We always need to include library:
#include <FourDigits_7segments_74HC595.h>

//Going to make display class here, but first im gonna define where my ports are connected to:
//PIN 1 => Latch (LOAD)
#define LATCH 2
//PIN 2 => Serial input (SDI)
#define _INPUT 3
//PIN 3 => (S)CLK
#define CLK 4
//Put them in correct order:
FourDigits_7segments_74HC595 display(_INPUT, CLK, LATCH);

void setup(){
    //Clears the display:
    display.clear();

    //Starts the serial communication on 9600 bauds
    Serial.begin(9600);

    while (!Serial) {
    ; // Waits for serial port to connect. Needed for native USB only.
    }
}

void loop(){
    if (Serial.available() > 0) {  //Checks if data is available to read
        //Makes a variable in which we store number send trought serial monitor.
        int receivedNumber = Serial.parseInt();
        //Prints out receivedNumber. Numbers from -999 to 999 work.
        display.printInt(receivedNumber);
    }
}