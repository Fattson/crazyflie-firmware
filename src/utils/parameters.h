#ifndef parameters_h
#define parameters_h
#include <cmath>

// Physical constanTs_att
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

const float OS_att = 0.005;
const float Ts_att = 0.3;
const float zeta_att = abs(log(OS_att))/(sqrt(pow(log(OS_att), 2) + pow(pi ,2)));
const float wn_att = 4.0/(zeta_att*Ts_att);
const float Kp_att = wn_att/(2.0*zeta_att);
const float Kd_att = 2.0*zeta_att*wn_att;

const float p1_range = 0.3;
const float p2_range = 0.3;

const float OS_vert = 0.25;
const float Ts_vert = 2.0;
const float zeta_vert = abs(log(OS_vert))/(sqrt(pow(log(OS_vert), 2) + pow(pi ,2)));
const float wn_vert = 4.0/(Ts_vert*zeta_vert);
const float Kp_vert = wn_vert/(2.0*zeta_vert);
const float Kd_vert = 2.0*zeta_vert*wn_vert;

#endif