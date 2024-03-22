#include<iostream>
#include<cmath>
#include<fstream>

//Funcion para integrar

double f(double x)
{
    return 100*pow(x,2)*cos(20*x);
}

//Calcuilo de la integral aproximada bajo regla trapezoidal
double Trapezoidal(double a, double b, int N){
    double h=(b-a)/N;
    double suma=0.0;
    double w;
    for(int i=0;i<N+1;i++){
        double xi=a+i*h;
        if (i==1 || i==N+1)
        {
           w= (1/2)*h;
        }
        else
        {
            w=h;
        }
        suma+=f(xi)*w;
    }
    return suma;
}
