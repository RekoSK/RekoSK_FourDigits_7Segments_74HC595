#ifndef FOUR_7SEGMENTS74HC595_H
#define FOUR_7SEGMENTS74HC595_H
#include <Arduino.h>

class FourDigits_7segments_74HC595
{
private:
    //input is reversed for some reason!
    uint8_t _input;
    //clk is stored here
    uint8_t _clk;
    //latch is stored here
    uint8_t _latch;
    //primitive logic for printInt() here
    void intLogic(uint8_t num, bool anim);
public:
    //By changing this, you will change the animation speed of every segment in ms
    uint16_t animDelay = 25;
    /**
     * Create the class. 
     * After this, you don't need to call any other function like init() or begin(),
     * everything is done here
     * @param input pin of the Serial Input (or SDI)
     * @param clk pin of Shift Register Clock Input (or SCLK)
     * @param latch pin of latch (or LOAD)
     */
    FourDigits_7segments_74HC595(uint8_t input, uint8_t clk, uint8_t latch);
    /**
     * Displays/print out one segment on the display
     * @param status What segment do you want to print. HIGH to display a enabled segment, LOW for disabled one.
     * @param visible If you want to see the segment. Useful when disabling/enabling an animation. WARNING! Used delay here!
     */
    void SegmentPrint(uint8_t status, bool visible);
    /**
     * Clears the display.
     * @param anim Change if you want to see animation (segments passing trought) or not
     */
    void clear(bool anim = false);
    /**
     * Prints out any int from -999 to 999
     * @param theInt Number that you want to print (from -999 to 999)
     * @param anim Change if you want to see animation (segments passing trought) or not
     */
    void printInt(int theInt, bool anim = false);
    /**
     * Prints out a number
     * @param dot Change if you wanna see a dot (8th segment on)
     * @param anim Change if you want to see animation (segments passing trought) or not
     */
    void Create1(bool dot, bool anim = false);
    /**
     * Prints out a number
     * @param dot Change if you wanna see a dot (8th segment on)
     * @param anim Change if you want to see animation (segments passing trought) or not
     */
    void Create2(bool dot, bool anim = false);
    /**
     * Prints out a number
     * @param dot Change if you wanna see a dot (8th segment on)
     * @param anim Change if you want to see animation (segments passing trought) or not
     */
    void Create3(bool dot, bool anim = false);
    /**
     * Prints out a number
     * @param dot Change if you wanna see a dot (8th segment on)
     * @param anim Change if you want to see animation (segments passing trought) or not
     */
    void Create4(bool dot, bool anim = false);
    /**
     * Prints out a number
     * @param dot Change if you wanna see a dot (8th segment on)
     * @param anim Change if you want to see animation (segments passing trought) or not
     */
    void Create5(bool dot, bool anim = false);
    /**
     * Prints out a number
     * @param dot Change if you wanna see a dot (8th segment on)
     * @param anim Change if you want to see animation (segments passing trought) or not
     */
    void Create6(bool dot, bool anim = false);
    /**
     * Prints out a number
     * @param dot Change if you wanna see a dot (8th segment on)
     * @param anim Change if you want to see animation (segments passing trought) or not
     */
    void Create7(bool dot, bool anim = false);
    /**
     * Prints out a number
     * @param dot Change if you wanna see a dot (8th segment on)
     * @param anim Change if you want to see animation (segments passing trought) or not
     */
    void Create8(bool dot, bool anim = false);
    /**
     * Prints out a number
     * @param dot Change if you wanna see a dot (8th segment on)
     * @param anim Change if you want to see animation (segments passing trought) or not
     */
    void Create9(bool dot, bool anim = false);
    /**
     * Prints out a number
     * @param dot Change if you wanna see a dot (8th segment on)
     * @param anim Change if you want to see animation (segments passing trought) or not
     */
    void Create0(bool dot, bool anim = false);
    /**
     * Prints out a -
     * @param anim Change if you want to see animation (segments passing trought) or not
     */
    void CreateMinus(bool anim = false);
    /**
     * Creates blank character (8 LOW segments in a row)
     */
    void CreateBlank(bool anim = false);
    
};






#endif