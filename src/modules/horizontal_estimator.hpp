#ifndef horizontal_estimator_hpp
#define horizontal_estimator_hpp

#include "mbed.h"
#include "src/utils/pin_names.h"
#include "src/utils/parameters.h"
#include "src/drivers/pmw3901.h"

class HorizontalEstimator {
    public:
        HorizontalEstimator();

        void init();
        void predict();
        void correct(float p, float q, float z, float phi, float theta);

        float x, u, y, v, d, px, py;

    private:
        PMW3901 flow;

        float x_m_last, y_m_last;
};

#endif