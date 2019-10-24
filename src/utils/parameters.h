#ifndef parameters_h
#define parameters_h
#include <cmath>

// Physical constants
const float pi = 3.1416f;
const float g = 9.81f;              // m/s^2

// Quadcopter dimensions
const float m = 30e-3f;             // kg
const float I_xx = 16.0e-6f;        // kg.m^2
const float I_yy = 16.0e-6f;        // kg.m^2
const float I_zz = 29.0e-6f;        // kg.m^2
const float l = 33e-3f;             // m
const float p1 = 1.219e-7f;         // Coef. calib. pwm
const float p2 = 1.211e-12f;        // Coef. calib. pwm
const float kl = 1.927e-08;         // Const. sustentação
const float kd = 1.4538e-10;        // Const. de arrasto
const float dt = 2e-3;              // Intervalo de tempo
const float dt_range = 50e-3;
const float alpha = 0.01;            // Fator de suavização filtro 

const float OS = 0.005;
const float Ts = 0.3;
const float zeta = abs(log(OS))/(sqrt(pow(log(OS), 2) + pow(pi ,2)));
const float wn = 4/(zeta*Ts);
const float Kp = wn/(2*zeta);
const float Kd = 2*zeta*wn;

const float p1_range = 0.3;
const float p2_range = 0.3;

#endif