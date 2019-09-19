#include "mbed.h"
#include "attitude_estimator.hpp"

AttitudeEstimator::AttitudeEstimator() : imu(IMU_SDA, IMU_SCL){
    phi = 0;
    theta = 0;
    psi = 0;
    p = 0;
    q = 0;
    r = 0;
}

void AttitudeEstimator::init(){
    imu.init();
}

void AttitudeEstimator::estimate(){
    imu.read();
    //float p = imu.gx;
    //float phi_g = phi_g +  p*dt;
    //phi = phi_g;
    float phi_a = atan2(-imu.ay, -imu.az);
    phi = (1-alpha)*phi_a + alpha*phi;
}
