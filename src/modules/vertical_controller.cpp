#include "mbed.h"
#include "vertical_controller.hpp"

VerticalController::VerticalController(){
    f_t = 0;
}

void VerticalController::control(float z_r, float z, float w){
    float w_r, wl_r;

    w_r = Kp*(z_r - z);
    wl_r = Kd*(w_r - w);
    f_t = m*g + m*wl_r;
}