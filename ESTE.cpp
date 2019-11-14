#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std; 

#define  h  0.01 //esto es mejor para definir constantes
#define k  0.7
#define g 9.8

float X;
float Y;
float VY;
float VX;
float T;



float rk4(float yn, float zn, float tn, float (*F)(float , float, float)){ 
    
    float k1 = h*F(tn, yn, zn);    
    float k2 = h*F(tn+h/2 , yn+k1/2, zn+k1/2);
    float k3 = h*F(tn+h/2, yn+k2/2, zn+k2/2 );
    float k4 = h*F(tn+h/2 , yn+k3, zn+k3);    
    
    float y = yn + 1.0/6.0*(k1 + 2*k2 + 2*k3 + k4);
    
    
    return y;   
    
}


float f_x (float t, float x,float vx){    
    return vx;    
}

float f_vx (float t, float vx, float vy){
    
    float vv = (-k*vx *(vx/(sqrt((vx*vx) + (vy*vy)))));    
    return  vv;   
}

float f_y (float t,float y, float vy){    
    return vy;    
}

float f_vy (float t, float vy, float vx){
    
    float vv = (-g - (k*vy *(vy/(sqrt((vx*vx) + (vy*vy))))));    
    return  vv;   
}

int main(){
    
    float X = 0.0;
    float Y = 0.0;
    float VY = 10.0;
    float VX = 10.0;
    float T = 0.0;
    
    while (T<3.0){
        
        cout << T  << "\t" << X << "\t" << Y << "\t"<< VX  << "\t"<< VY << "\t" <<endl;
        
        
        VY = rk4( VY, VX, T, f_vy);
        VX = rk4( VX, VY, T, f_vx);
    
        X = rk4(X,VX, T, f_x);
        Y = rk4(Y,VY, T, f_y);
        
        
        T+=h;
    }
    
    
    return 0;
}
