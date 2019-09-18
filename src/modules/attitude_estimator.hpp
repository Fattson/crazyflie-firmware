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

        float phi, theta, psi;
        float p, q, r;

    private:
        MPU9250 imu;
};

#endif