#ifndef VerticalEstimator_h
#define VerticalEstimator_h

#include "mbed.h"
#include "parameters.h"
#include "vl53l0x.h"

class VerticalEstimator {
    public:
        VerticalEstimator();

        void init();
        void predict();
        void correct(float phi, float theta);

        float z, w;

    private:
        VL53L0X range;

        float z_m_last;
};

#endif