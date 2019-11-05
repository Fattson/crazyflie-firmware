#include "mbed.h"
#include "attitude_controller.hpp"
#include "parameters.h"

AttitudeController::AttitudeController(){
    tau_phi = 0;
    tau_theta = 0;
    tau_psi = 0;
    
}

void AttitudeController::control(float phi_r, float theta_r, float psi_r, float phi, float theta, float psi, float p, float q, float r){

    float q_r, ql_r, p_r, pl_r, r_r, rl_r;

    q_r = Kp_att*(theta_r - theta);
    ql_r = Kd_att*(q_r - q);
    // ql_r = Kp_att*(theta_r - theta) + Kd_att*(0.0 - q);
    tau_theta = ql_r*I_yy;

    p_r = Kp_att*(phi_r - phi);
    pl_r = Kd_att*(p_r - p);
    // pl_r = Kp_att*(phi_r - phi) + Kd_att*(0.0 - p);
    tau_phi = pl_r*I_xx;

    r_r = Kp_att2*(psi_r - psi);
    rl_r = Kd_att2*(r_r - r);
    // rl_r = Kp_att*(psi_r - psi) + Kd_att*(0.0 - r);
    tau_psi = rl_r*I_zz;
}
