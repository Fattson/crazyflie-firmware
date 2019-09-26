#ifndef attitude_controller_h
#define attitude_controller_h

#include "mbed.h"
#include "src/utils/parameters.h"

// Attitude controller class
class AttitudeController{

    public:
        AttitudeController();
        void control(float phi_r, float theta_r, float psi_r, float phi, float theta, float psi, float p, float q, float r);
        float tau_phi, tau_theta, tau_psi;

    private:
        float control_state_regulator(float angle_r, float angle, float rate, float kp, float kd);
};

#endif