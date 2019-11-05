#include "mbed.h"
#include "crazyflie.h"
#include "USBSerial.h"

// USBSerial serial;

// Crazyflie controller objects
Mixer mixer;
AttitudeEstimator att_est;
AttitudeController att_cont;

// Ticker objects
Ticker tic;

// Interrupt flag and counter variables
bool flag;

// Callback functions
void callback(){
flag = true;
}
int contador= 0;

// Main program
int main (){

    // Set references
    float f_t = 1*m*g;
    float phi_r = 0.0f;
    float theta_r = 0.0f;
    float psi_r = 0.0f;

    // Initialize estimators objects
    att_est.init();

    // Initialize interrupts
    tic.attach(&callback, dt);

    // Arm motors and run controller while stable
    mixer.arm();

    while (abs( att_est.phi ) <= pi /4.0f && abs( att_est.theta ) <= pi /4.0f && abs 
    (att_est.p) <= 4.0f*pi && abs( att_est.q) <= 4.0f*pi && abs( att_est.r) <= 4.0f*pi && contador < 1500){
    

        if (flag){

            flag = false;
            att_est.estimate();
            att_cont.control (phi_r, theta_r, psi_r, att_est.phi, att_est.theta, att_est.psi, att_est.p, att_est.q, att_est.r);
            mixer.actuate(f_t, 0.0f, att_cont.tau_theta, 0.0f);

            // serial.printf("%f \n\r", att_cont.tau_theta);
            contador++;
            }
            
    }

    // Disarm motors and end program
    mixer.disarm();
    while(1);
}