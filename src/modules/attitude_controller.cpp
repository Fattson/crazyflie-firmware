#include "mbed.h"
#include "attitude_controller.hpp"

AttitudeController::AttitudeController(){
    tau_phi = 0;
    tau_theta = 0;
    tau_psi = 0;
    
}

void AttitudeController::control(float phi_r, float theta_r, float psi_r, float phi, float theta, float psi, float p, float q, float r){

    float q_r, ql_r, p_r, pl_r;

    q_r = Kp*(theta_r - theta);
    ql_r = Kd*(q_r - q);
    tau_theta = ql_r*I_yy;

    p_r = Kp*(phi_r - phi);
    pl_r = Kd*(p_r - p);
    tau_theta = pl_r*I_xx;
}

// float AttitudeController::control_state_regulator(float angle_r, float angle, float rate, float kp, float kd){

// }
