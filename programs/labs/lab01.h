#include "mbed.h"
#include "crazyflie.h"

// Define all LEDs as digital output objects

DigitalOut ledM1(LED_RED_R, !false);
DigitalOut ledM2(LED_RED_L, !false);
DigitalOut ledM3(LED_BLUE_L, !true);

// Define all motors as PWM objects

PwmOut motor1(MOTOR1);
PwmOut motor2(MOTOR2);
PwmOut motor3(MOTOR3);
PwmOut motor4(MOTOR4);

// Main program
int main()
{
    // Blink blue LED indicating inicialization (5 seconds)
    int i;
    for (i=0; i<10; i++)
    {
    ledM1 = !ledM1;
    ledM2 = !ledM2;
    ledM3 = !ledM3;
    wait_ms(500);
    }
    
    // Turn on red LEDs indicating motors are armed

    ledM1 = !true;
    motor1 = 0.2;
    wait_ms(1000);
    motor1 = 0;
    ledM1 = !false;
    
    // Test all motors with different frequencies (to make different noises)
    
    // Turn off red LEDs indicating motors are disarmed
    
    // Blink green LEDs indicating end of program
    while(true)
    {
        
    }
}
