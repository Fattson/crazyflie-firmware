#ifndef parameters_h
#define parameters_h

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
const float alpha = 0.01;            // Fator de suavização filtro 
const float Kp = 5;
const float Kd = 25;

#endif