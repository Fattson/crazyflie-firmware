#include "mbed.h"
#include "crazyflie.h"
#include "USBSerial.h"

USBSerial serial;

// Crazyflie controller objects
Mixer mixer;
AttitudeEstimator att_est;
AttitudeController att_cont;
VerticalEstimator vert_est;
VerticalController vert_cont;
HorizontalEstimator hor_est;

// Ticker objects
Ticker tic;
Ticker tic_range;

// Interrupt flag and counter variables
bool flag, flag_range;

// Callback functions
void callback(){
    flag = true;
}

void callback_range(){
    flag_range = true;
}

int contador= 0;

// Main program
int main (){

    // Set references
    float z_r = 0.5f;
    float phi_r = 0.0f;
    float theta_r = 0.0f;
    float psi_r = 0.0f;

    // Initialize estimators objects
    att_est.init();
    vert_est.init();
    hor_est.init();

    // Initialize interrupts
    tic.attach(&callback, dt);
    tic_range.attach(&callback_range, dt_range);   

    // Arm motors and run controller while stable
    mixer.arm();

    while (abs( att_est.phi ) <= pi /4.0f && abs( att_est.theta ) <= pi /4.0f && abs 
    (att_est.p) <= 4.0f*pi && abs( att_est.q) <= 4.0f*pi && abs( att_est.r) <= 4.0f*pi && contador < 1500){
    
        if (flag){
            flag = false;
            att_est.estimate();
            vert_est.predict();

            hor_est.estimate(att_est.p, att_est.q, vert_est.d);
            hor_est.predict();

            if (flag_range){
                flag_range = false;
                vert_est.correct(att_est.phi, att_est.theta);

                serial.printf("\nFlow [m]: %.2f %.2f | [m/s] %.2f %.2f\n\r", hor_est.x, hor_est.y, hor_est.u, hor_est.v);
                serial.printf("Angles: %.2f %.2f %.2f\n\r", att_est.phi, att_est.theta, att_est.psi);
                serial.printf("Angular Speed: %.2f %.2f %.2f\n\r", att_est.p, att_est.q, att_est.r);
            }  

            vert_cont.control(z_r, vert_est.z, vert_est.w);
            att_cont.control(phi_r, theta_r, psi_r, att_est.phi, att_est.theta, att_est.psi, att_est.p, att_est.q, att_est.r);
            // mixer.actuate(vert_cont.f_t/(cos(att_est.phi)*cos(att_est.theta)), att_cont.tau_phi, att_cont.tau_theta, att_cont.tau_psi);

            // serial.printf("%f \n\r", att_cont.tau_theta);
            // contador++;
        } 
            
    }

    // Disarm motors and end program
    mixer.disarm();
    while(1);
}
