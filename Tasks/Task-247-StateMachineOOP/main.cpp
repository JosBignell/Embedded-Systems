#include "uop_msb.h"
#include "SwitchTimerLedManager.hpp"
#include "FlashLED.hpp"
#include <chrono>
#include <ratio>
using namespace uop_msb;
using namespace chrono;


SwitchTimerLedManager fsm1(BTN1_PIN, SwitchTimerLedManager::UP);
SwitchTimerLedManager fsm2(BTN2_PIN, SwitchTimerLedManager::DOWN);

FlashLED greenLED(TRAF_GRN1_PIN, 200ms);     //Green Traffic 1
FlashLED yellowLED(TRAF_YEL1_PIN, 300ms);
FlashLED redLED(TRAF_RED1_PIN, 400ms);

//Dual Digit 7-segment Display
LatchedLED disp(LatchedLED::SEVEN_SEG);

int main()
{
    int count = 0;

    //Turn ON the 7-segment display
    disp.enable(true);
    disp = 0;
    

    while (true) {

        // **********
        //Poll inputs
        // **********
        fsm1.readInputs();
        fsm2.readInputs();
        greenLED.readInputs();
        yellowLED.readInputs();
        redLED.readInputs();

        // **********************************
        // UPDATE "STATE" for buttons A and B
        // **********************************
        fsm1.updateState(count);
        fsm2.updateState(count);
        greenLED.updateState();
        yellowLED.updateState();
        redLED.updateState();

        

        // UPDATE OUTPUTS
        disp = count;
  
    }
}





