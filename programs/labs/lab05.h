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

void forces_to_rads(float F_t, float T_Phi, float T_theta, float T_psi, float * w1, float * w2, float * w3, float * w4){
    float sigma1 = T_theta/(4.0*kl*l);
    float sigma2 = T_Phi/(4.0*kl*l);
    float sigma3 = T_psi/(4.0*kd);
    float sigma4 = F_t/(4*kl);

    float w1_s = sigma4-sigma3-sigma2-sigma1;
    float w2_s = sigma4+sigma3-sigma2+sigma1;
    float w3_s = sigma4-sigma3+sigma2+sigma1;
    float w4_s = sigma4+sigma3+sigma2-sigma1;

    if(w1_s < 0){
        *w1 = 0;
    } else {
        *w1 = sqrt(w1_s);
    }
    
    if(w2_s < 0){
        *w2 = 0;
    } else {
        *w2 = sqrt(w2_s);
    }

    if(w3_s < 0){
        *w3 = 0;
    } else {
        *w3 = sqrt(w3_s);
    }

    if(w4_s < 0){
        *w4 = 0;
    } else {
        *w4 = sqrt(w4_s);
    }
}

void actuate(float F_t, float T_Phi, float T_theta, float T_psi, float * w1, float * w2, float * w3, float * w4){
    forces_to_rads(F_t, T_Phi, T_theta, T_psi, w1, w2, w3, w4);
    M1 = control_motor(*w1);
    M2 = control_motor(*w2);
    M3 = control_motor(*w3);
    M4 = control_motor(*w4);
}

int main(){
    float w1, w2, w3, w4;

    wait_ms(2000);
    
    actuate(0.2, 0, 0, 0, &w1, &w2, &w3, &w4);
    wait_ms(1000);

    actuate(0, 0.005, 0, 0, &w1, &w2, &w3, &w4);
    actuate(0, -0.005, 0, 0, &w1, &w2, &w3, &w4);
    wait_ms(1000);

    actuate(0, 0, 0.005, 0, &w1, &w2, &w3, &w4);
    actuate(0, 0, -0.005, 0, &w1, &w2, &w3, &w4);
    wait_ms(1000);

    actuate(0, 0, 0, 0.001, &w1, &w2, &w3, &w4);
    actuate(0, 0, 0, -0.001, &w1, &w2, &w3, &w4);
    wait_ms(1000);

    actuate(0, 0, 0, 0, &w1, &w2, &w3, &w4);

}