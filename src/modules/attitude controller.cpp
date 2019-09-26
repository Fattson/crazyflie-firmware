#include "mbed.h"
#include "attitude_controller.h"

AttitudeController::AttitudeController(){
    tau_phi = 0;
    tau_theta = 0;
    tau_psi = 0;
    
}

void AttitudeController::control(float phi_r, float theta_r, float psi_r, float phi, float theta, float psi, float p, float q, float r){

}

float AttitudeController::control_state_regulator(float angle_r, float angle, float rate, float kp, float kd){

}
