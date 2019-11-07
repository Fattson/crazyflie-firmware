#ifndef parameters_h
#define parameters_h
#include <cmath>

// Physical constanTs_att
const float pi = 3.1416f;
const float g = 9.81f;              // m/s^2

// Quadcopter dimensions
const float m = 0.03;             // kg
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
const float Ts_att = 0.1;
const float zeta_att = abs(log(OS_att))/(sqrt(pow(log(OS_att), 2) + pow(pi ,2)));
const float wn_att = 4.0/(zeta_att*Ts_att);
const float Kp_att = wn_att/(2.0*zeta_att);
// const float Kp_att = pow(wn_att,2);
const float Kd_att = 2.0*zeta_att*wn_att;

const float OS_att2 = 0.005;
const float Ts_att2 = 0.6;
const float zeta_att2 = abs(log(OS_att2))/(sqrt(pow(log(OS_att2), 2) + pow(pi ,2)));
const float wn_att2 = 4.0/(zeta_att2*Ts_att2);
const float Kp_att2 = wn_att2/(2.0*zeta_att2);
// const float Kp_att2 = pow(wn_att2,2);
const float Kd_att2 = 2.0*zeta_att2*wn_att2;

const float p1_range = 0.3;
const float p2_range = 0.3;

const float OS_vert = 0.005;
const float Ts_vert = 2.0;
const float zeta_vert = abs(log(OS_vert))/(sqrt(pow(log(OS_vert), 2) + pow(pi ,2)));
const float wn_vert = 4.0/(Ts_vert*zeta_vert);
const float Kp_vert = wn_vert/(2.0*zeta_vert);
// const float Kp_vert = pow(wn_vert,2);
const float Kd_vert = 2.0*zeta_vert*wn_vert;

const float gamma = 0.733f;
const float W = 420.0f;
const float sigma = 2.0f*tan(gamma/2.0f)/(W*dt);
const float alpha_flow = 0.3f;

const float OS_hor = 0.001;
const float Ts_hor = 4.0;
const float zeta_hor = abs(log(OS_hor))/(sqrt(pow(log(OS_hor), 2) + pow(pi ,2)));
const float wn_hor = 4.0/(Ts_hor*zeta_hor);
const float Kp_hor = wn_hor/(2.0*zeta_hor);
// const float Kp_hor = pow(wn_hor,2);
const float Kd_hor = 2.0*zeta_hor*wn_hor;

#endif