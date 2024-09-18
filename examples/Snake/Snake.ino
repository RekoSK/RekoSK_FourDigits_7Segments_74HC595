/**
 * Name: Snake
 * Description: This example shows how we can create simple looping snake on the display
 *              To be able to understant this example, you going to need to know how shift registers (74HC595) work, and pinout of 7 segments numbers:
 *                   1
 *                  ---
 *            6 |    7    | 2
 *                  ---   
 *            5 |    4    | 3   (dot) 8
 *                  ---         ::
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

//Defines a little delay which we going to use later.
//If you want the snake to move smoother and quicker, you can change this to a smaller number:
#define LITTLE_DELAY 250

void setup(){
    //Clears the display:
    display.clear();
}

void loop(){

    //We going to make the snake appear:
    //Do it 4 times (because there are 4 digits)
    for (uint8_t i = 0; i < 4; i++)
    {
        for (uint8_t h = 0; h < 7; h++)
        {
            //Makes the first 7 segments in line LOW:
            display.SegmentPrint(LOW, false);
        }

        //Prints out the first (or the last in line) segment HIGH and makes it visible:
        display.SegmentPrint(HIGH, true);

        

        //Adds a little delay, so we can acually see the animation:
        delay(LITTLE_DELAY);
    }
    
    //Now we going to make the snake dissapear from left to right:
    //Do it 4 times (because there are 4 digits)
    for (uint8_t i = 0; i < 4; i++)
    {
        //Creates one blank digit (8 blank segments):
        display.CreateBlank();
        

        //Makes the changes apply on the display (we didn't need to do that in the first for(), because we turned visible to on in SegmentPrint())
        digitalWrite(LATCH, HIGH);
        digitalWrite(LATCH, LOW);

        //Adds a little delay, so we can acually see the animation:
        delay(LITTLE_DELAY);
    }
    

    
}