/**
 * Name: PrintINT
 * Description: This example shows how to display an int on the display.
 * Author: RekoSK
 * Date: 17.8.2024
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

//The number we are printing out:
#define NUMBERTOPRINT 123

void setup(){
    //Clear the display:
    display.clear();

    //Print out the number. Can only print numbers from -999 to 999!
    //In the 2nd variable you can change if you want to see animation or not (default is false, but just for fun we gonna turn it to true).
    //BE CAREFUL! - animation is defaultly using delay!
    display.printInt(NUMBERTOPRINT, true);
}

void loop(){
    //Do something here
}