#ifndef horizontal_controller_h
#define horizontal_controller_h

#include "mbed.h"
#include "src/utils/parameters.h"

// horizontal controller class
class HorizontalController{

    public:
        HorizontalController();
        void control(float x_r, float x, float u, float y_r, float y, float v);
        float phi_r, theta_r;
};

#endif