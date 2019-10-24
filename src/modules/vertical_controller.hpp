#ifndef vertical_controller_h
#define vertical_controller_h

#include "mbed.h"
#include "src/utils/parameters.h"

// vertical controller class
class VerticalController{

    public:
        VerticalController();
        void control(float z_r, float z, float w);
        float f_t;
};

#endif