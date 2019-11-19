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
HorizontalController hor_cont;

// Ticker objects
Ticker tic;
Ticker tic_range;

// Interrupt flag and counter variables
bool flag, flag_range;

// Set references
float tfly = 20.0; // sec.
float t2 = 0.5;
float cont_max = tfly/dt;
float h_max = 0.8f;
float t1 = (cont_max-2000.0)/4.0 - t2/dt;

float x_r = 0.0f;
float y_r = 0.0f;
float x_max = 1.0f;
float y_max = 1.0f;
float z_r = 0.8f;
float theta_r = 0.0f;
float phi_r = 0.0f;
float psi_r = 0.0f;

// Callback functions
void callback(){
    flag = true;
}

void callback_range(){
    flag_range = true;
}

void zr_up(int contador){
    z_r = (h_max/1000.0)*(float)contador;
}

void zr_down(int contador){
    z_r = h_max - (1.4*h_max/1000.0)*((float)contador-cont_max+1000.0);
}

void z_ref(int contador){
    if(contador <= 1000){
        zr_up(contador);
    } else if (contador >= (cont_max-1000.0)){
        zr_down(contador);
    } else {
        z_r = h_max;
    }
}

void square(int contador, int cont_max){
    if (contador <= 1000){
        x_r = 0.0f;
        y_r = 0.0f;
    } else if (contador <= (t1+1000)){
        x_r = (x_max/t1)*(contador-1000);
        y_r = 0.0f;
    } else if (contador <= (t1+1000+t2)){
        x_r = x_r;
        y_r = y_r;
    } else if (contador <= (1000+2*t1+t2)){
        x_r = x_r;
        y_r = (-y_max/t1)*(contador-1000-t1-t2);
    } else if (contador <= (1000+2*t1+2*t2)){
        x_r = x_r;
        y_r = y_r;
    } else if (contador <= (1000+3*t1+2*t2)){
        x_r = x_max - (x_max/t1)*(contador-1000-2*t1-2*t2);
        y_r = y_r;
    } else if (contador <= (1000+3*t1+3*t2)){
        x_r = x_r;
        y_r = y_r;
    } else if (contador <= (1000+4*t1+3*t2)){
        x_r = x_r;
        y_r = -y_max + (y_max/t1)*(contador-1000-3*t1-3*t2);
    } else if (contador <= (1000+4*t1+4*t2)){
        x_r = 0.0f;
        y_r = 0.0f;
    }
}

int contador = 0;

// Main program
int main (){

    // Initialize estimators objects
    att_est.init();
    vert_est.init();
    hor_est.init();

    // Initialize interrupts
    tic.attach(&callback, dt);
    tic_range.attach(&callback_range, dt_range);   

    // Arm motors and run controller while stable
    mixer.arm();

    while (att_est.withinSafeLimits() && contador < cont_max){
        z_ref(contador);
        square(contador, cont_max);

        if (flag){
            flag = false;
            att_est.estimate();
            vert_est.predict();

            hor_est.correct(att_est.p, att_est.q, vert_est.z, att_est.phi, att_est.theta);
            hor_est.predict();

            if (flag_range){
                flag_range = false;
                vert_est.correct(att_est.phi, att_est.theta);

                serial.printf("%.2f %.2f %.2f %d\n\r", x_r, y_r, z_r, contador);
                // serial.printf("Flow [m]: %.2f %.2f | [m/s] %.2f %.2f\n\r", hor_est.x, hor_est.y, hor_est.u, hor_est.v);
                // serial.printf("PXs %6.0f %6.0f\n\r", hor_est.px, hor_est.py);
                // serial.printf("D: %.2f\n\r", hor_est.d);
                // serial.printf("Range: %.2f\n\r", vert_est.z);
                // serial.printf("Angles: %.2f %.2f %.2f\n\r", att_est.phi, att_est.theta, att_est.psi);
                // serial.printf("Controller: %.2f %.2f\n\r", hor_cont.phi_r, hor_cont.theta_r);
                // serial.printf("Angular Speed: %.2f %.2f %.2f\n\r", att_est.p, att_est.q, att_est.r);
            }  

            vert_cont.control(z_r, vert_est.z, vert_est.w);
            hor_cont.control(x_r, hor_est.x, hor_est.u, y_r, hor_est.y, hor_est.v);
            att_cont.control(hor_cont.phi_r, hor_cont.theta_r, psi_r, att_est.phi, att_est.theta, att_est.psi, att_est.p, att_est.q, att_est.r);
            //att_cont.control(phi_r, theta_r, psi_r, att_est.phi, att_est.theta, att_est.psi, att_est.p, att_est.q, att_est.r);
            //mixer.actuate(vert_cont.f_t/(cos(att_est.phi)*cos(att_est.theta)), att_cont.tau_phi, att_cont.tau_theta, att_cont.tau_psi);

            contador++;
        } 
            
    }

    // Disarm motors and end program
    mixer.disarm();
    while(1);
}
