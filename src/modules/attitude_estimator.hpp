#ifndef attitude_estimator_hpp
#define attitude_estimator_hpp

#include "mbed.h"
#include "src/utils/pin_names.h"
#include "src/utils/parameters.h"
#include "src/drivers/mpu9250.h"

class AttitudeEstimator {
    public:
        AttitudeEstimator();

        void init();
        void estimate();
        bool withinSafeLimits();
        int sgn(double v);

        float phi, theta, psi;
        float p, q, r;

    private:
        MPU9250 imu;
        float p_bias, q_bias, r_bias;
        float phi_a, theta_a;
        float phi_g, theta_g, psi_g;
};

#endif