#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std; 

#define  h  0.01 //esto es mejor para definir constantes



float rk4(float yn, float tn, float (*F)(float , float)){ 
    
    float k1 = h*F(tn, yn);    
    float k2 = h*F(tn+h/2 , yn+k1/2);
    float k3 = h*F(tn+h/2, yn+k2/2 );
    float k4 = h*F(tn+h/2 , yn+k3);    
    
    float y = yn + 1.0/6.0*(k1 + 2*k2 + 2*k3 + k4);
    
    return y;
    
    
}

float funcion (float t, float y ){
    float f = sin(t) - y;
    return f;
}
    
int main(){
    
    float yact = 1.0;  //actual
    float yfut = 1.0;   //futuro
    float tiempo = 0.0;
    
    while (tiempo<20){
        yfut = rk4(yact, tiempo, funcion);
        tiempo += h;
        cout<<tiempo<<"\t"<<yfut<<endl;
        yact = yfut;
       }       
    
       
          
    
    
    return 0;
}
