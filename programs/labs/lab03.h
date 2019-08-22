#include "mbed.h"
#include "crazyflie.h"

PwmOut M1(MOTOR1);
PwmOut M2(MOTOR2);
PwmOut M3(MOTOR3);
PwmOut M4(MOTOR4);

float control_motor(float omega_r){
    return (p1*omega_r*omega_r + p2*omega_r);
}

float rpm_to_rads(float rpm){
    return 2.0f*pi*rpm/60.0f;
}

int main(){
    M1 = control_motor(2200.0);
    M2 = control_motor(2200.0);
    M3 = control_motor(2200.0);
    M4 = control_motor(2200.0);
    wait_ms(5000);
    M1 = 0.0;
    M2 = 0.0;
    M3 = 0.0;
    M4 = 0.0;

}