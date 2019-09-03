#ifndef leds_h
#define leds_h

#include "mbed.h"
#include "utils/pin_names.h"
#include "utils/parameters.h"

#define ON true
#define OFF false

class Leds {
    private: 
        DigitalOut L_M1_R;
        DigitalOut L_M1_G;

        DigitalOut L_M2_R;
        DigitalOut L_M2_G;

        DigitalOut L_M3_B;

        void ledM1_R(bool status){
            L_M1_R = !status;
        }

        void ledM1_G(bool status){
            L_M1_G = !status;
        }

        void ledM2_R(bool status){
            L_M2_R = !status;
        }

        void ledM2_G(bool status){
            L_M2_G = !status;
        }

        void ledM3_B(bool status){
            L_M1_R = status;
        }

    public:
        Leds() : L_M1_R(LED_RED_R, !false), L_M1_G(LED_GREEN_R, !false),
                 L_M2_R(LED_RED_L, !false), L_M2_G(LED_GREEN_L, !false),
                 L_M3_B(LED_BLUE_L, !true) {
            ledM1_R(OFF);
            ledM1_G(OFF);

            ledM2_R(OFF);
            ledM2_G(OFF);

            ledM3_B(OFF);
        }

        void start_up() {
            bool status = true;

            for(int i = 0; i < 5; i++){
                ledM1_R(status);
                ledM2_R(status);
                wait_ms(200);
                status = !status;
            }
        }

        void armed() {
            ledM1_R(ON);
            ledM2_R(ON);

            ledM1_G(OFF);
            ledM2_G(OFF);
        }

        void disarmed() {
            ledM1_G(ON);
            ledM2_G(ON);

            ledM1_R(OFF);
            ledM2_R(OFF);
        }

};

#endif