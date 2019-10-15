#include "mbed.h"
#include "attitude_controller.hpp"

AttitudeController::AttitudeController(){
    tau_phi = 0;
    tau_theta = 0;
    tau_psi = 0;
    
}

void AttitudeController::control(float phi_r, float theta_r, float psi_r, float phi, float theta, float psi, float p, float q, float r){

    float q_r, ql_r, p_r, pl_r, r_r, rl_r;

    q_r = Kp*(theta_r - theta);
    ql_r = Kd*(q_r - q);
    tau_theta = ql_r*I_yy;

    p_r = Kp*(phi_r - phi);
    pl_r = Kd*(p_r - p);
    tau_phi = pl_r*I_xx;

    r_r = Kp*(psi_r - psi);
    rl_r = Kd*(r_r - r);
    tau_psi = rl_r*I_zz;
}

// float AttitudeController::control_state_regulator(float angle_r, float angle, float rate, float kp, float kd){

// }
