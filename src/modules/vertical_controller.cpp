#include "mbed.h"
#include "vertical_controller.hpp"

VerticalController::VerticalController(){
    f_t = 0;
}

void VerticalController::control(float z_r, float z, float w){
    float w_r, wl_r;

    w_r = Kp_vert*(z_r - z);
    wl_r = Kd_vert*(w_r - w);
    // wl_r = Kp_vert*(z_r - z) + Kd_vert*(0.0f - w);
    f_t = m*g + m*wl_r;
}