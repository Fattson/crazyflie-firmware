#include "mbed.h"
#include "crazyflie.h"

Mixer mixer;

int main(){
    mixer.arm();
    //wait_ms(0);
    
    mixer.actuate(0.7*m*g, 0, -0.005, 0);
    wait_ms(1000);

    mixer.disarm();
}