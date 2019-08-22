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

void forces_to_rads(float F_t, float T_psi, float T_Phi, float T_theta, float * w1, float * w2, float * w3, float * w4){
    float sigma1 = T_theta/(4.0*kl*l);
    float sigma2 = T_Phi/(4.0*kl*l);
    float sigma3 = T_psi/(4.0*kd);
    float sigma4 = F_t/(4*kl);

    *w1 = sqrt(sigma4-sigma3-sigma2-sigma1);
    *w2 = sqrt(sigma4+sigma3-sigma2+sigma1); 
    *w3 = sqrt(sigma4-sigma3+sigma2+sigma1); 
    *w4 = sqrt(sigma4+sigma3+sigma2-sigma1); 
}

int main(){
    float w1, w2, w3, w4;

    wait_ms(2000);
    M1 = control_motor(1000.0);
    M2 = control_motor(2000.0);
    M3 = control_motor(1000.0);
    M4 = control_motor(2000.0);
    wait_ms(1500);
    M1 = 0.0;
    M2 = 0.0;
    M3 = 0.0;
    M4 = 0.0;

}