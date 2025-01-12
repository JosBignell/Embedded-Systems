#include "mbed.h"

// Hardware Definitions
#define TRAF_GRN1_PIN PC_6
#define TRAF_YEL1_PIN PC_3
#define TRAF_RED1_PIN PC_2
#define LEDMASK 0b0000000001001100
// Objects
//BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);
PortOut leds(PortC, LEDMASK);

#define TRAF_GRN2_PIN PB_0
#define TRAF_YEL2_PIN PB_7
#define TRAF_RED2_PIN PB_14
#define LEDMASK2 0b0100000010000001

PortOut leds2(PortB, LEDMASK2);

int main()
{
    while (true) {
        leds = leds^LEDMASK;   //Binary 000
        wait_us(500000);
        leds2 = leds2^LEDMASK2;   //Binary 11111111
        wait_us(500000);    
    }
}




