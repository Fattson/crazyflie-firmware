#include "mbed.h"
#include "attitude_estimator.h"

float A_phi;
float A_theta;
float A_ksi;
float V_p;
float V_q;
float V_r;

AttitudeEstimador::AttitudeEstimator() : imu(IMU_SDA, IMU_SCL){
    A_phi = 0;
    A_theta = 0;
    A_ksi = 0;
    V_p = 0;
    V_q = 0;
    V_r = 0;
}

void AttitudeEstimator::init(){

}

void AttitudeEStimator::estimate(){

}
