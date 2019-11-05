#include "mbed.h"
#include "horizontal_estimator.hpp"
#include "src/utils/parameters.h"
#include "crazyflie.h"
#include <cmath>

HorizontalEstimator::HorizontalEstimator() : flow(E_MOSI,E_MISO,E_SCK,E_CS1) {
    u = 0;
    v = 0;
}

void HorizontalEstimator::init() {
    flow.init();
}

void HorizontalEstimator::predict(){
    x = x + u*dt;
    u = u;
    
    y = y + v*dt;
    v = v;
}

void HorizontalEstimator::estimate(float p, float q, float d) {
    flow.read();

    float u_m = (sigma*flow.px + q)*d;
    float x_m = x_m_last + u_m*dt;
    x_m_last = x_m;

    x = x + alpha_flow*(x_m-x);
    u = u + alpha_flow*(u_m-u);
    
    float v_m = (sigma*flow.py - p)*d;
    float y_m = y_m_last + v_m*dt;
    y_m_last = y_m;

    y = y + alpha_flow*(y_m-y);
    v = v + alpha_flow*(v_m-v);
}