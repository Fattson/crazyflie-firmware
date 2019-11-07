#include "mbed.h"
#include "horizontal_controller.hpp"

HorizontalController::HorizontalController(){
    phi_r = 0.0;
    theta_r = 0.0;
}

void HorizontalController::control(float x_r, float x, float u, float y_r, float y, float v){
    float u_r, ul_r, v_r, vl_r;

    u_r = Kp_hor*(x_r - x);
    ul_r = Kd_hor*(u_r - u);
    // wl_r = Kp_vert*(z_r - z) + Kd_vert*(0.0f - w);
    theta_r = (1.0f/g)*ul_r;

    v_r = Kp_hor*(y_r - y);
    vl_r = Kd_hor*(v_r - v);
    // wl_r = Kp_vert*(z_r - z) + Kd_vert*(0.0f - w);
    phi_r = (-1.0f/g)*vl_r;
}