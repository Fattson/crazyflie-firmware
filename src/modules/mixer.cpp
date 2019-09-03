#include "mixer.h"


Mixer::Mixer() : M1(MOTOR1), M2(MOTOR2), M3(MOTOR3), M4(MOTOR4) {
            w1 = 0.0;
            w2 = 0.0;
            w3 = 0.0;
            w4 = 0.0;
            armed = false;
        }

void Mixer::actuate(float F_t, float T_Phi, float T_theta, float T_psi){
    if(armed){

        M1.period(1.0/500.0);
        M2.period(1.0/500.0);
        M3.period(1.0/500.0);
        M4.period(1.0/500.0);

        forces_to_rads(F_t, T_Phi, T_theta, T_psi);
        M1 = control_motor(w1);
        M2 = control_motor(w2);
        M3 = control_motor(w3);
        M4 = control_motor(w4);
    }
}

void Mixer::stop_all(){
    actuate(0, 0, 0, 0);
}

void Mixer::arm(){
    if(!armed){
        leds.start_up();
        leds.armed();
        armed = true;

        M1.period(1.0/1567.98);
        M1 = 0.1;
        wait_ms(500);
        stop_all();

        M2.period(1.0/880.0);
        M2 = 0.1;
        wait_ms(500);
        stop_all(); 

        M3.period(1.0/523.25);
        M3 = 0.1;
        wait_ms(500);
        stop_all();

        M4.period(1.0/1567.98);
        M4 = 0.1;
        wait_ms(300);
        stop_all();

        M1.period(1.0/587.33);
        M4 = 0.1;
        wait_ms(1000);
        stop_all();
        
        wait_ms(1000);

    }
}
void Mixer::disarm(){
    
    M4.period(1.0/3135.96);
    M4 = 0.1;
    wait_ms(300);
    stop_all();

    M3.period(1.0/2349.32);
    M3 = 0.1;
    wait_ms(300);
    stop_all();

    M2.period(1.0/1567.98);
    M2 = 0.1;
    wait_ms(300);
    stop_all(); 

    M1.period(1.0/1760.0);
    M1 = 0.1;
    wait_ms(800);
    stop_all();

    wait_ms(1000);

    leds.disarmed();
    armed = false;
}

float Mixer::control_motor(float omega_r){
    return (p1*omega_r*omega_r + p2*omega_r);
}

float Mixer::rpm_to_rads(float rpm){
    return 2.0f*pi*rpm/60.0f;
}

void Mixer::forces_to_rads(float F_t, float T_Phi, float T_theta, float T_psi){
    float sigma1 = T_theta/(4.0*kl*l);
    float sigma2 = T_Phi/(4.0*kl*l);
    float sigma3 = T_psi/(4.0*kd);
    float sigma4 = F_t/(4*kl);

    float w1_s = sigma4-sigma3-sigma2-sigma1;
    float w2_s = sigma4+sigma3-sigma2+sigma1;
    float w3_s = sigma4-sigma3+sigma2+sigma1;
    float w4_s = sigma4+sigma3+sigma2-sigma1;

    if(w1_s < 0){
        w1 = 0;
    } else {
        w1 = sqrt(w1_s);
    }
    
    if(w2_s < 0){
        w2 = 0;
    } else {
        w2 = sqrt(w2_s);
    }

    if(w3_s < 0){
        w3 = 0;
    } else {
        w3 = sqrt(w3_s);
    }

    if(w4_s < 0){
        w4 = 0;
    } else {
        w4 = sqrt(w4_s);
    }
}