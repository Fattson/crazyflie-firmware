#include "mbed.h"
#include "crazyflie.h"

PwmOut M1(MOTOR1);

float control_motor(float omega_r){
    float p1 = 1.219e-7f;
    float p2 = 1.211e-12f;

    return (p1*omega_r*omega_r + p2*omega_r);
}

float rpm_to_rads(float rpm){
    return 2.0f*pi*rpm/60.0f;
}

int main(){
    M1 = control_motor(rpm_to_rads(24000.0));
    wait(20);
    M1 = 0.0;
}