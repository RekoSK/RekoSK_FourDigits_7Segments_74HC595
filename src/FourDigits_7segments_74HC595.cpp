#include "FourDigits_7segments_74HC595.h"
#include <Arduino.h>

FourDigits_7segments_74HC595::FourDigits_7segments_74HC595(uint8_t input, uint8_t clk, uint8_t latch){
    _input = input;
    _clk = clk;
    _latch = latch;

    pinMode(_input, OUTPUT);
    pinMode(_clk, OUTPUT);
    pinMode(_latch, OUTPUT);
}

void FourDigits_7segments_74HC595::clear(bool anim = false){
    digitalWrite(_input, HIGH);

    for (uint8_t i = 0; i < 32; i++)
    {
        digitalWrite(_clk, HIGH);
        if(anim) {digitalWrite(_latch, HIGH); delay(animDelay);}
        digitalWrite(_clk, LOW);
        if(anim) digitalWrite(_latch, LOW);
    }
    
    if(!anim){
        digitalWrite(_latch, HIGH);
        digitalWrite(_latch, LOW);
    }
    
}

void FourDigits_7segments_74HC595::SegmentPrint(uint8_t status, bool visible){
    if(status == HIGH) status = LOW;
    else status = HIGH;

    digitalWrite(_input, status);
    digitalWrite(_clk, HIGH);
    digitalWrite(_clk,LOW);
    digitalWrite(_input, LOW);

    

    if(visible){
        digitalWrite(_latch, HIGH);
        digitalWrite(_latch, LOW);
        delay(animDelay);
    }
    
}

void FourDigits_7segments_74HC595::Create1(bool dot, bool anim = false){
    if(dot) SegmentPrint(HIGH, anim);
    else SegmentPrint(LOW, anim);

    for(uint8_t i = 0; i < 4; i++) SegmentPrint(LOW, anim);
    for(uint8_t i = 0; i < 2; i++) SegmentPrint(HIGH, anim);

    SegmentPrint(LOW, anim);
}

void FourDigits_7segments_74HC595::Create2(bool dot, bool anim = false){
    if(dot) SegmentPrint(HIGH, anim);
    else SegmentPrint(LOW, anim);

    SegmentPrint(HIGH, anim);
    SegmentPrint(LOW, anim);
    SegmentPrint(HIGH, anim);
    SegmentPrint(HIGH, anim);
    SegmentPrint(LOW, anim);
    SegmentPrint(HIGH, anim);
    SegmentPrint(HIGH, anim);
}

void FourDigits_7segments_74HC595::Create3(bool dot, bool anim = false){
    if(dot) SegmentPrint(HIGH, anim);
    else SegmentPrint(LOW, anim);

    SegmentPrint(HIGH, anim);
    SegmentPrint(LOW, anim);
    SegmentPrint(LOW, anim);

    for(uint8_t i = 0; i < 4; i++) SegmentPrint(HIGH, anim);
}

void FourDigits_7segments_74HC595::Create4(bool dot, bool anim = false){
    if(dot) SegmentPrint(HIGH, anim);
    else SegmentPrint(LOW, anim);

    SegmentPrint(HIGH, anim);
    SegmentPrint(HIGH, anim);
    SegmentPrint(LOW, anim);
    SegmentPrint(LOW, anim);
    SegmentPrint(HIGH, anim);
    SegmentPrint(HIGH, anim);
    SegmentPrint(LOW, anim);


}

void FourDigits_7segments_74HC595::Create5(bool dot, bool anim = false){
    if(dot) SegmentPrint(HIGH, anim);
    else SegmentPrint(LOW, anim);

    SegmentPrint(HIGH, anim);
    SegmentPrint(HIGH, anim);

    SegmentPrint(LOW, anim);
    
    SegmentPrint(HIGH, anim);
    SegmentPrint(HIGH, anim);
    SegmentPrint(LOW, anim);
    SegmentPrint(HIGH, anim);

}

void FourDigits_7segments_74HC595::Create6(bool dot, bool anim = false){
    if(dot) SegmentPrint(HIGH, anim);
    else SegmentPrint(LOW, anim);

    for(uint8_t i = 0; i < 5; i++) SegmentPrint(HIGH, anim);
    SegmentPrint(LOW, anim);
    SegmentPrint(HIGH, anim);
}

void FourDigits_7segments_74HC595::Create7(bool dot, bool anim = false){
    if(dot) SegmentPrint(HIGH, anim);
    else SegmentPrint(LOW, anim);

    
    for(uint8_t i = 0; i < 4; i++) SegmentPrint(LOW, anim);
    for(uint8_t i = 0; i < 3; i++) SegmentPrint(HIGH, anim);
}

void FourDigits_7segments_74HC595::Create8(bool dot, bool anim = false){
    if(dot) SegmentPrint(HIGH, anim);
    else SegmentPrint(LOW, anim);

    for(uint8_t i = 0; i < 7; i++) SegmentPrint(HIGH, anim);
}

void FourDigits_7segments_74HC595::Create9(bool dot, bool anim = false){
    if(dot) SegmentPrint(HIGH, anim);
    else SegmentPrint(LOW, anim);

    SegmentPrint(HIGH, anim);
    SegmentPrint(HIGH, anim);

    SegmentPrint(LOW, anim);

    for(uint8_t i = 0; i < 4; i++) SegmentPrint(HIGH, anim);
}

void FourDigits_7segments_74HC595::Create0(bool dot, bool anim = false){
    if(dot) SegmentPrint(HIGH, anim);
    else SegmentPrint(LOW, anim);

    SegmentPrint(LOW, anim);

    for(uint8_t i = 0; i < 6; i++) SegmentPrint(HIGH, anim);
}

void FourDigits_7segments_74HC595::CreateMinus(bool anim = false){
    SegmentPrint(LOW, anim);
    SegmentPrint(HIGH, anim);
    
    for(uint8_t i = 0; i < 6; i++) SegmentPrint(LOW, anim);
}

void FourDigits_7segments_74HC595::CreateBlank(bool anim = false){
    for(uint8_t i = 0; i < 8; i++) SegmentPrint(LOW, anim);
}

void FourDigits_7segments_74HC595::intLogic(uint8_t num, bool anim){
    switch (num)
    {
    case 0:
        Create0(false, anim);
        break;
    case 1:
        Create1(false, anim);
        break;
    case 2:
        Create2(false, anim);
        break;
    case 3:
        Create3(false, anim);
        break;
    case 4:
        Create4(false, anim);
        break;
    case 5:
        Create5(false, anim);
        break;
    case 6:
        Create6(false, anim);
        break;
    case 7:
        Create7(false, anim);
        break;
    case 8:
        Create8(false, anim);
        break;
    case 9:
        Create9(false, anim);
        break;
    
    default:
        CreateBlank(anim);
        break;
    }
}

void FourDigits_7segments_74HC595::printInt(int theInt, bool anim = false){
    uint8_t splitUp[3];

    splitUp[0] = abs(theInt) % 10;
    splitUp[1] = (abs(theInt) / 10) % 10;
    splitUp[2] = abs(theInt) / 100;

    if(splitUp[2] == 0){
        splitUp[2] = 10;
        if(splitUp[1] == 0) splitUp[1] = 10;
    }

    for (uint8_t i = 0; i < 3; i++)
    {
        intLogic(splitUp[i], anim);
    }
    
    if(theInt < 0) CreateMinus(anim);
    else CreateBlank(anim);

    if(!anim){
        digitalWrite(_latch, HIGH);
        digitalWrite(_latch, LOW);
    }
}
