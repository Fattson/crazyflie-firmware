#include "mbed.h"
#include "crazyflie.h"

int main(){
    Mixer mixer;

    mixer.arm();

    // mixer.actuate(0.7*m*g,0,0,0);
    wait_ms(1000);
    mixer.stop_all();

    mixer.disarm();
}