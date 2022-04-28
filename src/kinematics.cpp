#include <Arduino.h>
#include <math.h>

double e0=0, e1=0, e2=0, e3=0;
double alphaP=0;
double eta[3] = {0,0,0};

// Tool to reference - transformation via Quaternions
double T_TtoR[4][4] = {
    { ( pow(e0,2)+ pow(e1,2)-pow(e2,2)-pow(e3,2)), 2*(e1*e2-e0*e3), 2*(e1*e3+e0*e2), 0},
    { 2*(e1*e2+e0*e3), (pow(e0,2)-pow(e1,2)+pow(e2,2)-pow(e3,2)), 2*(e2*e3-e0*e1), 0},
    { 2*(e1*e3-e0*e2), 2*(e2*e3+e0*e1), (pow(e0,2)-pow(e1,2)-pow(e2,2)+pow(e3,2)), 0}, 
    { 0, 0, 0, 1}};

/* Determination of Theta1-3
 =================
 Coefficients for the quadratic polynom in u
 A(etai)*u^2 + B(etai)*u + C == 0
*/

double a[3], b[3], c[3];


for (int i = 0; i < 3; i++) {
  
    a[i] = 2* 
        (-e0*e3*sin(alphaP) 
        + e1*e2*cos(2*eta[i])*sin(alphaP)
        + cos(alphaP)* ((e0*e1+e2*e3)*cos(eta[i])
                        + (e0*e2-e1*e3)*sin(eta(i)))
        -(1/2)*pow(e1,2)*sin(alphaP)*sin(2*eta[i])
        +(1/2)*pow(e2,2)*sin(alphaP)*sin(2*eta[i]));

    b[i] = 2*
        (-pow(e0,2)*sin(alphaP)
        + pow(e3,2)*sin(alphaP) 
        + pow(e1,2)*cos(2*eta[i])*sin(alphaP)
        - pow(e2,2)*cos(2*eta[i])*sin(alphaP)
        + 2*e1*e2*sin(alphaP)*sin(2*eta[i]));

    c[i] = 2*
        (e0*e3*sin(alphaP)
        - e1*e2*cos(2*eta[i])*sin(alphaP)
        + cos(alphaP)* ((e0*e1+e2*e3)*cos(eta[i])
                        +(e0*e2-e1*e3)*sin(eta[i]))
        +(1/2)*e1^2*sin(alphaP)*sin(2*eta[i])
        -(1/2)*e2^2*sin(alphaP)*sin(2*eta[i]));
}






