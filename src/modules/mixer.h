#ifndef mixer_h
#define mixer_h

#include "mbed.h"
#include "utils/pin_names.h"
#include "utils/parameters.h"
#include "modules/leds.h"



class Mixer {
    private:
        PwmOut M1;
        PwmOut M2;
        PwmOut M3;
        PwmOut M4;

        float w1, w2, w3, w4;
        bool armed; 

        float control_motor(float omega_r);
        
        float rpm_to_rads(float rpm);
        
        void forces_to_rads(float F_t, float T_Phi, float T_theta, float T_psi);
        

    public:
        Mixer();
        
        Leds leds;

        void actuate(float F_t, float T_Phi, float T_theta, float T_psi);
        
        void stop_all();

        void arm();
        
        void disarm();
        
};

#endif