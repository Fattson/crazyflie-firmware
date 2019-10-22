#include "mbed.h"
#include "vertical_estimator.h"

VerticalEstimator::VerticalEstimator()  : range(E_SDA, E_SCL) {
    z = 0, w = 0;
}

void VerticalEstimator::init() {
    range.init();
}

void VerticalEstimator::predict(){
    
}

void VerticalEstimator::correct(float phi, float theta){

}