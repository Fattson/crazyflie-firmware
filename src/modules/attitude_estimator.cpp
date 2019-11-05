#include "mbed.h"
#include "attitude_estimator.hpp"

int AttitudeEstimator::sgn(double v) {
    if (v < 0) return -1;
    if (v > 0) return 1;
    return 0;
}

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

    for (int i=0; i<500; i++){
        imu.read();
        p_bias += imu.gx;
        q_bias += imu.gy;
        r_bias += imu.gz;
        wait(dt); 
    }
    p_bias = p_bias/500.0;
    q_bias = q_bias/500.0;
    r_bias = r_bias/500.0;
}

void AttitudeEstimator::estimate(){
     
    imu.read();

    // Desconto de erro
    p = imu.gx - p_bias;
    q = imu.gy - q_bias;
    r = imu.gz - r_bias;

    phi_g = phi + ( p + sin(phi)*tan(theta)*q + cos(phi)*tan(theta)*r )*dt;
    theta_g = theta + ( cos(phi)*q -sin(phi)*r )*dt;
    psi_g = psi + ( (sin(phi)/cos(theta))*q + (cos(phi)/cos(theta))*r )*dt;

    // Estimador acelerômetro
    phi_a = atan2(-imu.ay, -imu.az);
    theta_a = atan2(imu.ax, (-sgn(imu.az)*sqrt(pow(imu.ay,2) + pow(imu.az,2))));

    // Estimador complementar
    phi = (1.0 - alpha)*phi_g + alpha*phi_a;
    theta = (1.0 - alpha)*theta_g + alpha*theta_a;
    psi = psi_g;
    
}


