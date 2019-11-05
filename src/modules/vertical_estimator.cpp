#include "mbed.h"
#include "vertical_estimator.hpp"
#include "crazyflie.h"
#include <cmath>

VerticalEstimator::VerticalEstimator()  : range(E_SDA, E_SCL) {
    z = 0, w = 0, z_m_last = 0;
}

void VerticalEstimator::init() {
    range.init();
}

void VerticalEstimator::predict(){
    w = w;
    z = z + w*dt;
}

void VerticalEstimator::correct(float phi, float theta){
    range.read();
    if (range.d <= 2.0)
    {
    float z_m = (range.d)*cos(phi)*cos(theta);
    float w_m = (z_m-z_m_last)/dt_range;

    z_m_last = z_m;
    w = w + p1_range*(w_m-w);
    z = z + p2_range*(z_m-z);
    }
}